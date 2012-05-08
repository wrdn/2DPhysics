#pragma once

#include "MathUtils.h"

struct Body;

union FeaturePair
{
	struct Edges
	{
		char inEdge1;
		char outEdge1;
		char inEdge2;
		char outEdge2;
	} e;
	int value;
};

struct Contact
{
	Contact();

	Vector2f position;
	Vector2f normal;
	Vector2f r1, r2;
	float separation;
	float Pn;	// accumulated normal impulse
	float Pt;	// accumulated tangent impulse
	float Pnb;	// accumulated normal impulse for position bias
	float massNormal, massTangent;
	float bias;
	FeaturePair feature;
};

struct ArbiterKey
{
	ArbiterKey(Body* b1, Body* b2)
	{
		body1 = b1;
		body2 = b2;
		/*if (b1 < b2)
		{
			body1 = b1; body2 = b2;
		}
		else
		{
			body1 = b2; body2 = b1;
		}*/
	}

	Body* body1;
	Body* body2;
};

struct Arbiter
{
	enum {MAX_POINTS = 2};

	Arbiter(Body* b1, Body* b2);

	void Update(Contact* contacts, int numContacts);

	void PreStep(float inv_dt);
	void ApplyImpulse();

	Contact contacts[MAX_POINTS];
	int numContacts;

	Body* body1;
	Body* body2;

	// Combined friction
	float friction;
};

// This is used by std::set
inline bool operator < (const ArbiterKey& a1, const ArbiterKey& a2)
{
	if (a1.body1 < a2.body1)
		return true;

	if (a1.body1 == a2.body1 && a1.body2 < a2.body2)
		return true;

	return false;
}

int Collide(Contact* contacts, Body* body1, Body* body2);