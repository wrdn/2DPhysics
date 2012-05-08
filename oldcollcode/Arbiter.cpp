#include "Arbiter.h"
#include "BoxCollider.h"

PhysArbiter::PhysArbiter(Body *b1, Body *b2)
{
	/*if (b1 < b2)
	{
		body1 = b1;
		body2 = b2;
	}
	else
	{
		body1 = b2;
		body2 = b1;
	}*/
	body1=b1;
	body2=b2;

	numContacts = BoxCollide(contacts, body1, body2);

	friction = sqrtf(body1->friction * body2->friction);
};

void PhysArbiter::Update(PhysContact *newContacts, int numNewContacts)
{
	PhysContact mergedContacts[2];

	for (int i = 0; i < numNewContacts; ++i)
	{
		PhysContact* cNew = newContacts + i;
		int k = -1;
		for (int j = 0; j < numContacts; ++j)
		{
			PhysContact* cOld = contacts + j;
			if (cNew->feature.value == cOld->feature.value)
			{
				k = j;
				break;
			}
		}

		if (k > -1)
		{
			PhysContact* c = mergedContacts + i;
			PhysContact* cOld = contacts + k;
			*c = *cNew;

			c->accNormalImpulse = cOld->accNormalImpulse;
			c->accTangentImpulse = cOld->accTangentImpulse;
		}
		else
		{
			mergedContacts[i] = newContacts[i];
		}
	}

	for (int i = 0; i < numNewContacts; ++i)
		contacts[i] = mergedContacts[i];

	numContacts = numNewContacts;
};

void PhysArbiter::PreStep(float inv_dt)
{
	const float allowedPenetration = 0.01f;
	float biasFactor = 0.2;

	for(int i=0;i<numContacts;++i)
	{
		PhysContact *c = &contacts[i];

		float2 r1 = c->pos - body1->pos;
		float2 r2 = c->pos - body2->pos;
		
		float rn1 = r1.dot(c->normal);
		float rn2 = r2.dot(c->normal);
		float kNormal = body1->invMass + body2->invMass;
		kNormal += body1->invInertia * (r1.dot(r1) - (rn1*rn1)) +
			body2->invInertia * (r2.dot(r2) - (rn2*rn2));
		c->massNormal = 1.0f / kNormal;

		float2 tangent = vcross(c->normal, 1.0f);
		float rt1 = r1.dot(tangent);
		float rt2 = r2.dot(tangent);
		float kTangent = body1->invMass + body2->invMass;
		kTangent += body1->invInertia * (r1.dot(r1) - rt1 * rt1) +
			body2->invInertia * (r2.dot(r2) - rt2 * rt2);
		c->massTangent = 1.0f/kTangent;

		//c->bias = -biasFactor * invDt * min(0.0f, c->seperation + allowedPenetration);

		/*float2 relativeVelocity = body2->velocity + (vcross(r2, body2->angularVelocity));
		relativeVelocity -= body1->velocity - (vcross(r1, body1->angularVelocity));
		float combinedRestitution = body1->restitution * body2->restitution;
		float relVel = c->normal.dot(relativeVelocity);
		c->restitution = max(combinedRestitution * -relVel, 0.0f);

		float penVel = -c->seperation / dt;
		c->bias = c->restitution>=penVel ? 0 : -biasFactor * invDt * min(0.0f, c->seperation + allowedPenetration);*/

		c->bias = -biasFactor * inv_dt * min(0.0f, c->seperation+allowedPenetration);

		// Accumulate impulses
		/*float2 P = (c->normal*c->accNormalImpulse) +
			(tangent*c->accTangentImpulse);

		body1->velocity -= P.mul(body1->invMass);
		body1->angularVelocity -= body1->invInertia * vcross(r1, P);

		body2->velocity += P.mul(body2->invMass);
		body2->angularVelocity += body2->invInertia * vcross(r2, P);*/
		// End impulse accumulation

		c->biasImpulse = 0;
	}
};

void PhysArbiter::ApplyImpulse()
{
	Body* b1 = body1;
	Body* b2 = body2;

	for(int i=0;i<numContacts;++i)
	{
		PhysContact *c = &contacts[i];
		float2 r1 = c->pos - b1->pos;
		float2 r2 = c->pos - b2->pos;
		
		float2 dv = b2->velocity +
			vcross(b2->angularVelocity, r2) -
			b1->velocity - vcross(b1->angularVelocity, r1);
		float vn = dv.dot(c->normal);

		float dPn = c->massNormal * (-vn + c->bias);

		/*float Pn0 = c->accNormalImpulse;
		c->accNormalImpulse = max(Pn0 + dPn, 0.0f);
		dPn = c->accNormalImpulse - Pn0;*/
		dPn = max(dPn,0);

		float2 Pn = c->normal*dPn;

		b1->velocity -= Pn*b1->invMass;
		b1->angularVelocity -= b1->invInertia * vcross(r1, Pn);

		b2->velocity += Pn * b2->invMass;
		b2->angularVelocity += b2->invInertia * vcross(r2, Pn);
	}

	/*for (int i = 0; i < numContacts; ++i)
	{
		PhysContact* c = contacts + i;

		float2 r1 = c->pos - b1->pos;
		float2 r2 = c->pos - b2->pos;

		// relative velocity at contact
		float2 relativeVelocity = b2->velocity + vcross(b2->angularVelocity, r2) -
			b1->velocity - vcross(b1->angularVelocity, r1);

		// normal impulse
		float vn = relativeVelocity.dot(c->normal);
		float normalImpulse = c->massNormal * (-vn + c->bias);
		//float normalImpulse = c->massNormal * (c->restitution - vn);

		// clamp accumulated impulse
		float oldNormalImpulse = c->accNormalImpulse;
		c->accNormalImpulse = max(oldNormalImpulse + normalImpulse, 0.0f);
		normalImpulse = c->accNormalImpulse - oldNormalImpulse;

		// apply contact impulse
		float2 impulse = c->normal*normalImpulse;
		b1->velocity -= impulse*b1->invMass;
		b1->angularVelocity -= b1->invInertia * vcross(r1, impulse);
		b2->velocity += impulse*b2->invMass;
		b2->angularVelocity += b2->invInertia * vcross(r2, impulse);

		//relativeVelocity.set(b2.getBiasedVelocity());
		//relativeVelocity.add(MathUtil.cross(b2.getBiasedAngularVelocity(), r2));
		//relativeVelocity.sub(b1.getBiasedVelocity());
		//relativeVelocity.sub(MathUtil.cross(b1.getBiasedAngularVelocity(), r1));
		//float vnb = relativeVelocity.dot(c.normal);

		//float biasImpulse = c.massNormal * (-vnb + c.bias);
		//float oldBiasImpulse = c.biasImpulse;
		//c.biasImpulse = Math.max(oldBiasImpulse + biasImpulse, 0.0f);
		//biasImpulse = c.biasImpulse - oldBiasImpulse;

		//Vector2f Pb = MathUtil.scale(c.normal, biasImpulse);
		//
		//b1.adjustBiasedVelocity(MathUtil.scale(Pb, -b1.getInvMass()));
		//b1.adjustBiasedAngularVelocity(-(b1.getInvI() * MathUtil.cross(r1, Pb)));

		//b2.adjustBiasedVelocity(MathUtil.scale(Pb, b2.getInvMass()));
		//b2.adjustBiasedAngularVelocity((b2.getInvI() * MathUtil.cross(r2, Pb)));

		float maxTangentImpulse = friction * c->accNormalImpulse;

		relativeVelocity = b2->velocity + vcross(b2->angularVelocity,r2)
			- b1->velocity - vcross(b1->angularVelocity, r1);

		float2 tangent = vcross(c->normal, 1.0f);
		float vt = relativeVelocity.dot(tangent);
		float tangentImpulse = c->massTangent * (-vt);

		float oldTangentImpulse = c->accTangentImpulse;
		c->accTangentImpulse = clamp(oldTangentImpulse+tangentImpulse,
			-maxTangentImpulse, maxTangentImpulse);
		tangentImpulse = c->accTangentImpulse - oldTangentImpulse;

		impulse = tangent*tangentImpulse;

		b1->velocity -= impulse*b1->invMass;
		b1->angularVelocity -= b1->invInertia * vcross(r1,impulse);
		b2->velocity += impulse*b2->invMass;
		b2->angularVelocity += b2->invInertia * vcross(r2, impulse);
	}*/
};