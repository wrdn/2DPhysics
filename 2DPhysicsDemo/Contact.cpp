#include "Contact.h"

CollisionMaterial Contact::cmat = CollisionMaterial();

Contact::Contact(void)
{
	Reset();
}
Contact::Contact(const float2 *CA, const float2 *CB, const u32 Cnum,
		const float2 &N, const f32 m_t,
		SimBody *a, SimBody *b)
{
	numContacts = min(MAX_CONTACTS, Cnum);
	collidingBodies[0] = a;
	collidingBodies[1] = b;
	contactNormal = N;
	t = m_t;

	for(u32 i=0;i<numContacts;++i)
	{
		contacts[i][0] = CA[i];
		contacts[i][1] = CB[i];
	}
};
Contact::~Contact(void) {};

void Contact::Reset()
{
	collidingBodies[0] = collidingBodies[1] = 0;
	numContacts = 0;
};

void Contact::Solve()
{
	// since we don't support time-to-collision, this will always be true
	if(t<0.0f)
	{
		// resolve overlaps
		for(u32 i=0;i<numContacts;++i)
			ResolveOverlap(contacts[i][0], contacts[i][1]);
	}

	// resolve collisions
	for(u32 i=0;i<numContacts;++i)
		ResolveCollision(contacts[i][0], contacts[i][1]);
};

void Contact::ResolveOverlap(float2 &C0, float2 &C1)
{
	f32 m0 = collidingBodies[0]->invMass;
	f32 m1 = collidingBodies[1]->invMass;
	f32 m = m0 + m1;

	float2 D = (C1 - C0) * cmat.coSep;
	
	if (m0 > 0.0f)
	{
		float2 D0 = D * (m0 / m);
		collidingBodies[0]->position += D0;
	}
	if (m1 > 0.0f) 
	{
		float2 D1 = D * -(m1 / m);
		collidingBodies[1]->position += D1;
	}
};

void Contact::ResolveCollision(float2 &C0, float2 &C1)
{
	SimBody &a = *collidingBodies[0];
	SimBody &b = *collidingBodies[1];

	
	float m0 = a.invMass;
	float m1 = b.invMass;
	float i0 = a.invInertia;
	float i1 = b.invInertia;

	const float2 &P0 = a.position;
	const float2 &P1 = b.position;
	float2 &V0 = a.velocity;
	float2 &V1 = b.velocity;
	float&  w0 = a.angularVelocity;
	float&  w1 = b.angularVelocity;

	//float fCoR = 0.3f;
	//fCoF = 0.2f;

	ResolveCollisions(-contactNormal, t, cmat.coFriction, cmat.coRestitution,
		C1, P1, V1, w1, m1, i1,
		C0, P0, V0, w0, m0, i0);
};

void Contact::ResolveCollisions(const float2& Ncoll, float t, float fCoF, float fCoR,
					  const float2& C0, const float2& P0, float2& V0, float& w0, float m0, float i0, 
					  const float2& C1, const float2& P1, float2& V1, float& w1, float m1, float i1)
{
	// pre-computations
	float tcoll = t > 0.0f ? t : 0.0f;

	float2 Q0 = P0 + V0 * tcoll;
	float2 Q1 = P1 + V1 * tcoll;
	float2 R0 = C0 - Q0;
	float2 R1 = C1 - Q1;
	float2 T0(-R0.y, R0.x);
	float2 T1(-R1.y, R1.x);
	float2 VP0 = V0 - T0 * w0;
	float2 VP1 = V1 - T1 * w1;

	// impact velocity
	float2 Vcoll = VP0 - VP1;
	float  vn	 = Vcoll.dot(Ncoll);
	float2 Vn	 = Ncoll * vn;
	float2 Vt	 = Vcoll - Vn;
	if(vn > 0.0f) { return; }
	float vt = Vt.magnitude();
	Vt = Vt.normalize();

	// compute impulse (friction and restitution)
	float2 J, Jt(0.0f, 0.0f), Jn(0.0f, 0.0f);
	float t0 = (R0 ^ Ncoll) * (R0 ^ Ncoll) * i0;
	float t1 = (R1 ^ Ncoll) * (R1 ^ Ncoll) * i1;
	float m  = m0 + m1;
	float denom = m + t0 + t1;
	float jn = vn / denom;
	Jn = Ncoll * (-(1.0f + fCoR) * jn); // restitution
	Jt = Vt.normalize() * (fCoF * jn); // friction
	J = Jn + Jt;

	// changes in momentum
	float2 dV0 = J * m0;
	float2 dV1 = -J * m1;
	float dw0 =-(R0 ^ J) * i0; 
	float dw1 = (R1 ^ J) * i1;

	if(m0 > 0.0f) { V0 += dV0; w0 += dw0; }; // apply changes in momentum
	if(m1 > 0.0f) { V1 += dV1; w1 += dw1; }; // apply changes in momentum

	// Check for static frcition
	if (vn < 0.0f && fCoF > 0.0f)
	{
		float cone = -vt / vn;
		if (cone < fCoF)
		{
			float2 Nfriction = -Vt.normalize();
			float fCoS = cmat.coStaticFriction;

			ResolveCollisions(Nfriction, 0.0f, 0.0f, fCoS,
							 C0, P0, V0, w0, m0, i0, 
							 C1, P1, V1, w1, m1, i1);
		}
	}
};