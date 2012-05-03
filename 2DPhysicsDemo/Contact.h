#pragma once

#include "SimBody.h"

struct CollisionMaterial
{
public:

	// Friction, Restitution, Static Friction and Seperation
	// Coefficient of Restitution is the elasticity of collisions
	// Keep all in range 0 to 1
	f32 coFriction, coRestitution, coStaticFriction, coSep;

	CollisionMaterial(f32 fCoF = 0.4f, f32 fCoR = 0.3f,
		f32 fCoS = 0.4f, f32 fSep=0.5f)
		: coFriction(fCoF), coRestitution(fCoR),
		coStaticFriction(fCoS), coSep(fSep) {};
};

class Contact
{
public:
	enum { MAX_CONTACTS = 2 };

	static CollisionMaterial cmat;

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
	void ResolveOverlap(float2 &C0, float2 &C1);
	void ResolveCollision(float2 &C0, float2 &C1);

	void ResolveCollisions(const float2& Ncoll, float t, float fCoF, float fCoR,
					  const float2& C0, const float2& P0, float2& V0, float& w0, float m0, float i0, 
					  const float2& C1, const float2& P1, float2& V1, float& w1, float m1, float i1);

};

