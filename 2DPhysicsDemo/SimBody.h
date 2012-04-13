#pragma once

#include "float2.h"
#include "Mesh.h"
#include "Material.h"

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

	f32 rotation; // only need rotation about z
	f32 angularVelocity; // around z
	float2 force;
	f32 torque;
	
	f32 friction;
	f32 dragCoefficient; // default 0.1
	f32 I, invI; // impulse (see Catto)

	// GRAPHICS VARIABLES
	Material objectMaterial;
	MeshHandle mesh;
	GLenum fillMode;
	bool use_textures, use_shaders;
	
	bool draw; // enable/disable drawing of the simbody
	bool update;

	void Draw();
};

bool BoundingCircleIntersects(const SimBody &a, const SimBody &b);

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

	// Top Left (TL), Top Right (TR), Bottom Left (BL), Bottom Right (BR)
	enum boxvert { TL, TR, BL, BR };

	float2 _cached_vertices[4];

	// calculates and caches vertices from box extents
	// origin is assumed to be at (0,0). In collision code, we use relative position
	// of objects. This way, we don't have to recalculate vertex positions
	void CalculateVertices()
	{
		_cached_vertices[BL].set(-extents.x(), -extents.y());
		_cached_vertices[BR].set(extents.x(),  -extents.y());
		_cached_vertices[TL].set(-extents.x(), extents.y());
		_cached_vertices[TR].set(extents.x(),  extents.y());
	};
};

struct MinMaxProjection
{
public:
	f32 min;
	f32 max;
};

bool Intersect(const Box &a, const Box &b, float2 &out_mtd_vec, f32 &t);
void CalculateBoxVertices(const Box &b, float2 *verts);
bool overlaps(MinMaxProjection &ax, MinMaxProjection &bx); // 1D overlap test