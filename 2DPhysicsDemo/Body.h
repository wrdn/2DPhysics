#pragma once

#include "MathUtils.h"
#include "Arbiter.h"
#include "float2.h"

class Body
{
public:
	Body();
	~Body();
	void Set(const float2& w, float m);

	void AddForce(const float2& f)
	{
		force += f;
	}

	float2 position;
	float rotation;

	float2 velocity;
	float angularVelocity;

	float2 force;
	float torque;

	float2 width;

	float friction;
	float mass, invMass;
	float I, invI;

	float boundingCircleRadius;

	void Draw();
};