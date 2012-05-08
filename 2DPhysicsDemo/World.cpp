#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"

//typedef map<PhysArbiterKey, PhysArbiter>::iterator ArbIter;
//typedef pair<PhysArbiterKey, PhysArbiter> ArbPair;

World::World() : zoom(-3.45f), objects(0) {};
World::~World() { Unload(); };

typedef map<ArbiterKey, Arbiter>::iterator ArbIter;
typedef pair<ArbiterKey, Arbiter> ArbPair;
void World::BroadPhase()
{
	// O(n^2) broad-phase
	for (int i = 0; i < (int)bodies.size(); ++i)
	{
		Body* bi = bodies[i];

		for (int j = i + 1; j < (int)bodies.size(); ++j)
		{
			Body* bj = bodies[j];

			if (bi->invMass == 0.0f && bj->invMass == 0.0f)
				continue;

			Arbiter newArb(bi, bj);
			ArbiterKey key(bi, bj);

			if (newArb.numContacts > 0)
			{
				ArbIter iter = arbiters.find(key);
				if (iter == arbiters.end())
				{
					arbiters.insert(ArbPair(key, newArb));
				}
				else
				{
					iter->second.Update(newArb.contacts, newArb.numContacts);
				}
			}
			else
			{
				arbiters.erase(key);
			}
		}
	}
};

Vector2f gravity(0.0f, -10.0f);
void World::Update(f64 dt)
{
	float inv_dt = dt > 0.0f ? 1.0f / dt : 0.0f;

	BroadPhase();

	for (int i = 0; i < (int)bodies.size(); ++i)
	{
		Body* b = bodies[i];

		if (b->invMass == 0.0f)
			continue;

		b->velocity += dt * (gravity + b->invMass * b->force);
		b->angularVelocity += dt * b->invI * b->torque;
	}

	for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
	{
		arb->second.PreStep(inv_dt);
	}

	for (int i = 0; i < 10; ++i)
	{
		for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
		{
			arb->second.ApplyImpulse();
		}
	}

	for (int i = 0; i < (int)bodies.size(); ++i)
	{
		Body* b = bodies[i];

		b->position += dt * b->velocity;
		b->rotation += dt * b->angularVelocity;

		b->force.Set(0.0f, 0.0f);
		b->torque = 0.0f;
	}
}

void World::Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glScalef(zoom,zoom,1);
	glTranslatef(camPos.x, camPos.y, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	{ // bottom wall
		const SimBody &wall = *objects[0];
		DrawLine(wall.position+wall.vertices[0], wall.position+wall.vertices[1], 1,0,0,2.0f);
	}
	{ // left wall
		const SimBody &wall = *objects[1];
		DrawLine(wall.position+wall.vertices[0], wall.position+wall.vertices[1], 1,0,0,2.0f);
	}
	{ // right wall
		const SimBody &wall = *objects[2];
		DrawLine(wall.position+wall.vertices[0], wall.position+wall.vertices[1], 1,0,0,2.0f);
	}
	{ // top wall
		const SimBody &wall = *objects[3];
		DrawLine(wall.position+wall.vertices[0], wall.position+wall.vertices[1], 1,0,0,2.0f);
	}

	//DrawLine(objects[0]->vertices[0], objects[0]->vertices[1], 1,0,0,2.0f);

	for(int i=0;i<bodies.size();++i)
		bodies[i]->Draw();

	glPopMatrix();
};

/*
void World::BroadPhase()
{
	Mat22 test = Mat22::RotationMatrix(10);

	for (int i = 0; i < (int)bodies.size(); ++i)
	{
		Body* bi = bodies[i];

		for (int j = i + 1; j < (int)bodies.size(); ++j)
		{
			Body* bj = bodies[j];

			if (bi->invMass == 0.0f && bj->invMass == 0.0f)
				continue;

			PhysArbiter newArb(bi, bj);
			PhysArbiterKey key(bi, bj);

			if (newArb.numContacts > 0)
			{
				ArbIter iter = arbiters.find(key);
				if (iter == arbiters.end())
				{
					arbiters.insert(ArbPair(key, newArb));
				}
				else
				{
					iter->second.Update(newArb.contacts, newArb.numContacts);
				}
			}
			else
			{
				arbiters.erase(key);
			}
		}
	}
};
*/

/*
void World::Update(f64 dt)
{
	//dt = min(dt, 0.005f);
	//const float2 &gravity = SimBody::gravity;
	//float2 gravity(0,-9.81f);
	float2 gravity(0,-10);

	dt = 1.0f/250.0f;

	float inv_dt = 1.0f/dt;

	arbiters.clear();
	BroadPhase();

	for (int i = 0; i < (int)bodies.size(); ++i)
	{
		Body* b = bodies[i];

		if (b->invMass == 0.0f)
			continue;

		b->velocity += (gravity + b->force*b->invMass)*dt;
		b->angularVelocity += dt * b->invInertia * b->torque;
	}

	for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
	{
		arb->second.PreStep(inv_dt);
	}

	for (int i = 0; i < 10; ++i)
	{
		for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
		{
			arb->second.ApplyImpulse();
		}
	}

	for (int i = 0; i < (int)bodies.size(); ++i)
	{
		Body* b = bodies[i];

		b->pos += b->velocity*dt;
		b->rotation += b->angularVelocity*dt;

		b->force.set(0.0f, 0.0f);
		b->torque = 0.0f;
	}

	return;
	arbiters.clear();
	// Broad phase
	for(int i=0;i<bodies.size();++i)
	{
		Body *bi = bodies[i];

		for(int j=i+1;j<bodies.size();++j)
		{
			Body* bj = bodies[j];

			if(NearZero(bi->invMass) && NearZero(bj->invMass)) continue;

			PhysArbiter newArb(bi, bj);
			newArb.numContacts = BoxCollide(newArb.contacts, bi, bj);
			PhysArbiterKey key(bi, bj);

			if(newArb.numContacts > 0)
			{
				map<PhysArbiterKey, PhysArbiter>::iterator it;
				it = arbiters.find(key);
				if(it == arbiters.end())
				{
					arbiters.insert(ArbPair(key, newArb));
				}
				else
				{
					it->second.Update(newArb.contacts, newArb.numContacts);
				}
			}
			else
			{
				arbiters.erase(key);
			}
		}
	}
	// End of broad phase


	for (int i = 0; i < (int)bodies.size(); ++i)
	{
		Body* b = bodies[i];

		if (NearZero(b->invMass))
			continue;

		b->velocity += (gravity + b->force*b->invMass)*dt;
		b->angularVelocity += dt * b->invInertia * b->torque;
	}

	for(ArbIter arb=arbiters.begin();arb!=arbiters.end();++arb)
	{
		arb->second.PreStep(1.0f/dt);
	}
	
	for (int i = 0; i < 1; ++i)
	{
		for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
		{
			arb->second.ApplyImpulse();
		}
	}

	for (int i = 0; i < (int)bodies.size(); ++i)
	{
		Body* b = bodies[i];

		b->pos += b->velocity*dt;
		b->rotation += dt * b->angularVelocity;
		b->force.set(0);
		b->torque=0;
	};
	return;

	for(u32 i=0;i<total_cnt;++i)
	{
		SimBody &obj = *objects[i];

		if(obj.Unmovable()) continue;

		obj.AddForce(float2((gravity.x), (gravity.y))*obj.mass);;
	}

	for(u32 i=0;i<total_cnt;++i)
	{
		SimBody &obj = *objects[i];

		for(u32 j=0;j<total_cnt;++j)
		{
			if(i==j) continue;

			SimBody &other = *objects[j];

			if(obj.Unmovable() && other.Unmovable()) continue;

			obj.Collide(other, dt);
		}
	}

	for(u32 i=0;i<total_cnt;++i)
	{
		if(objects[i]->Unmovable()) continue;

		objects[i]->Update(dt);
	}
};
*/