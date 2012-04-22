#include "SATCollision.h"

bool IntersectOBBTriangle(const Box &a, const Triangle &b, float2 &out_mtd_vec, f32 &t)
{
	if(&a||&b||&out_mtd_vec||&t){};
	return false;
	/*const Mat22 &OA = a._cached_rotation_matrix;
	const Mat22 &OB = b._cached_rotation_matrix;

	Mat22 xOrient = OA * OB.Transpose();
	float2 xOffset = (a.position - b.position) * OB.Transpose();

	float2 xAxis[5];
	f32 tAxis[5];
	u32 axisCount = 0;

	//************************************
	// Test seperating axes of A (2 axis for box)
	//************************************

	{
		float2 aBL = a._cached_vertices[Box::BL]; // bottom left vertex
		float2 aBR = a._cached_vertices[Box::BR]; // bottom right vertex
		float2 aTL = a._cached_vertices[Box::TL]; // top left vertex
		float2 aFirstAxis = aTL - aBL;
		float2 aSecondAxis = aBR - aBL;

		// First axis
		xAxis[axisCount] = aFirstAxis.perp() * xOrient;
		if(!IntervalIntersect(xAxis[axisCount], a._cached_vertices, b._cached_vertices, 4,3, xOffset, tAxis[axisCount], xOrient))
			return false;
		++axisCount;

		// Second axis
		xAxis[axisCount] = aSecondAxis.perp() * xOrient;
		if(!IntervalIntersect(xAxis[axisCount], a._cached_vertices, b._cached_vertices, 4,3, xOffset, tAxis[axisCount], xOrient))
			return false;
		++axisCount;
	}

	//************************************
	// Test seperating axes of B
	//************************************

	{
		float2 bT =  b._cached_vertices[Triangle::T]; // top vertex
		float2 bBL = b._cached_vertices[Triangle::BL]; // bottom left vertex
		float2 bBR = b._cached_vertices[Triangle::BR]; // bottom right vertex
		float2 bFirstAxis =  bT -  bBL;
		float2 bSecondAxis = bT -  bBR;
		float2 bThirdAxis =  bBR - bBL;

		// First axis
		xAxis[axisCount] = bFirstAxis.perp();
		if(!IntervalIntersect(xAxis[axisCount], a._cached_vertices, b._cached_vertices, 4, 3, xOffset, tAxis[axisCount], xOrient))
			return false;
		++axisCount;

		// Second axis
		xAxis[axisCount] = bSecondAxis.perp();
		if(!IntervalIntersect(xAxis[axisCount], a._cached_vertices, b._cached_vertices, 4, 3, xOffset, tAxis[axisCount], xOrient))
			return false;
		++axisCount;

		// Third axis
		xAxis[axisCount] = bThirdAxis.perp();
		if(!IntervalIntersect(xAxis[axisCount], a._cached_vertices, b._cached_vertices, 4, 3, xOffset, tAxis[axisCount], xOrient))
			return false;
		++axisCount;
	}

	if(!FindMTD(xAxis, tAxis, axisCount, out_mtd_vec, t))
	{
		return false;
	}

	out_mtd_vec = out_mtd_vec.dot(xOffset) < 0.0f ? out_mtd_vec.negate() : out_mtd_vec;
	out_mtd_vec = out_mtd_vec * OB;

	return true;*/
};