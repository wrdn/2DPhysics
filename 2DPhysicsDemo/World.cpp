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

			if(!BoundingCircleHit(bi->position, bi->boundingCircleRadius, bj->position, bj->boundingCircleRadius))
			{
				continue;
			}
			
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

			if(!BoundingCircleHit(obj.position, obj.boundingCircleRadius, objects[i]->position, objects[i]->boundingCircleRadius))
			{
				continue;
			}

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

void Integrate(void *integration_data)
{
	World::IntegrationData *idata = (World::IntegrationData*)integration_data;

	int firstIndex = idata->firstindex;
	int lastIndex = idata->lastindex;
	f64 dt = idata->dt;
	World *w = idata->w;

	// update all the objects between firstIndex and lastIndex
	for (int i = firstIndex; i < lastIndex; ++i)
	{
		SimBody *b = w->objects[i];

		b->position += dt * b->velocity;
		b->rotation_in_rads += dt * b->angularVelocity;
		b->CalculateRotationMatrix();

		b->force.zero();
		b->torque = 0;
	}
};

void World::IntegrateBoxes(f64 dt)
{
	// This is thread safe as objects are updated without changing other objects. Therefore we can thread the update to
	// put it on as many as we want. We can tweak the value to update per thread but it should be fairly large (maybe ~100 a time?)
	// as the process is very fast
	integration_data.clear();
	int numPerThread = 100; // should be a multiple of 1,2,5,10,20,25,50,100,200 or 400
	for(int i=0;i<firstTriangleIndex-4;i+=numPerThread) // 0 to 800
	{
		IntegrationData idt(i, i+numPerThread, dt, this);
		integration_data.push_back(idt);
		physicsPool.AddTask(Task(Integrate, &integration_data.back()));
	}
	IntegrationData idt(firstTriangleIndex-4, firstTriangleIndex-1, dt, this);
	Integrate(&idt);
	while(physicsPool.TasksAvailable()); // wait for everything to finish for physics for this frame
};

void World::Update(f64 dt)
{
	dt=0.016;

	//dt = max(dt, 0.001f);

	//dt = 1.0/80.0; // constant dt makes for a MUCH more stable simulation, with dynamic dt (default) the simulation sometimes explodes :( - maybe an issue with QueryPerformanceCounter???
	double inv_dt = 1.0f/dt;

	//double inv_dt = dt==0?0:1.0/dt;

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

	for (int i = 0; i < 10; ++i)
	{
		for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
		{
			arb->second.ApplyImpulse();
		}
	}
	
	IntegrateBoxes(dt);
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

	for(u32 i=0;i<objects.size();++i)
	{
		objects[i]->Draw();
	}

	glPopMatrix();
};