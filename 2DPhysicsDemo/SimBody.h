#pragma once

#include "float2.h"
#include "Mesh.h"
#include "Material.h"

const float2 gravity(0,-9.81f); // gravity defined as -9.81 m/s^2

// Base for physics objects
class SimBody
{
public:
	SimBody(void)
	{
		position = float2(0.0f);
		rotation = 0.0f;
		velocity = float2(0.0f);
		angularVelocity = 0.0f;
		force = float2(0.0f);
		torque = 0.0f;
		friction = 0.2f;

		mass = I = 10;
		invMass = invI = 1.0f/mass;

		fillMode = GL_FILL;
		mesh = MeshHandle(0);

		use_textures = use_shaders = draw = true;
	};

	~SimBody(void) {};

	// PHYSICS VARIABLES
	float2 position;
	float rotation; // only need rotation about z

	float2 velocity;
	float angularVelocity; // around z

	float2 force;
	float torque;

	float friction;
	float mass, invMass;
	float I, invI; // impulse (see Catto)

	
	// GRAPHICS VARIABLES
	Material objectMaterial;
	MeshHandle mesh;
	GLenum fillMode;
	bool use_textures, use_shaders;
	bool draw; // enable/disable drawing of the simbody

	void Draw();
};

// used to represent a box in the simulation
// Since SimBody contains a "rotation" and "position" parameter, this
// object only needs to store the extents of the box
class Box : public SimBody
{
public:
	Box()
	{
		extents = float2(1,1);
	};
	~Box() {};

	float2 extents; // half-width and half-height of box (from center)
};