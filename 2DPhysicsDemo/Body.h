#pragma once

#include "MathUtils.h"
#include "Arbiter.h"

class Body
{
public:
	Body();
	~Body();
	void Set(const Vector2f& w, float m);

	void AddForce(const Vector2f& f)
	{
		force += f;
	}

	Vector2f position;
	float rotation;

	Vector2f velocity;
	float angularVelocity;

	Vector2f force;
	float torque;

	Vector2f width;

	float friction;
	float mass, invMass;
	float I, invI;

	void Draw();
};