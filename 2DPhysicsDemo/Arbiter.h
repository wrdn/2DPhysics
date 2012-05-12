#pragma once

#include "MathUtils.h"
#include "float2.h"
#include "SimBody.h"

struct Body;


void test_collide_polygons();
bool SATCollide(SimBody *body1, SimBody *body2, float2 &N, f32 &t);


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

	float2 position;
	float2 normal;
	float2 r1, r2;
	float separation;
	float Pn;	// accumulated normal impulse
	float Pt;	// accumulated tangent impulse
	float Pnb;	// accumulated normal impulse for position bias
	float massNormal, massTangent;
	float bias;
	FeaturePair feature;
	uintptr_t hash;
};

int Collide(Contact* contacts, SimBody* body1, SimBody* body2);

struct ArbiterKey
{
	ArbiterKey(SimBody* b1, SimBody* b2)
	{
		body1 = b1;
		body2 = b2;
	}

	SimBody* body1;
	SimBody* body2;
};
struct Arbiter
{
	enum {MAX_POINTS = 2};

	Arbiter()
	{
		numContacts=0;
	};
	Arbiter(SimBody* b1, SimBody* b2);

	int DoCollision();

	void AddContact(const Contact &c)
	{
		if(numContacts < MAX_POINTS)
		{
			contacts[numContacts++] = c;
		}
		else
		{
			contacts[MAX_POINTS-1] = c;
		}
	};

	void Update(Contact* contacts, int numContacts);

	void PreStep(float inv_dt);
	void ApplyImpulse();

	Contact contacts[MAX_POINTS];
	int numContacts;

	SimBody* body1;
	SimBody* body2;

	// Combined friction
	float friction;
};











struct b2Rot
{
public:
	b2Rot() {}

	/// Initialize from an angle in radians
	explicit b2Rot(float angle)
	{
		/// TODO_ERIN optimize
		s = sinf(angle);
		c = cosf(angle);
	}

	/// Set using an angle in radians.
	void Set(float angle)
	{
		/// TODO_ERIN optimize
		s = sinf(angle);
		c = cosf(angle);
	}

	/// Set to the identity rotation
	void SetIdentity()
	{
		s = 0.0f;
		c = 1.0f;
	}

	/// Get the angle in radians
	float GetAngle() const
	{
		return atan2(s, c);
	}

	/// Get the x-axis
	float2 GetXAxis() const
	{
		return float2(c, s);
	}

	/// Get the u-axis
	float2 GetYAxis() const
	{
		return float2(-s, c);
	}

	/// Sine and cosine
	float s, c;
};
inline float2 Mul(const b2Rot& q, const float2& v)
{
	return float2(q.c * v.x - q.s * v.y, q.s * v.x + q.c * v.y);
}
inline float2 MulT(const b2Rot& q, const float2& v)
{
	return float2(q.c * v.x + q.s * v.y, -q.s * v.x + q.c * v.y);
}
inline float2 MulT(const float2 &p, const b2Rot &q, const float2 &v)
{
	float px = v.x - p.x;
	float py = v.y - p.y;
	float x = (q.c * px + q.s * py);
	float y = (-q.s * px + q.c * py);

	return float2(x,y);
};


struct ContactFeature
{
	enum Type
	{
		e_vertex = 0,
		e_face = 1
	};

	unsigned char indexA;		///< Feature index on shapeA
	unsigned char indexB;		///< Feature index on shapeB
	unsigned char typeA;		///< The feature type on shapeA
	unsigned char typeB;		///< The feature type on shapeB
};

union b2ContactID
{
	ContactFeature cf;
	unsigned int key;					///< Used to quickly compare contact ids.
};
struct ClipVertex
{
	float2 v;
	b2ContactID id;
};
struct ManifoldPoint
{
	float2 localPoint;		///< usage depends on manifold type
	float normalImpulse;	///< the non-penetration impulse
	float tangentImpulse;	///< the friction impulse
	b2ContactID id;			///< uniquely identifies a contact point between two shapes
};
enum ManifoldType { e_faceA, e_faceB };
struct Manifold
{
public:
	int pointCount;
	ManifoldType type;
	float2 localNormal, localPoint;
	ManifoldPoint points[2];
};
void CollidePolygons(Manifold &manifold, Body &a, Body &b);

struct b2WorldManifold
{
	/// Evaluate the manifold with supplied transforms. This assumes
	/// modest motion from the original state. This does not change the
	/// point count, impulses, etc. The radii must come from the shapes
	/// that generated the manifold.
	void Initialize(const Manifold* manifold,
		const float2& xfa_pos, const b2Rot &xfa_rot, float radiusA,
					const float2& xfb_pos, const b2Rot &xfb_rot, float radiusB)
	{
		if(!manifold->pointCount) return;

		switch(manifold->type)
		{
		case e_faceA:
			{
				normal = Mul(xfa_rot, manifold->localNormal);
				float2 planePoint = xfa_pos + Mul(xfa_rot, manifold->localPoint);

				for (int i = 0; i < manifold->pointCount; ++i)
				{
					float2 clipPoint = xfb_pos + Mul(xfb_rot, manifold->points[i].localPoint);
					//float2 cA = clipPoint + (radiusA - b2Dot(clipPoint - planePoint, normal)) * normal;
					float2 cA = clipPoint + (radiusA - (clipPoint-planePoint).dot(normal)) * normal;
					float2 cB = clipPoint - radiusB * normal;
					points[i] = 0.5f * (cA + cB);
				}

			} break;

		case e_faceB:
			{
				normal = Mul(xfb_rot, manifold->localNormal);
				float2 planePoint = xfb_pos + Mul(xfb_rot, manifold->localPoint);

				for (int i = 0; i < manifold->pointCount; ++i)
				{
					float2 clipPoint = xfa_pos + Mul(xfa_rot, manifold->points[i].localPoint);
					//float2 cA = clipPoint + (radiusA - b2Dot(clipPoint - planePoint, normal)) * normal;
					float2 cA = clipPoint + (radiusB - (clipPoint-planePoint).dot(normal)) * normal;
					float2 cB = clipPoint - radiusA * normal;
					points[i] = 0.5f * (cA + cB);
				}

				normal = -normal;

			} break;
		}
	};

	float2 normal;							///< world vector pointing from A to B
	float2 points[2];	///< world contact point (point of intersection)
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

