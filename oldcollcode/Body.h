#pragma once

#include "float2.h"
#include <float.h>
#include <vector>
#include <GXBase.h>
using namespace std;

void CalculateInertia(vector<float2> &vertices,
	float mass, float &inertia, float &invInertia);

class Body
{
public:
	float2 pos, velocity, force;
	float rotation, angularVelocity, torque;
	float friction, mass, invMass, inertia, invInertia;
	float restitution;
	
	vector<float2> vertices;
	
	float2 dimensions; // width and height (for box)

	Body() : pos(), velocity(), force(), rotation(0), angularVelocity(0),
		torque(0), friction(0.2f), mass(FLT_MAX), invMass(0), inertia(0),
		invInertia(0), restitution(0.3f)
	{
	};
	~Body() {};

	void Draw();
};