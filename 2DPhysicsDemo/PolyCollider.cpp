#include "Arbiter.h"
#include "Body.h"
#include <vector>
#include <assert.h>
using namespace std;

typedef f32 float32;
typedef i32 int32;

/*
float32 EdgeSeparation(Body& a, int32 edge1, Body& b)
{
	float2 *vertices1 = &a.vertices[0];
	float2 *normals1 = &a.axes[0];

	int32 count2 = b.vertices.size();
	
	float2* vertices2 = &b.vertices[0];

	assert(0 <= edge1 && edge1 < a.vertices.size());

	b2Rot rotA(a.rotation), rotB(b.rotation);

	float2 normal1World = Mul(rotA, normals1[edge1]);
	float2 normal1 = MulT(rotB, normal1World);

	//Mat22 rotMatA = Mat22::RotationMatrix(a.rotation);
	//Mat22 rotMatB = Mat22::RotationMatrix(b.rotation);

	//float2 normal1World = rotMatA * normals1[edge1];
	//float2 normal1 = rotMatB.Transpose() * normal1World;

	// Find support vertex on poly2 for -normal.
	int32 index = 0;
	float32 minDot = FLT_MAX;

	for (int32 i = 0; i < count2; ++i)
	{
		float32 dot = vertices2[i].dot(normal1);

		if (dot < minDot)
		{
			minDot = dot;
			index = i;
		}
	}

	float2 v1 = a.position + Mul(rotA, vertices1[edge1]);
	float2 v2 = b.position + Mul(rotB, vertices2[index]);
	float32 separation = (v2 - v1).dot(normal1World);
	return separation;
};

float32 FindMaxSeparation(int32* edgeIndex, Body& a, Body &b)
{
	int32 count1 = a.vertices.size();
	float2* normals1 = &a.axes[0];

	b2Rot rotA(a.rotation), rotB(b.rotation);

	// Vector pointing from the centroid of poly1 to the centroid of poly2.
	float2 a_transformed_centroid = a.position + Mul(rotA, a.centroid);
	float2 b_transformed_centroid = b.position + Mul(rotB, b.centroid);
	
	float2 d = b_transformed_centroid - a_transformed_centroid;
	float2 dLocal1 = MulT(rotA, d);

	// Find edge normal on poly1 that has the largest projection onto d.
	int32 edge = 0;
	float32 maxDot = -FLT_MAX;
	for (int32 i = 0; i < count1; ++i)
	{
		float32 dot = normals1[i].dot(dLocal1);
		if (dot > maxDot)
		{
			maxDot = dot;
			edge = i;
		}
	}

	// Get the separation for the edge normal.
	float32 s = EdgeSeparation(a, edge, b);

	// Check the separation for the previous edge normal.
	int32 prevEdge = edge - 1 >= 0 ? edge - 1 : count1 - 1;
	float32 sPrev = EdgeSeparation(a, prevEdge, b);

	// Check the separation for the next edge normal.
	int32 nextEdge = edge + 1 < count1 ? edge + 1 : 0;
	float32 sNext = EdgeSeparation(a, nextEdge, b);

	// Find the best edge and the search direction.
	int32 bestEdge;
	float32 bestSeparation;
	int32 increment;
	if (sPrev > s && sPrev > sNext)
	{
		increment = -1;
		bestEdge = prevEdge;
		bestSeparation = sPrev;
	}
	else if (sNext > s)
	{
		increment = 1;
		bestEdge = nextEdge;
		bestSeparation = sNext;
	}
	else
	{
		*edgeIndex = edge;
		return s;
	}

	// Perform a local search for the best edge normal.
	for ( ; ; )
	{
		if (increment == -1)
			edge = bestEdge - 1 >= 0 ? bestEdge - 1 : count1 - 1;
		else
			edge = bestEdge + 1 < count1 ? bestEdge + 1 : 0;

		s = EdgeSeparation(a, edge, b);

		if (s > bestSeparation)
		{
			bestEdge = edge;
			bestSeparation = s;
		}
		else
		{
			break;
		}
	}

	*edgeIndex = bestEdge;
	return bestSeparation;
};

void FindIncidentEdge(ClipVertex c[2],
							 Body &poly1, int32 edge1,
							 Body& poly2)
{
	float2* normals1 = &poly1.axes[0];

	int32 count2 = poly2.vertices.size();

	float2* vertices2 = &poly2.vertices[0];
	float2* normals2 = &poly2.axes[0];
	
	assert(0 <= edge1 && edge1 < poly1.vertices.size());

	// Get the normal of the reference edge in poly2's frame.
	//float2 n = Mat22::RotationMatrix(poly1.rotation) * normals1[edge1];
	//float2 normal1 = Mat22::RotationMatrix(poly2.rotation).Transpose() * n;

	float2 normal1 = MulT(b2Rot(poly2.rotation),
		Mul(b2Rot(poly1.rotation), normals1[edge1]));

	// Find the incident edge on poly2.
	int32 index = 0;
	float32 minDot = FLT_MAX;
	for (int32 i = 0; i < count2; ++i)
	{
		float32 dot = normal1.dot(normals2[i]);
		if (dot < minDot)
		{
			minDot = dot;
			index = i;
		}
	}

	// Build the clip vertices for the incident edge.
	int32 i1 = index;
	int32 i2 = i1 + 1 < count2 ? i1 + 1 : 0;

	c[0].v = poly2.position + (Mat22::RotationMatrix(poly2.rotation) * vertices2[i1]);

	c[0].id.cf.indexA = (unsigned char)edge1;
	c[0].id.cf.indexB = (unsigned char)i1;
	c[0].id.cf.typeA = ContactFeature::e_face;
	c[0].id.cf.typeB = ContactFeature::e_vertex;

	c[1].v = poly2.position + (Mat22::RotationMatrix(poly2.rotation) * vertices2[i2]);
	c[1].id.cf.indexA = (unsigned char)edge1;
	c[1].id.cf.indexB = (unsigned char)i2;
	c[1].id.cf.typeA = ContactFeature::e_face;
	c[1].id.cf.typeB = ContactFeature::e_vertex;
};

int32 ClipSegmentToLine(ClipVertex vOut[2], const ClipVertex vIn[2],
						const float2& normal, float32 offset, int32 vertexIndexA)
{
	// Start with no output points
	int32 numOut = 0;

	// Calculate the distance of end points to the line
	float32 distance0 = normal.dot(vIn[0].v) - offset;
	float32 distance1 = normal.dot(vIn[1].v) - offset;

	// If the points are behind the plane
	if (distance0 <= 0.0f) vOut[numOut++] = vIn[0];
	if (distance1 <= 0.0f) vOut[numOut++] = vIn[1];

	// If the points are on different sides of the plane
	if (distance0 * distance1 < 0.0f)
	{
		// Find intersection point of edge and plane
		float32 interp = distance0 / (distance0 - distance1);
		vOut[numOut].v = vIn[0].v + interp * (vIn[1].v - vIn[0].v);

		// VertexA is hitting edgeB.
		vOut[numOut].id.cf.indexA = vertexIndexA;
		vOut[numOut].id.cf.indexB = vIn[0].id.cf.indexB;
		vOut[numOut].id.cf.typeA = ContactFeature::e_vertex;
		vOut[numOut].id.cf.typeB = ContactFeature::e_face;
		++numOut;
	}

	return numOut;
};

void CollidePolygons(Manifold &manifold, Body &a, Body &b)
{
	float angleA = a.rotation;
	float angleB = b.rotation;

	manifold.pointCount = 0;
	float32 totalRadius = a.m_radius + b.m_radius;

	int32 edgeA = 0;
	float32 separationA = FindMaxSeparation(&edgeA, a, b);
	if (separationA > totalRadius)
		return;

	int32 edgeB = 0;
	float32 separationB = FindMaxSeparation(&edgeB, b, a);
	if (separationB > totalRadius)
		return;

	Body *poly1, *poly2;
	float2 xf1_pos, xf2_pos;
	b2Rot xf1_rot, xf2_rot;
	int edge1;
	unsigned char flip;
	const float k_relativeTol = 0.98f, k_absoluteTol = 0.001f;

	if (separationB > k_relativeTol * separationA + k_absoluteTol)
	{
		poly1 = &b;
		poly2 = &a;
		xf1_pos = b.position;
		xf1_rot = b2Rot(b.rotation);
		xf2_pos = a.position;
		xf2_rot = b2Rot(a.rotation);

		edge1 = edgeB;

		manifold.type = e_faceB;

		flip = 1;
	}
	else
	{
		poly1 = &a;
		poly2 = &b;
		xf1_pos = a.position;
		xf1_rot.Set(a.rotation);
		xf2_pos = b.position;
		xf2_rot.Set(b.rotation);
		
		edge1 = edgeA;
		manifold.type = e_faceA;
		
		flip = 0;
	}

	ClipVertex incidentEdge[2];
	FindIncidentEdge(incidentEdge, a, edge1, b);
	
	int32 count1 = a.vertices.size();
	const float2* vertices1 = &a.vertices[0];

	int32 iv1 = edge1;
	int32 iv2 = edge1 + 1 < count1 ? edge1 + 1 : 0;

	float2 v11 = vertices1[iv1];
	float2 v12 = vertices1[iv2];

	float2 localTangent = v12 - v11;
	localTangent = localTangent.normalize();
	
	float2 localNormal = cross(localTangent, 1.0f);
	float2 planePoint = 0.5f * (v11 + v12);

	//float2 tangent = Mat22::RotationMatrix(a.rotation) * localTangent;
	float2 tangent = Mul(b2Rot(poly1->rotation), localTangent);
	float2 normal = cross(tangent, 1.0f);

	v11 = a.position + (Mat22::RotationMatrix(a.rotation)*v11);
	v12 = a.position + (Mat22::RotationMatrix(a.rotation)*v12);
	
	float32 frontOffset = normal.dot(v11);

	float32 sideOffset1 = -tangent.dot(v11) + totalRadius;
	float32 sideOffset2 = tangent.dot(v12) + totalRadius;

	// Clip incident edge against extruded edge1 side edges.
	ClipVertex clipPoints1[2];
	ClipVertex clipPoints2[2];
	int np;

	// Clip to box side 1
	np = ClipSegmentToLine(clipPoints1, incidentEdge, -tangent, sideOffset1, iv1);

	if (np < 2)
		return;

	// Clip to negative box side 1
	np = ClipSegmentToLine(clipPoints2, clipPoints1,  tangent, sideOffset2, iv2);

	if (np < 2)
		return;

	// Build the manifold
	manifold.localNormal = localNormal;
	manifold.localPoint = planePoint;
	int32 pointCount = 0;
	for (int32 i = 0; i < 2; ++i)
	{
		float32 separation = normal.dot(clipPoints2[i].v) - frontOffset;

		if (separation <= totalRadius)
		{
			ManifoldPoint* cp = manifold.points + pointCount;
			
			//cp->localPoint = xf2_pos + (xf2_rot.Transpose() * clipPoints2[i].v);
			cp->localPoint = MulT(xf2_pos, xf2_rot, clipPoints2[i].v);

			cp->id = clipPoints2[i].id;

			if (flip)
			{
				// Swap features
				ContactFeature cf = cp->id.cf;
				cp->id.cf.indexA = cf.indexB;
				cp->id.cf.indexB = cf.indexA;
				cp->id.cf.typeA = cf.typeB;
				cp->id.cf.typeB = cf.typeA;
			}
			++pointCount;
		}
	}
	manifold.pointCount = pointCount;
};

void test_collide_polygons()
{
	Body a;
	a.vertices.push_back(float2(-0.5, -0.5));
	a.vertices.push_back(float2(0.5 , -0.5));
	a.vertices.push_back(float2(0.5, 0.5));
	a.vertices.push_back(float2(-0.5, 0.5));
	a.m_radius = 0.0099999998;

	a.axes.push_back(float2(0,-1));
	a.axes.push_back(float2(1,0));
	a.axes.push_back(float2(0,1));
	a.axes.push_back(float2(-1,0));

	a.rotation = 2.4723271e-005;
	a.position.set(10, 0.51493084);

	Body b = a;
	b.rotation = 0;
	b.position.set(10, 1.5253330);

	Manifold out;
	CollidePolygons(out, a, b);
};
*/