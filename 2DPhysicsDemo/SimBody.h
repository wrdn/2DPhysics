#pragma once

#include "NetworkController.h"
#include "Mat22.h"
#include "float2.h"
#include "Mesh.h"
#include "Material.h"
#include "util.h"
#include <vector>
#include "ThreadPool.h"
#include "SAT.h"

const float2 default_gravity(0, meters(-9.81f));

struct SplittingPlane
{
	float2 N;
	float d;

	SplittingPlane() : d(0) {};
	SplittingPlane(float2 &_N, float _d)
		: N(_N), d(_d) {};
	~SplittingPlane() {};
};

// Base for physics objects
class SimBody
{
public:
	static int GUID_GEN;

	SimBody();
	~SimBody(void) {};

	static int whoami; // set from ConnectAuth network packet. used to ensure we only update our half of data
	int owner;

	static float2 gravity;

	// PHYSICS VARIABLES
	float2 position;
	float2 velocity;
	f32 mass, invMass;

	bool isbox;
	int hashid;

	// only need rotation about z, every time this is updated, you should also update _cached_rotation_matrix
	// rotation specified in degrees
	f32 rotation_in_rads;
	Mat22 rotation_matrix; // Mat22::RotationMatrix(rotation)
	f32 angularVelocity; // around z
	
	float2 force;
	f32 torque;
	f32 density;
	f32 inertia; // inertia = CalculateInertia()
	f32 invInertia; // 1/inertia

	f32 friction;
	f32 dragCoefficient; // default 0.1
	f32 I, invI; // impulse? (see Catto)

	// Bounding stuff
	f32 boundingCircleRadius; // all objects have a bounding circle, to allow for very fast rejection tests

	// GRAPHICS VARIABLES
	Material objectMaterial;
	MeshHandle mesh;
	GLenum fillMode;
	bool use_textures, use_shaders;
	
	bool draw; // enable/disable drawing of the simbody
	bool update;

	// Data used during SAT collision phase. You should ONLY use CalculateVerticesAndSeperatingAxis() to set this data
	std::vector<float2> vertices;
	std::vector<SplittingPlane> splittingPlanes;

	std::vector<float2> seperatingAxis;

	// world space positions of vertices and splitting planes (once transformations have been applied)
	std::vector<float2> transformedVertices;
	std::vector<SplittingPlane> transformedSplittingPlanes;

	float2 width; // box info
	float side_len; // triangle info

	u32 lastAxis; // cache the last axis we found a seperation on, and we'll use it first next time

	void UpdateWorldSpaceProperties()
	{
		CalculateRotationMatrix();
		
		float cos_angle = cos(rotation_in_rads);
		float sin_angle = sin(rotation_in_rads);

		// assumes transformedVertices size == vertices size
		for(u32 i=0;i<vertices.size();++i)
		{
			transformedVertices[i] = position + (vertices[i].rotate(cos_angle, sin_angle));
		}

		// assumes splittingPlanes size == vertices size
		for(u32 i=0;i<splittingPlanes.size();++i)
		{
			float2 n = splittingPlanes[i].N.rotate(cos_angle, sin_angle);
			transformedSplittingPlanes[i].N = n;
			transformedSplittingPlanes[i].d = position.dot(n) + splittingPlanes[i].d;
		}
	};

	void CalculateRotationMatrix()
	{
		rotation_matrix = Mat22::RotationMatrix(rotation_in_rads);
	}

	// http://www.physicsforums.com/showthread.php?s=e251fddad79b926d003e2d4154799c14&t=25293&page=2&pp=15
	void CalculateInertia()
	{
		if(vertices.size() == 1)
		{
			inertia = invInertia = 0;
			return;
		}

		f32 denom = 0, numer = 0;

		float2 *A = &vertices[0];

		for(u32 j=vertices.size()-1,i=0;i<vertices.size();j=i,i++)
		{
			float2 P0 = A[j];
			float2 P1 = A[i];

			f32 a = (f32)fabs(P0 ^ P1);
			f32 b = P1.dot(P1) + P1.dot(P0) + P0.dot(P0);

			denom += (a * b);
			numer += a;
		}
		
		inertia = (mass / 6.0f) * (denom / numer);
		invInertia = 1.0f / inertia;
	};

	void Init()
	{
		force.zero();
		velocity.zero();
		position.zero();
		torque = 0;
		angularVelocity = 0;
		
		CalculateInertia();
	};

	void Draw();

	bool Collide(SimBody &other, f32 dt);

	bool Unmovable() { return mass <= EPSILON; };

	void AddForce(const float2 &F)
	{
		if(Unmovable()) return;

		force += F;
	};

	SplittingPlane GenSplittingPlane(float2 a, float2 b)
	{
		float2 n = (b-a).perp().normalize();
		return SplittingPlane(n, n.dot(a));
	};

	// untested, assumes convex
	void MakePolygon(const std::vector<float2> &verts)
	{
		vertices = verts; // copy all the verts

		transformedVertices.resize(vertices.size());

		SAT::GenerateSeperatingAxes(vertices, seperatingAxis);

		for(u32 i=0;i<vertices.size();++i)
		{
			SplittingPlane sp = GenSplittingPlane(vertices[i], vertices[(i+1)%vertices.size()]);
			splittingPlanes.push_back(sp);
		}

		transformedSplittingPlanes.resize(splittingPlanes.size());

		UpdateWorldSpaceProperties();
	};

	void MakeTriangle(float sideLen)
	{
		float h = sideLen/2;
		std::vector<float2> verts;
		verts.push_back(float2(-h, -h));
		verts.push_back(float2(0, h));
		verts.push_back(float2(h, -h));

		MakePolygon(verts);
	};

	void MakeBox(float boxwidth, float boxheight)
	{
		width.set(boxwidth, boxheight);
		float2 h = width/2; // half width and height
		std::vector<float2> verts;
		verts.push_back(float2(-h.x, -h.y));
		verts.push_back(float2(-h.x, h.y));
		verts.push_back(float2(h.x, h.y));
		verts.push_back(float2(h.x, -h.y));

		MakePolygon(verts);
	};

	void Update(f32 dt)
	{
		if(Unmovable())
		{
			velocity.zero();
			angularVelocity = 0;
			return;
		}

		position += velocity * dt;
		
		rotation_in_rads += (angularVelocity) * dt;
		rotation_in_rads = wrapf(rotation_in_rads, -TWOPI, TWOPI);
		rotation_matrix = Mat22::RotationMatrix(rotation_in_rads);

		velocity += force * (invMass * dt);
		angularVelocity += torque * (invInertia * dt);

		force.zero();
		torque = 0;
	};
};

bool BoundingCircleIntersects(const SimBody &a, const SimBody &b);