#pragma once

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

// 2D Oriented Bounding Box
struct OBB
{
public:
	float2 center; // 8
	float2 extents; // half width and half height, 8
	float2 axis[2]; // local x-axis [0] and y-axis [1]
};

// 2D Circle
struct Circle
{
public:
	Circle() : radius(5) {};
	Circle(const float2 &_center, const float _radius) // constructor that can be used if box dimensions are same (i.e. a square), or if you want to treat the AABB as a Circle
		: center(_center), radius(_radius) {};

	float2 center;
	float radius;
};
struct CollisionPoint2D
{
public:
	float2 p1; f32 t1; // always the shortest distance
	float2 p2; f32 t2; // always the longest distance

	CollisionPoint2D() : p1(), t1(0), p2(), t2(0) { };
	~CollisionPoint2D() { };
};

bool LineCircleCollision(const Line2D &line, const Circle &c, CollisionPoint2D &cp);

bool Hit_AABB_AABB(const AABB &a, const AABB &b);

bool Hit_Circle_Circle(const Circle &a, const Circle &b);

// Seperating Axis Theorem to find if two OBBs hit
bool Hit_OBB_OBB(const OBB &a, const OBB &b);