#include "Arbiter.h"
#include "Body.h"
#include "World.h"

bool WARM_STARTING = true;
bool POSITION_CORRECTION = true;
bool ACCUMULATE_IMPULSES = true;

Contact::Contact() : Pn(0.0f), Pt(0.0f), Pnb(0.0f) {};

Arbiter::Arbiter(SimBody* b1, SimBody* b2)
{
	body1 = b1;
	body2 = b2;

	//numContacts = Collide(contacts, body1, body2);

	friction = sqrtf(body1->friction * body2->friction);

	//glPointSize(4.0f);
	//glColor3f(1.0f, 0.0f, 0.0f);
	//glBegin(GL_POINTS);
	//for (int i = 0; i < numContacts; ++i)
	//{
	//	glVertex2f(contacts[i].position.x, contacts[i].position.y);
	//}
	//glEnd();
	//glPointSize(1.0f);
}

void Arbiter::Update(Contact* newContacts, int numNewContacts)
{
	Contact mergedContacts[2];

	for (int i = 0; i < numNewContacts; ++i)
	{
		Contact* cNew = newContacts + i;
		int k = -1;
		for (int j = 0; j < numContacts; ++j)
		{
			Contact* cOld = contacts + j;
			if (cNew->feature.value == cOld->feature.value)
			{
				k = j;
				break;
			}
		}

		if (k > -1)
		{
			Contact* c = mergedContacts + i;
			Contact* cOld = contacts + k;
			*c = *cNew;
			if (WARM_STARTING)
			{
				c->Pn = cOld->Pn;
				c->Pt = cOld->Pt;
				c->Pnb = cOld->Pnb;
			}
			else
			{
				c->Pn = 0.0f;
				c->Pt = 0.0f;
				c->Pnb = 0.0f;
			}
		}
		else
		{
			mergedContacts[i] = newContacts[i];
		}
	}

	for (int i = 0; i < numNewContacts; ++i)
		contacts[i] = mergedContacts[i];

	numContacts = numNewContacts;
}

void Arbiter::PreStep(float inv_dt)
{
	const float k_allowedPenetration = 0.1f;
	float k_biasFactor = POSITION_CORRECTION ? 0.2f : 0.0f;

	for (int i = 0; i < numContacts; ++i)
	{
		Contact* c = contacts + i;

		float2 r1 = c->position - body1->position;
		float2 r2 = c->position - body2->position;

		// Precompute normal mass, tangent mass, and bias.
		float rn1 =r1.dot(c->normal);
		float rn2 =r2.dot(c->normal);
		float kNormal = body1->invMass + body2->invMass;
		kNormal += body1->invI * (r1.dot(r1) - rn1 * rn1) + body2->invI * (r2.dot(r2) - rn2 * rn2);
		c->massNormal = 1.0f / kNormal;
		
		float2 tangent = cross(c->normal, 1.0f);
		float rt1 = r1.dot(tangent);
		float rt2 = r2.dot(tangent);
		float kTangent = body1->invMass + body2->invMass;
		kTangent += body1->invI * (r1.dot(r1) - rt1 * rt1) + body2->invI * (r2.dot(r2) - rt2 * rt2);
		c->massTangent = 1.0f /  kTangent;

		c->bias = -k_biasFactor * inv_dt * Min(0.0f, c->separation + k_allowedPenetration);

		if (ACCUMULATE_IMPULSES)
		{
			// Apply normal + friction impulse
			float2 P = c->Pn * c->normal + c->Pt * tangent;

			body1->velocity -= body1->invMass * P;
			body1->angularVelocity -= body1->invI * cross(r1, P);

			body2->velocity += body2->invMass * P;
			body2->angularVelocity += body2->invI * cross(r2, P);
		}
	}
}

void Arbiter::ApplyImpulse()
{
	SimBody* b1 = body1;
	SimBody* b2 = body2;

	for (int i = 0; i < numContacts; ++i)
	{
		Contact* c = contacts + i;
		c->r1 = c->position - b1->position;
		c->r2 = c->position - b2->position;

		// Relative velocity at contact
		float2 dv = b2->velocity + cross(b2->angularVelocity, c->r2) - b1->velocity - cross(b1->angularVelocity, c->r1);

		// Compute normal impulse
		float vn = dv.dot(c->normal);

		float dPn = c->massNormal * (-vn + c->bias);

		if (ACCUMULATE_IMPULSES)
		{
			// Clamp the accumulated impulse
			float Pn0 = c->Pn;
			c->Pn = Max(Pn0 + dPn, 0.0f);
			dPn = c->Pn - Pn0;
		}
		else
		{
			dPn = Max(dPn, 0.0f);
		}

		// Apply contact impulse
		float2 Pn = dPn * c->normal;

		//b1->updateCriticalSection.Lock();
		b1->velocity -= b1->invMass * Pn;
		b1->angularVelocity -= b1->invI * cross(c->r1, Pn);
		//b1->updateCriticalSection.Unlock();
		
		//b2->updateCriticalSection.Lock();
		b2->velocity += b2->invMass * Pn;
		b2->angularVelocity += b2->invI * cross(c->r2, Pn);
		//b2->updateCriticalSection.Unlock();

		// Relative velocity at contact
		dv = b2->velocity + cross(b2->angularVelocity, c->r2) -
			b1->velocity - cross(b1->angularVelocity, c->r1);

		float2 tangent = cross(c->normal, 1.0f);
		float vt = dv.dot(tangent);
		float dPt = c->massTangent * (-vt);

		if (ACCUMULATE_IMPULSES)
		{
			// Compute friction impulse
			float maxPt = friction * c->Pn;

			// Clamp friction
			float oldTangentImpulse = c->Pt;
			c->Pt = Clamp(oldTangentImpulse + dPt, -maxPt, maxPt);
			dPt = c->Pt - oldTangentImpulse;
		}
		else
		{
			float maxPt = friction * dPn;
			dPt = Clamp(dPt, -maxPt, maxPt);
		}

		// Apply contact impulse
		float2 Pt = dPt * tangent;

		//b1->updateCriticalSection.Lock();
		b1->velocity -= b1->invMass * Pt;
		b1->angularVelocity -= b1->invI * cross(c->r1, Pt);
		//b1->updateCriticalSection.Unlock();

		//b2->updateCriticalSection.Lock();
		b2->velocity += b2->invMass * Pt;
		b2->angularVelocity += b2->invI * cross(c->r2, Pt);
		//b2->updateCriticalSection.Unlock();
	}
}