#include "Contact.h"

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
	//for(u32 i=0;i<numContacts;++i)
	//	ResolveCollision(contacts[i][0], contacts[i][1]);
};

void Contact::ResolveOverlap(const float2 &C0, const float2 &C1)
{
	f32 m0 = collidingBodies[0]->invMass;
	f32 m1 = collidingBodies[1]->invMass;
	f32 m = m0 + m1;

	float2 D = C1 - C0;
	D = D*0.5f;
	
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

void Contact::ResolveCollision(const float2 &C0, const float2 &C1)
{
};