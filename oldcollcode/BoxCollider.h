#pragma once

#include "Arbiter.h"
#include "Mat22.h"

typedef Body Box;

enum Axis
{
	FACE_A_X,
	FACE_A_Y,
	FACE_B_X,
	FACE_B_Y
};
enum EdgeNumbers
{
	NO_EDGE = 0,
	EDGE1,
	EDGE2,
	EDGE3,
	EDGE4
};
struct ClipVertex
{
public:
	ClipVertex() { fp.value = 0; }
	float2 v;
	FeaturePair fp;
};

template<typename T> inline void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
};
inline float Sign(float x)
{
	return x < 0.0f ? -1.0f : 1.0f;
}

static void Flip(FeaturePair& fp)
{
	Swap(fp.edge1.inEdge, fp.edge2.inEdge);
	Swap(fp.edge1.outEdge, fp.edge2.outEdge);
}

static int ClipSegmentToLine(ClipVertex vOut[2], ClipVertex vIn[2],
					  const float2& normal, float offset, char clipEdge)
{
	// Start with no output points
	int numOut = 0;

	// Calculate the distance of end points to the line
	float distance0 = normal.dot(vIn[0].v) - offset;
	float distance1 = normal.dot(vIn[1].v) - offset;

	// If the points are behind the plane
	if (distance0 <= 0.0f) vOut[numOut++] = vIn[0];
	if (distance1 <= 0.0f) vOut[numOut++] = vIn[1];

	// If the points are on different sides of the plane
	if (distance0 * distance1 < 0.0f)
	{
		// Find intersection point of edge and plane
		float interp = distance0 / (distance0 - distance1);
		vOut[numOut].v = vIn[0].v + ( (vIn[1].v - vIn[0].v) * interp);
		if (distance0 > 0.0f)
		{
			vOut[numOut].fp = vIn[0].fp;
			vOut[numOut].fp.edge1.inEdge = clipEdge;
			vOut[numOut].fp.edge2.inEdge = NO_EDGE;
		}
		else
		{
			vOut[numOut].fp = vIn[1].fp;
			vOut[numOut].fp.edge1.outEdge = clipEdge;
			vOut[numOut].fp.edge2.outEdge = NO_EDGE;
		}
		++numOut;
	}

	return numOut;
}

static void ComputeIncidentEdge(ClipVertex c[2], const float2& h, const float2& pos,
								const Mat22& Rot, const float2& normal)
{
	// The normal is from the reference box. Convert it
	// to the incident boxe's frame and flip sign.
	Mat22 RotT = Rot.Transpose();
	float2 n = -(RotT.Mul(normal));
	float2 nAbs = n.absolute();

	if (nAbs.x > nAbs.y)
	{
		if (Sign(n.x) > 0.0f)
		{
			c[0].v.set(h.x, -h.y);
			c[0].fp.edge2.inEdge = EDGE3;
			c[0].fp.edge2.outEdge = EDGE4;

			c[1].v.set(h.x, h.y);
			c[1].fp.edge2.inEdge = EDGE4;
			c[1].fp.edge2.outEdge = EDGE1;
		}
		else
		{
			c[0].v.set(-h.x, h.y);
			c[0].fp.edge2.inEdge = EDGE1;
			c[0].fp.edge2.outEdge = EDGE2;

			c[1].v.set(-h.x, -h.y);
			c[1].fp.edge2.inEdge = EDGE2;
			c[1].fp.edge2.outEdge = EDGE3;
		}
	}
	else
	{
		if (Sign(n.y) > 0.0f)
		{
			c[0].v.set(h.x, h.y);
			c[0].fp.edge2.inEdge = EDGE4;
			c[0].fp.edge2.outEdge = EDGE1;

			c[1].v.set(-h.x, h.y);
			c[1].fp.edge2.inEdge = EDGE1;
			c[1].fp.edge2.outEdge = EDGE2;
		}
		else
		{
			c[0].v.set(-h.x, -h.y);
			c[0].fp.edge2.inEdge = EDGE2;
			c[0].fp.edge2.outEdge = EDGE3;

			c[1].v.set(h.x, -h.y);
			c[1].fp.edge2.inEdge = EDGE3;
			c[1].fp.edge2.outEdge = EDGE4;
		}
	}

	c[0].v = pos + Rot * c[0].v;
	c[1].v = pos + Rot * c[1].v;
}

static int BoxCollide(PhysContact *contacts, Box *bodyA, Box *bodyB)
{
	float2 hA = bodyA->dimensions*0.5f;
	float2 hB = bodyB->dimensions*0.5f;
	
	float2 posA = bodyA->pos, posB = bodyB->pos;

	Mat22 rotA = Mat22::RotationMatrix(bodyA->rotation);
	Mat22 rotB = Mat22::RotationMatrix(bodyB->rotation);
	Mat22 rotAT = rotA.Transpose();
	Mat22 rotBT = rotB.Transpose();

	float2 dp = posB - posA;
	float2 dA = rotAT * dp;
	float2 dB = rotBT * dp;

	Mat22 C = rotAT * rotB;
	Mat22 absC = C.Abs();
	Mat22 absCT = absC.Transpose();

	float2 faceA = dA.absolute() - hA - absC * hB;
	if(faceA.x > 0.0f || faceA.y > 0.0f) return 0;

	float2 faceB = dB.absolute() - absCT * hA - hB;
	if (faceB.x > 0.0f || faceB.y > 0.0f) return 0;

	Axis axis;
	float separation;
	float2 normal;

	float2 a1(rotA.mat[0], rotA.mat[2]);
	float2 a2(rotA.mat[1], rotA.mat[3]);
	float2 b1(rotB.mat[0], rotB.mat[2]);
	float2 b2(rotB.mat[1], rotB.mat[3]);

	axis = FACE_A_X;
	separation = faceA.x;
	normal = dA.x > 0.0f ? a1 : -a1;

	const float relativeTol = 0.95f;
	const float absoluteTol = 0.01f;

	if (faceA.y > relativeTol * separation + absoluteTol * hA.y)
	{
		axis = FACE_A_Y;
		separation = faceA.y;
		normal = dA.y > 0.0f ? a2 : -a2;
	}

	// Box B faces
	if (faceB.x > relativeTol * separation + absoluteTol * hB.x)
	{
		axis = FACE_B_X;
		separation = faceB.x;
		normal = dB.x > 0.0f ? b1 : -b1;
	}

	if (faceB.y > relativeTol * separation + absoluteTol * hB.y)
	{
		axis = FACE_B_Y;
		separation = faceB.y;
		normal = dB.y > 0.0f ? b2 : -b2;
	}
	
	float2 frontNormal, sideNormal;
	ClipVertex incidentEdge[2];
	float front, negSide, posSide;
	char negEdge, posEdge;

	switch (axis)
	{
	case FACE_A_X:
		{
			frontNormal = normal;
			front = posA.dot(frontNormal) + hA.x;
			sideNormal = a2;
			float side = posA.dot(sideNormal);
			negSide = -side + hA.y;
			posSide =  side + hA.y;
			negEdge = EDGE3;
			posEdge = EDGE1;
			ComputeIncidentEdge(incidentEdge, hB, posB, rotB, frontNormal);
		}
		break;

	case FACE_A_Y:
		{
			frontNormal = normal;
			front = posA.dot(frontNormal) + hA.y;
			sideNormal = a1;
			float side = posA.dot(sideNormal);
			negSide = -side + hA.x;
			posSide =  side + hA.x;
			negEdge = EDGE2;
			posEdge = EDGE4;
			ComputeIncidentEdge(incidentEdge, hB, posB, rotB, frontNormal);
		}
		break;

	case FACE_B_X:
		{
			frontNormal = -normal;
			front = posB.dot(frontNormal) + hB.x;
			sideNormal = b2;
			float side = posB.dot(sideNormal);
			negSide = -side + hB.y;
			posSide =  side + hB.y;
			negEdge = EDGE3;
			posEdge = EDGE1;
			ComputeIncidentEdge(incidentEdge, hA, posA, rotA, frontNormal);
		}
		break;

	case FACE_B_Y:
		{
			frontNormal = -normal;
			front = posB.dot(frontNormal) + hB.y;
			sideNormal = b1;
			float side = posB.dot(sideNormal);
			negSide = -side + hB.x;
			posSide =  side + hB.x;
			negEdge = EDGE2;
			posEdge = EDGE4;
			ComputeIncidentEdge(incidentEdge, hA, posA, rotA, frontNormal);
		}
		break;
	}

	ClipVertex clipPoints1[2];
	ClipVertex clipPoints2[2];
	int np;

	np = ClipSegmentToLine(clipPoints1, incidentEdge, -sideNormal, negSide, negEdge);
	if (np < 2) return 0;
	np = ClipSegmentToLine(clipPoints2, clipPoints1,  sideNormal, posSide, posEdge);
	if (np < 2) return 0;

	int numContacts = 0;
	for (int i = 0; i < 2; ++i)
	{
		float separation = frontNormal.dot(clipPoints2[i].v) - front;

		if (separation <= 0)
		{
			contacts[numContacts].seperation = separation;
			contacts[numContacts].normal = normal;
			// slide contact point onto reference face (easy to cull)
			contacts[numContacts].pos = clipPoints2[i].v - frontNormal * separation;
			contacts[numContacts].feature = clipPoints2[i].fp;
			if (axis == FACE_B_X || axis == FACE_B_Y)
			{
				Flip(contacts[numContacts].feature);
			}
			++numContacts;
		}
	}

	return numContacts;
};