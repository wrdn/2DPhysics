#pragma once

#include "Mat22.h"
#include "float2.h"
#include "Mesh.h"
#include "Material.h"
#include "util.h"
#include <vector>

const float2 default_gravity(0, meters(-9.81f));

// Base for physics objects
class SimBody
{
public:
	SimBody();
	~SimBody(void) {};

	static float2 gravity;

	// PHYSICS VARIABLES
	float2 position;
	float2 velocity;
	f32 mass, invMass;
	f32 boundingCircleRadius; // all objects have a bounding circle, to allow for very fast rejection tests

	// only need rotation about z, every time this is updated, you should also update _cached_rotation_matrix
	// rotation specified in degrees
	f32 rotation_in_rads;
	Mat22 rotation_matrix; // Mat22::RotationMatrix(rotation)
	f32 angularVelocity; // around z
	float2 force;
	f32 torque;
	
	f32 friction;
	f32 dragCoefficient; // default 0.1
	f32 I, invI; // impulse? (see Catto)

	f32 density;
	f32 inertia;
	f32 invInertia;

	// GRAPHICS VARIABLES
	Material objectMaterial;
	MeshHandle mesh;
	GLenum fillMode;
	bool use_textures, use_shaders;
	
	bool draw; // enable/disable drawing of the simbody
	bool update;

	// Data used during SAT collision phase. You should ONLY use CalculateVerticesAndSeperatingAxis() to set this data
	std::vector<float2> vertices;
	std::vector<float2> seperatingAxis;

	float2 extents; // box info
	float side_len; // triangle info

	void CalculateRotationMatrix()
	{
		rotation_matrix = Mat22::RotationMatrix(rotation_in_rads);
	}

	void Draw();

	bool Collide(SimBody &other, f32 dt);

	bool Unmovable() { return mass <= EPSILON; };
};

bool BoundingCircleIntersects(const SimBody &a, const SimBody &b);