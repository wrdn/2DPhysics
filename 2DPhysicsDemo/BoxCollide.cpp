#include "Arbiter.h"

#include "Arbiter.h"
#include "Body.h"

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
	ClipVertex() { fp.value = 0; };
	Vector2f v;
	FeaturePair fp;
};

void Flip(FeaturePair& fp)
{
	Swap(fp.e.inEdge1, fp.e.inEdge2);
	Swap(fp.e.outEdge1, fp.e.outEdge2);
}

int ClipSegmentToLine(ClipVertex vOut[2], ClipVertex vIn[2],
					  const Vector2f& normal, float offset, char clipEdge)
{
	// Start with no output points
	int numOut = 0;

	// Calculate the distance of end points to the line
	float distance0 = Dot(normal, vIn[0].v) - offset;
	float distance1 = Dot(normal, vIn[1].v) - offset;

	// If the points are behind the plane
	if (distance0 <= 0.0f) vOut[numOut++] = vIn[0];
	if (distance1 <= 0.0f) vOut[numOut++] = vIn[1];

	// If the points are on different sides of the plane
	if (distance0 * distance1 < 0.0f)
	{
		// Find intersection point of edge and plane
		float interp = distance0 / (distance0 - distance1);
		vOut[numOut].v = vIn[0].v + interp * (vIn[1].v - vIn[0].v);
		if (distance0 > 0.0f)
		{
			vOut[numOut].fp = vIn[0].fp;
			vOut[numOut].fp.e.inEdge1 = clipEdge;
			vOut[numOut].fp.e.inEdge2 = NO_EDGE;
		}
		else
		{
			vOut[numOut].fp = vIn[1].fp;
			vOut[numOut].fp.e.outEdge1 = clipEdge;
			vOut[numOut].fp.e.outEdge2 = NO_EDGE;
		}
		++numOut;
	}

	return numOut;
}

static void ComputeIncidentEdge(ClipVertex c[2], const Vector2f& h, const Vector2f& pos,
								const Matrix22& Rot, const Vector2f& normal)
{
	// The normal is from the reference box. Convert it
	// to the incident boxe's frame and flip sign.
	Matrix22 RotT = Rot.Transpose();
	Vector2f n = -(RotT * normal);
	Vector2f nAbs = Abs(n);

	if (nAbs.x > nAbs.y)
	{
		if (Sign(n.x) > 0.0f)
		{
			c[0].v.Set(h.x, -h.y);
			c[0].fp.e.inEdge2 = EDGE3;
			c[0].fp.e.outEdge2 = EDGE4;

			c[1].v.Set(h.x, h.y);
			c[1].fp.e.inEdge2 = EDGE4;
			c[1].fp.e.outEdge2 = EDGE1;
		}
		else
		{
			c[0].v.Set(-h.x, h.y);
			c[0].fp.e.inEdge2 = EDGE1;
			c[0].fp.e.outEdge2 = EDGE2;

			c[1].v.Set(-h.x, -h.y);
			c[1].fp.e.inEdge2 = EDGE2;
			c[1].fp.e.outEdge2 = EDGE3;
		}
	}
	else
	{
		if (Sign(n.y) > 0.0f)
		{
			c[0].v.Set(h.x, h.y);
			c[0].fp.e.inEdge2 = EDGE4;
			c[0].fp.e.outEdge2 = EDGE1;

			c[1].v.Set(-h.x, h.y);
			c[1].fp.e.inEdge2 = EDGE1;
			c[1].fp.e.outEdge2 = EDGE2;
		}
		else
		{
			c[0].v.Set(-h.x, -h.y);
			c[0].fp.e.inEdge2 = EDGE2;
			c[0].fp.e.outEdge2 = EDGE3;

			c[1].v.Set(h.x, -h.y);
			c[1].fp.e.inEdge2 = EDGE3;
			c[1].fp.e.outEdge2 = EDGE4;
		}
	}

	c[0].v = pos + Rot * c[0].v;
	c[1].v = pos + Rot * c[1].v;
}

// The normal points from A to B
int Collide(Contact* contacts, Body* bodyA, Body* bodyB)
{
	// Setup
	Vector2f hA = 0.5f * bodyA->width;
	Vector2f hB = 0.5f * bodyB->width;

	Vector2f posA = bodyA->position;
	Vector2f posB = bodyB->position;

	Matrix22 RotA(bodyA->rotation), RotB(bodyB->rotation);

	Matrix22 RotAT = RotA.Transpose();
	Matrix22 RotBT = RotB.Transpose();

	Vector2f a1 = RotA.col1, a2 = RotA.col2;
	Vector2f b1 = RotB.col1, b2 = RotB.col2;

	Vector2f dp = posB - posA;
	Vector2f dA = RotAT * dp;
	Vector2f dB = RotBT * dp;

	Matrix22 C = RotAT * RotB;
	Matrix22 absC = Abs(C);
	Matrix22 absCT = absC.Transpose();

	// Box A faces
	Vector2f faceA = Abs(dA) - hA - absC * hB;
	if (faceA.x > 0.0f || faceA.y > 0.0f)
		return 0;

	// Box B faces
	Vector2f faceB = Abs(dB) - absCT * hA - hB;
	if (faceB.x > 0.0f || faceB.y > 0.0f)
		return 0;

	// Find best axis
	Axis axis;
	float separation;
	Vector2f normal;

	// Box A faces
	axis = FACE_A_X;
	separation = faceA.x;
	normal = dA.x > 0.0f ? RotA.col1 : -RotA.col1;

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

	// Setup clipping plane data based on the separating axis
	Vector2f frontNormal, sideNormal;
	ClipVertex incidentEdge[2];
	float front, negSide, posSide;
	char negEdge, posEdge;

	// Compute the clipping lines and the line segment to be clipped.
	switch (axis)
	{
	case FACE_A_X:
		{
			frontNormal = normal;
			front = Dot(posA, frontNormal) + hA.x;
			sideNormal = RotA.col2;
			float side = Dot(posA, sideNormal);
			negSide = -side + hA.y;
			posSide =  side + hA.y;
			negEdge = EDGE3;
			posEdge = EDGE1;
			ComputeIncidentEdge(incidentEdge, hB, posB, RotB, frontNormal);
		}
		break;

	case FACE_A_Y:
		{
			frontNormal = normal;
			front = Dot(posA, frontNormal) + hA.y;
			sideNormal = RotA.col1;
			float side = Dot(posA, sideNormal);
			negSide = -side + hA.x;
			posSide =  side + hA.x;
			negEdge = EDGE2;
			posEdge = EDGE4;
			ComputeIncidentEdge(incidentEdge, hB, posB, RotB, frontNormal);
		}
		break;

	case FACE_B_X:
		{
			frontNormal = -normal;
			front = Dot(posB, frontNormal) + hB.x;
			sideNormal = RotB.col2;
			float side = Dot(posB, sideNormal);
			negSide = -side + hB.y;
			posSide =  side + hB.y;
			negEdge = EDGE3;
			posEdge = EDGE1;
			ComputeIncidentEdge(incidentEdge, hA, posA, RotA, frontNormal);
		}
		break;

	case FACE_B_Y:
		{
			frontNormal = -normal;
			front = Dot(posB, frontNormal) + hB.y;
			sideNormal = RotB.col1;
			float side = Dot(posB, sideNormal);
			negSide = -side + hB.x;
			posSide =  side + hB.x;
			negEdge = EDGE2;
			posEdge = EDGE4;
			ComputeIncidentEdge(incidentEdge, hA, posA, RotA, frontNormal);
		}
		break;
	}

	// clip other face with 5 box planes (1 face plane, 4 edge planes)

	ClipVertex clipPoints1[2];
	ClipVertex clipPoints2[2];
	int np;

	// Clip to box side 1
	np = ClipSegmentToLine(clipPoints1, incidentEdge, -sideNormal, negSide, negEdge);

	if (np < 2)
		return 0;

	// Clip to negative box side 1
	np = ClipSegmentToLine(clipPoints2, clipPoints1,  sideNormal, posSide, posEdge);

	if (np < 2)
		return 0;

	// Now clipPoints2 contains the clipping points.
	// Due to roundoff, it is possible that clipping removes all points.

	int numContacts = 0;
	for (int i = 0; i < 2; ++i)
	{
		float separation = Dot(frontNormal, clipPoints2[i].v) - front;

		if (separation <= 0)
		{
			contacts[numContacts].separation = separation;
			contacts[numContacts].normal = normal.tofloat2();
			// slide contact point onto reference face (easy to cull)
			contacts[numContacts].position = (clipPoints2[i].v - separation * frontNormal).tofloat2();
			contacts[numContacts].feature = clipPoints2[i].fp;
			if (axis == FACE_B_X || axis == FACE_B_Y)
				Flip(contacts[numContacts].feature);
			++numContacts;
		}
	}

	return numContacts;
}