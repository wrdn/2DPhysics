#pragma once

#include "SimBody.h"
#include "Line.h"
#include "float2.h"
#include "float3.h"

// 2D Axis Aligned Bounding Box
// Note: a circle could use the same structure as this, as long as extents (radius) x and y values
// are identical (to avoid ambiguity). This is sensible, and is memory efficient, with the structure
// 16 bytes in size (and on byte boundary)
struct AABB
{
public:
	AABB() {};
	AABB(const float2 &_center, const float2 &_extents)
		: center(_center), extents(_extents) {};

	float2 center;
	float2 extents; // half width and half height
};

// 2D Circle
struct Circle
{
public:
	Circle() : radius(5) {};
	Circle(const float2 &_center, const f32 _radius) // constructor that can be used if box dimensions are same (i.e. a square), or if you want to treat the AABB as a Circle
		: center(_center), radius(_radius) {};

	float2 center;
	f32 radius;
};

struct CollisionPoint2D
{
public:
	float2 p1; f32 t1; // always the shortest distance
	float2 p2; f32 t2; // always the longest distance

	CollisionPoint2D() : p1(), t1(0), p2(), t2(0) { };
	~CollisionPoint2D() { };
};

struct MinMaxProjection
{
public:
	f32 min;
	f32 max;
};

bool LineCircleCollision(const Line2D &line, const Circle &c, CollisionPoint2D &cp);

bool Hit(const AABB &a, const AABB &b);

bool Hit(const Circle &a, const Circle &b);

// bounding circle test
bool BoundingCircleHit(const float2 &pos1, const float radius1, const float2 &pos2, const float radius2);

bool Overlaps(MinMaxProjection &ax, MinMaxProjection &bx);

void ProjectPointOnSegment(const float2 &V, const float2 &A, const float2 &B, float2 &W, f32 &pt);

float2 TransformVector(const float2 &vertex, const float2 &p, const float2 &v, const Mat22 xOrient, f32 t);