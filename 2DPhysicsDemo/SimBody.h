#pragma once

#include "Mat22.h"
#include "float2.h"
#include "Mesh.h"
#include "Material.h"
#include "util.h"
#include <vector>
#include "ThreadPool.h"

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

	bool isbox;

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
	std::vector<float2> seperatingAxis;

	float2 width; // box info
	float side_len; // triangle info


	//CriticalSection updateCriticalSection;


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
	}
};

bool BoundingCircleIntersects(const SimBody &a, const SimBody &b);