#pragma once

#include "Line.h"
#include "Circle.h"

struct CollisionPoint2D
{
public:
	float2 p1; f32 t1; // always the shortest distance
	float2 p2; f32 t2; // always the longest distance

	CollisionPoint2D() : p1(), t1(0), p2(), t2(0) { };
	~CollisionPoint2D() { };
};

bool LineCircleCollision(const Line2D &line, const Circle &c, CollisionPoint2D &cp);