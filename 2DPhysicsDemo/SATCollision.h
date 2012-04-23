#pragma once

#include "SimBody.h"
#include "Collision.h"

// This is the function you are advised to use. It uses the SimBody vertex and seperating axis list data, and "should" work
// with any 2 SimBodies, as long as the combined number of seperating axis is less than or equal to 6
bool Intersect(const SimBody &a, const SimBody &b, float2 &out_mtd_vec, f32 &t);

// Find minimum translation vector
bool FindMTD(const float2 *axis, f32 *taxis, const u32 axisCount, float2 &N, f32 &t);

// If rotation isn't required or used, just set xOrient to the identity matrix
bool IntervalIntersect(
	const float2 &axis, const float2 * const polyAverts,
	const float2 * const polyBverts,
	const u32 polyAcount, const u32 polyBcount,
	const float2 &relativePosition, f32 &taxis,
	const Mat22 &xOrient=Mat22());

void GetInterval(const float2 &axis, const float2 * const verts, const u32 vertCount, MinMaxProjection &proj);