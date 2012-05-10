#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include "Collision.h"

World::World() : zoom(-3.45f), objects(0) {};
World::~World() { Unload(); };

typedef map<ArbiterKey, Arbiter>::iterator ArbIter;
typedef pair<ArbiterKey, Arbiter> ArbPair;
float2 gravity(0.0f, -10.0f);

void World::BroadPhase()
{
	// O(n^2) broad-phase
	for (int i = 0; i < firstTriangleIndex; ++i)
	{
		SimBody* bi = objects[i];

		for (int j = i + 1; j < (int)objects.size(); ++j)
		{
			SimBody* bj = objects[j];
			if(!bj->isbox) continue;

			/*if(!BoundingCircleHit(bi->position, bi->boundingCircleRadius, bj->position, bj->boundingCircleRadius))
			{
				continue;
			}*/
			
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

void World::OldUpdate(f64 dt)
{
	// We use the old SAT collision detection and response system for box-triangle and triangle-triangle
	// We only need to do triangle-Other checks here, dont run over the entire list of objects

	for(u32 i=firstTriangleIndex;i<objects.size();++i)
	{
		SimBody &obj = *objects[i];

		if(obj.Unmovable()) continue;

		obj.AddForce(float2((gravity.x), (gravity.y))*obj.mass);;
	}

	for(u32 i=firstTriangleIndex;i<total_cnt;++i)
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

	for(u32 i=firstTriangleIndex;i<objects.size();++i)
	{
		if(objects[i]->Unmovable()) continue;

		objects[i]->Update(dt);
	}
};

void World::Update(f64 dt)
{
	dt = min(dt,0.01f);

	double inv_dt = 1.0/dt;

	OldUpdate(dt);

	BroadPhase();

	for (int i = 0; i < firstTriangleIndex; ++i)
	{
		SimBody* b = objects[i];

		if (b->invMass == 0.0f)
			continue;

		b->velocity += dt * (gravity + b->invMass * b->force);
		b->angularVelocity += dt * b->invI * b->torque;
	}

	for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
	{
		arb->second.PreStep(inv_dt);
	}

	for (int i = 0; i < 20; ++i)
	{
		for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
		{
			arb->second.ApplyImpulse();
		}
	}

	for (int i = 0; i < firstTriangleIndex; ++i)
	{
		SimBody* b = objects[i];

		b->position += dt * b->velocity;
		b->rotation_in_rads += dt * b->angularVelocity;
		b->CalculateRotationMatrix();

		b->force.set(0.0f, 0.0f);
		b->torque = 0.0f;
	}
};

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

	for(int i=0;i<objects.size();++i)
	{
		objects[i]->Draw();
	}

	glPopMatrix();
};