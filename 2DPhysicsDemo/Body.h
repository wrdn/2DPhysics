#pragma once

#include "MathUtils.h"
#include "Arbiter.h"
#include "float2.h"
#include <vector>
#include "SAT.h"
using namespace std;

/*
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
	
	float boundingCircleRadius;

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

	float2 centroid;

	float m_radius;

	// original vertices and axes (untransformed). used for sat
	vector<float2> vertices, axes;

	void Draw();

	void GetVertices(vector<float2> &out);
};
*/