#include "SATCollision.h"

// Perform SAT intersection testing on 2 boxes - using SAT as we will later extend it to
// generate a "push" vector, then change to OBBs
bool IntersectAABB(const Box &a, const Box &b, float2 &out_mtd_vec, f32 &t)
{
	float2 relativePosition = a.position - b.position; // relative position

	static const float2 AXIS[2] = { float2(1,0), float2(0,1) };

	f32 taxis[2];

	if(!IntervalIntersect(AXIS[0], a._cached_vertices, b._cached_vertices, 
		4, 4, relativePosition, taxis[0]))
	{
		return false;
	}
	if(!IntervalIntersect(AXIS[1], a._cached_vertices, b._cached_vertices, 
		4, 4, relativePosition, taxis[1]))
	{
		return false;
	}

	if(!FindMTD(AXIS,  taxis, 2, out_mtd_vec, t))
	{
		return false;
	}

	f32 mtd_dot_rp = out_mtd_vec.dot(relativePosition);

	// Ignore the self assignment here. It is a possible optimisation as sometimes,
	// the ternary (sp?) operator will using floating point selects, resulting in
	// branchless code - a big win :)
	out_mtd_vec = mtd_dot_rp < 0.0f ? out_mtd_vec.negate() : out_mtd_vec;

	return true;
};