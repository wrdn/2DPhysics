#pragma once

#include "SimBody.h"

class Contact
{
public:
	enum { MAX_CONTACTS = 2 };

	SimBody *collidingBodies[2]; // pointer to each colliding body (2 bodies)
	float2 contacts[MAX_CONTACTS][2]; // contact pairs
	float2 contactNormal;
	f32 t; // depth (or time to hit)
	u32 numContacts; // <= MAX_CONTACTS

	Contact();
	Contact(const float2 *CA, const float2 *CB, const u32 Cnum,
		const float2 &N, const f32 m_t,
		SimBody *a, SimBody *b);
	~Contact();

	void Reset();

	void Solve();

	// Both assume we have 2 objects
	void ResolveOverlap(const float2 &C0, const float2 &C1);
	void ResolveCollision(const float2 &C0, const float2 &C1);
};

