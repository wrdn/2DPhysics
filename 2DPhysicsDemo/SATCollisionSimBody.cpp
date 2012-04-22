#include "SATCollision.h"
#include "util.h"

bool Intersect(SimBody &a, SimBody &b, float2 &out_mtd_vec, f32 &t)
{
	const Mat22 &OA = a._cached_rotation_matrix;
	const Mat22 &OB = b._cached_rotation_matrix;
	const Mat22 OB_T = OB.Transpose();

	Mat22 xOrient = OA * OB_T;
	float2 xOffset = (a.position - b.position) * OB_T;

	// max of 6 seperating axis
	// for our needs, this should be enough (worst case for
	// boxes and equilateral triangles is 2 triangles, which gives
	// 6 seperating axis). 2 boxes give 4 axis. A box and a triangle
	// gives 5 axis
	float2 xAxis[64];
	f32 tAxis[64];
	u32 axisCount = 0;
	
	// Test seperating axes of A
	for(u32 i=0;i<a.seperatingAxis.size();++i)
	{
		xAxis[axisCount] = a.seperatingAxis[i] * xOrient;
		if(!IntervalIntersect(xAxis[axisCount], &a.vertices[0], &b.vertices[0],
			a.vertices.size(), b.vertices.size(), xOffset, tAxis[axisCount], xOrient))
		{
			return false;
		}
		++axisCount;
	}

	// Test seperating axes of B
	for(u32 i=0;i<b.seperatingAxis.size();++i)
	{
		xAxis[axisCount] = b.seperatingAxis[i];
		if(!IntervalIntersect(xAxis[axisCount], &a.vertices[0], &b.vertices[0],
			a.vertices.size(), b.vertices.size(), xOffset, tAxis[axisCount], xOrient))
		{
			return false;
		}
		++axisCount;
	}

	// Find minimum translation vector
	if(!FindMTD(xAxis, tAxis, axisCount, out_mtd_vec, t))
		return false;

	out_mtd_vec = out_mtd_vec.dot(xOffset) < 0.0f ?
		out_mtd_vec.negate() : out_mtd_vec;

	out_mtd_vec = out_mtd_vec * OB;

	return true;
};