#pragma once

#include "SimBody.h"
#include "Collision.h"

bool IntersectAABB(const Box &a, const Box &b, float2 &out_mtd_vec, f32 &t);
bool IntersectOBB(const Box &a, const Box &b, float2 &out_mtd_vec, f32 &t);
bool IntersectTriangleTriangle(const Triangle &a, const Triangle &b, float2 &out_mtd_vec, f32 &t);
bool IntersectOBBTriangle(const Box &a, const Triangle &b, float2 &out_mtd_vec, f32 &t);

// Find minimum translation vector
bool FindMTD(const float2 *axis, f32 *taxis, u32 axisCount, float2 &N, f32 &t);

// If rotation isn't required or used, just set xOrient to the identity matrix
bool IntervalIntersect(
	const float2 &axis, const float2 * const polyAverts,
	const float2 * const polyBverts,
	const u32 polyAcount, const u32 polyBcount,
	const float2 &relativePosition, f32 &taxis,
	const Mat22 &xOrient=Mat22());

void GetInterval(const float2 &axis, const float2 * const verts, const u32 vertCount, MinMaxProjection &proj);