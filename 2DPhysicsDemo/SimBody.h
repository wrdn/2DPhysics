#pragma once

#include "Mat22.h"
#include "float2.h"
#include "Mesh.h"
#include "Material.h"
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
	f32 rotation;
	Mat22 _cached_rotation_matrix; // Mat22::RotationMatrix(rotation)
	f32 angularVelocity; // around z
	float2 force;
	f32 torque;
	
	f32 friction;
	f32 dragCoefficient; // default 0.1
	f32 I, invI; // impulse? (see Catto)

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

	void Draw();
};

bool BoundingCircleIntersects(const SimBody &a, const SimBody &b);

// used to represent a box in the simulation
// Since SimBody contains a "rotation" and "position" parameter, this
// object only needs to store the extents of the box
class Box : public SimBody
{
public:
	Box() : extents(1,1)
	{
		CalculateVerticesAndSeperatingAxis();
	};
	~Box() {};

	float2 extents; // half-width and half-height of box (from center)

	enum { BL, BR, TL, TR };

	// calculates and caches vertices from box extents
	// origin is assumed to be at (0,0). In collision code, we use relative position
	// of objects. This way, we don't have to recalculate vertex positions
	void CalculateVerticesAndSeperatingAxis();
};

class Triangle : public SimBody // designed for equilateral triangles only
{
public:
	Triangle() : sideLength(1)
	{
		CalculateVerticesAndSeperatingAxis();
	};
	~Triangle() {};

	f32 sideLength;

	//enum TriVert { T=0, BL=1, BR=2 };
	//float2 _cached_vertices[3];

	enum { T, BL, BR };

	void CalculateVerticesAndSeperatingAxis();
};