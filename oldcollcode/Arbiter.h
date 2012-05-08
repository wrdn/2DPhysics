#pragma once

#include "float2.h"
#include "util.h"
#include "Body.h"

struct InOutEdge
{
public:
	char inEdge, outEdge;
	InOutEdge() : inEdge(0),outEdge(0){};
	InOutEdge(char _inEdge, char _outEdge) : inEdge(_inEdge), outEdge(_outEdge) {};
};

class FeaturePair
{
public:
	union
	{
		struct { InOutEdge edge1, edge2; };
		int value;
	};

	FeaturePair() : edge1(), edge2() {};
	FeaturePair(InOutEdge _edge1, InOutEdge _edge2) : edge1(_edge1), edge2(_edge2) {};
	FeaturePair(int index) { edge1.inEdge = index; };

	int GetKey() const
	{
		return edge1.inEdge + (edge1.outEdge << 8) + (edge2.inEdge << 16)
			+ (edge2.outEdge << 24);
	};
	int HashCode() const { return GetKey(); };

	bool Equals(const FeaturePair &other) const
	{
		return other.HashCode() == this->HashCode();
	};

	void Set(const FeaturePair &fp)
	{
		edge1 = fp.edge1; edge2 = fp.edge2;
	};
};

class PhysContact
{
public:
	float2 pos, normal;
	FeaturePair feature;
	float seperation, accNormalImpulse, accTangentImpulse,
		massNormal, massTangent, bias, restitution, biasImpulse;

	PhysContact() : pos(), normal(), feature(), seperation(0),
		accNormalImpulse(0), accTangentImpulse(0), massNormal(0), massTangent(0),
		bias(0), restitution(0), biasImpulse(0)
	{
	};

	void Set(const PhysContact &contact)
	{
		pos = contact.pos;
		normal = contact.normal;
		feature = contact.feature;
		seperation = contact.seperation;
		accNormalImpulse = contact.accNormalImpulse;
		accTangentImpulse = contact.accTangentImpulse;
		massNormal = contact.massNormal;
		massTangent = contact.massTangent;
		bias = contact.bias;
		restitution = contact.restitution;
		biasImpulse = contact.biasImpulse;
	};

	int HashCode() const { return feature.HashCode(); };
};

struct PhysArbiterKey
{
	PhysArbiterKey(Body* b1, Body* b2)
	{
		body1 = b1; body2 = b2;
		return;

		if (b1 < b2)
		{
			body1 = b1; body2 = b2;
		}
		else
		{
			body1 = b2; body2 = b1;
		}
	}

	Body* body1;
	Body* body2;
};
inline bool operator < (const PhysArbiterKey& a1, const PhysArbiterKey& a2)
{
	if (a1.body1 < a2.body1)
		return true;

	if (a1.body1 == a2.body1 && a1.body2 < a2.body2)
		return true;

	return false;
}

const int MAX_CONTACTS = 2;
class PhysArbiter
{
public:
	PhysContact contacts[MAX_CONTACTS]; int numContacts;
	Body *body1, *body2;
	float friction;

	PhysArbiter() : body1(0), body2(0) {};
	PhysArbiter(Body *a, Body *b);

	void Update(PhysContact *newContacts, int numNewContacts);
	void PreStep(float dt);
	void ApplyImpulse();
};