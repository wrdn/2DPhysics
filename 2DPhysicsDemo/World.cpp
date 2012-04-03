#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
using namespace std;

World::World(void) : zoom(-3.45f) {}
World::~World(void) { UnLoad(); }

void World::Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	if(zoom <= 0.05f) zoom = 0.05f;
	glScalef(zoom,zoom,1);

	glTranslatef(cameraPosition.x(), cameraPosition.y(), 0);

	for(u32 i=0;i<1001;++i)
	{
		objects[i].fillMode = GL_LINE; // useful for debugging collision detection/response
		objects[i].Draw();
	}

	glPopMatrix();
};

float2 CurrentForce(const SimBody &s)
{
	float2 totalForce = s.force;
	totalForce += gravity*s.mass;
	return totalForce;
};
float2 CurrentForce(const float2 &pos, const float2 &vel, const SimBody &s)
{
	float2 totalForce = s.force;
	totalForce += gravity*s.mass;
	return totalForce;
};

void rkintegrate(SimBody &s, f32 dt)
{
	float2 acceleration = CurrentForce(s)/s.mass;

	float2 xk1, xk2, xk3, xk4;
	float2 vk1, vk2, vk3, vk4;

	// k1
	{
		xk1 = s.velocity * dt;
		vk1 = acceleration * dt;
	}

	// k2
	{
		float2 midvelocity = s.velocity + (vk1 * 0.5f);
		xk2 = midvelocity * dt;
		vk2 = (CurrentForce(s.position + (xk1 * 0.5f), midvelocity, s) / s.mass) * dt;
	}

	// k3
	{
		float2 midvelocity = s.velocity + (vk2 * 0.5f);
		xk3 = midvelocity * dt;
		vk3 = (CurrentForce(s.position + (xk2 * 0.5f), midvelocity, s) / s.mass) * dt;
	}

	// k4
	{
		float2 midvelocity = s.velocity + vk3;
		xk4 = midvelocity * dt;
		vk4 = (CurrentForce(s.position + xk3, midvelocity, s) / s.mass) * dt;
	}

	float2 xk2_2 = xk2*2.0f, xk3_2 = xk3*2.0f;
	float2 vk2_2 = vk2*2.0f, vk3_2 = vk3*2.0f;

	s.position += (xk1 + xk2_2 + xk3_2 + xk4) / 6.0f;
	s.velocity += (vk1 + vk2_2 + vk3_2 + vk4) / 6.0f;
};

void World::Update(f32 dt)
{
	dt = 0.0016f; // constant step size
	for(int i=0;i<1001;++i)
	{
		SimBody &body = objects[i];
		rkintegrate(body, dt);

		// HACK: make sure objects can't go below Y=0. We can now do collision detection to
		// make sure they don't penetrate each other, but also never go below Y=0
		// Later on we could add similar clamps for the X axis (left and right), and possibly an upper range for the Y
		// axis, so we can keep everything inside a box. Eventually, we will do proper collisions against a plane
		// so it can interact with the edges properly
		body.position.y( max(0, body.position.y()) );
	}
};