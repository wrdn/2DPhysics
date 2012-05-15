#include "chipCollide.h"
using namespace std;

static inline float PolyShapeValueOnAxis(SimBody *poly, const float2 n, const float d)
{
	vector<float2> &verts = poly->transformedVertices;
	float minft = n.dot(verts[0]);

	for(u32 i=1;i<verts.size();++i)
	{
		minft = min(minft, n.dot(verts[i]));
	}

	return minft - d;
};

static inline int FindMinimumSeperatingAxis(SimBody *poly, SplittingPlane *planes, const int num, float *min_out)
{
	int min_index = 0;
	float min = PolyShapeValueOnAxis(poly, planes->N, planes->d);
	if(min > 0.0f) 
	{
		return -1;
	}

	for(int i=1; i<num; i++)
	{
		float dist = PolyShapeValueOnAxis(poly, planes[i].N, planes[i].d);

		if(dist > 0.0f)
		{
			return -1;
		}
		else if(dist > min)
		{
			min = dist;
			min_index = i;
		}
	}

	(*min_out) = min;
	return min_index;
};

static inline float SplittingPlaneCompare(SplittingPlane plane, float2 v)
{
	return plane.N.dot(v) - plane.d;
}

static inline bool PolyShapeContainsVert(SimBody *poly, const float2 v)
{
	vector<SplittingPlane> &planes = poly->transformedSplittingPlanes;

	for(u32 i=0; i<poly->vertices.size(); i++)
	{
		float dist = SplittingPlaneCompare(planes[i], v);
		if(dist > 0.0f) return false;
	}
	
	return true;
}

typedef uintptr_t HashValue;
#define HASH_COEF (3344921057ul)
#define HASH_PAIR(A, B) ((HashValue)(A)*HASH_COEF ^ (HashValue)(B)*HASH_COEF)

Contact InitContactPoint(float2 pos, float2 n, float dist, HashValue hash)
{
	Contact c;
	c.position = pos;
	c.normal = n;
	c.separation = dist;
	
	c.hash = hash;

	c.Pn = c.Pt = 0;
	return c;
};

static inline bool PolyShapeContainsVertPartial(SimBody *poly, const float2 v, const float2 n)
{
	SplittingPlane *planes = &poly->transformedSplittingPlanes[0];
	
	for(unsigned int i=0; i<poly->vertices.size(); i++)
	{
		if(planes[i].N.dot(n) < 0.0f) continue;

		float dist = SplittingPlaneCompare(planes[i], v);

		if(dist > 0.0f) return false;
	}
	
	return true;
};

static int FindVertsFallback(Arbiter &output_arb, SimBody *poly1, SimBody *poly2, const float2 n, const float dist)
{
	int num = 0;
	Arbiter &arb = output_arb;

	for(unsigned int i=0; i<poly1->vertices.size(); i++)
	{
		float2 v = poly1->transformedVertices[i];
		if(PolyShapeContainsVertPartial(poly2, v, n.negate()))
		{
			arb.AddContact(InitContactPoint(v, n, dist, HASH_PAIR(poly1->hashid, i)));
		}
	}

	for(unsigned int i=0; i<poly2->vertices.size(); i++)
	{
		float2 v = poly2->transformedVertices[i];
		if(PolyShapeContainsVertPartial(poly1, v, n))
		{
			arb.AddContact(InitContactPoint(v, n, dist, HASH_PAIR(poly2->hashid, i)));
		}
	}

	num = arb.numContacts;
	
	return num;
}

static inline int FindVerts(Arbiter &output_arb, SimBody *poly1, SimBody *poly2, const float2 n, const float dist)
{
	int num=0;

	Arbiter &arb = output_arb;

	arb.body1 = poly1;
	arb.body2 = poly2;
	arb.friction = sqrt(poly1->friction * poly2->friction);

	for(u32 i=0;i<poly1->vertices.size();++i)
	{
		float2 v = poly1->transformedVertices[i];
		if(PolyShapeContainsVert(poly2, v))
		{
			arb.AddContact(InitContactPoint(v, n, dist, HASH_PAIR(poly1->hashid, i)));
		}
	}

	for(u32 i=0; i<poly2->vertices.size(); i++)
	{
		float2 v = poly2->transformedVertices[i];
		if(PolyShapeContainsVert(poly1, v))
		{
			arb.AddContact(InitContactPoint(v, n, dist, HASH_PAIR(poly2->hashid, i)));
		}
	}

	num = arb.numContacts;
	return (num ? num : FindVertsFallback(arb, poly1, poly2, n, dist));
};

Arbiter Collide::CollidePoly2Poly(SimBody *poly1, SimBody *poly2)
{
	Arbiter arb;

	float min1, min2;
	int mini1 = FindMinimumSeperatingAxis(poly2, &poly1->transformedSplittingPlanes[0], poly1->vertices.size(), &min1);
	if(mini1 == -1) return arb;

	int mini2 = FindMinimumSeperatingAxis(poly1, &poly2->transformedSplittingPlanes[0], poly2->vertices.size(), &min2);
	if(mini2 == -1) return arb;

	if(min1 > min2)
	{
		FindVerts(arb, poly1, poly2, poly1->transformedSplittingPlanes[mini1].N, min1);
		return arb;
	}
	else
	{
		FindVerts(arb, poly1, poly2, poly2->transformedSplittingPlanes[mini2].N.negate(), min2);
		return arb;
	}
};