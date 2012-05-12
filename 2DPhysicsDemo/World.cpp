#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include "Collision.h"

World::World() : zoom(-3.45f), objects(0) {};
World::~World() { Unload(); };

typedef map<ArbiterKey, Arbiter>::iterator ArbIter;
typedef pair<ArbiterKey, Arbiter> ArbPair;
float2 gravity(0.0f, -10.0f);

CriticalSection broadPhaseCS;

void BroadPhaseTask(void *bp)
{
	World::BroadTask *bt = (World::BroadTask*)bp;

	vector<SimBody*> &bodies = *bt->bodies;

	SimBody *base = bt->baseBody;
	for(int i=bt->firstIndex;i<bt->lastIndex;++i)
	{
		SimBody *other = bodies[i]; //bt->bodies->at(i);
		//SimBody *other = bodyList[i];

		if(BoundingCircleHit(base->position, base->boundingCircleRadius, other->position, other->boundingCircleRadius))
		{
			if(base != other) // dont add object when testing against itself
			{
				//c.push_back(World::PotentiallyColliding(base,other));
				//c->push_back(World::PotentiallyColliding(base, other));
				//broadPhaseCS.Lock();
				bt->output_plist->push_back(World::PotentiallyColliding(base, other));
				//broadPhaseCS.Unlock();
			}
		}
	}
};

void World::ThreadedBroadPhase()
{
	// Step 1: Generate list of boxes we own
	bodies.clear();

	for(int i=0;i<firstTriangleIndex;++i)
	{
		if(objects[i]->isbox /* && we own it */)
		{
			bodies.push_back(objects[i]);
		}
	}

	static vector<World::PotentiallyColliding> list1(1000), list2(1000), list3(1000);

	for(u32 i=0;i<bodies.size();++i)
	{
		BroadTask bt; bt.bodies = &bodies; bt.baseBody = bodies[i]; bt.firstIndex = i+1; bt.lastIndex = 804-(i+1)/2; bt.output_plist = &list1;
		BroadTask bt2 = bt; bt2.firstIndex = 804-(i+1)/2; bt.lastIndex = 804; bt.output_plist = &list2;
		//BroadTask bt3 = bt; bt2.firstIndex = 536; bt.lastIndex = 804; bt.output_plist = &list3;
		
		BroadPhaseTask(&bt);
		BroadPhaseTask(&bt2);

		//physicsPool.AddTask(Task(BroadPhaseTask, &bt));
		//physicsPool.AddTask(Task(BroadPhaseTask, &bt2));
		//physicsPool.AddTask(Task(BroadPhaseTask, &bt3));
		
		physicsPool.FinishAllTasks();

		list1.clear();
		list2.clear();
		//list3.clear();
	}

	//u32 DESIRED_PER_THREAD_BP = 268; // each thread does broad phase for DESIRED_PER_THREAD_BP objects, tweak for best performance
	//u32 LEFT_OVER = bodies.size() % DESIRED_PER_THREAD_BP;
	//if(DESIRED_PER_THREAD_BP > bodies.size())
	//{
	//	DESIRED_PER_THREAD_BP = bodies.size();
	//	LEFT_OVER = 0;
	//}

	//// Step 2: For each body in the box list (outer loop)
	//for(u32 i=0;i<bodies.size();++i)
	//{
	//	potentialCollisions.clear();
	//	broadTasks.clear();

	//	int startPos = i+1;

	//	// Step 3: Generate list(s?) of potential collidables. Thread this to create multiple lists, then potentially accumulate
	//	u32 numTasks = (bodies.size()-i) / (DESIRED_PER_THREAD_BP - LEFT_OVER);
	//	for(u32 j=0;j<numTasks;++j)
	//	{
	//		BroadTask bt;
	//		bt.baseBody = bodies[i];//bodies.at(i);
	//		bt.bodies = &bodies;
	//		bt.output_plist = &potentialCollisions;
	//		bt.firstIndex = startPos+j*(DESIRED_PER_THREAD_BP-LEFT_OVER);
	//		bt.lastIndex = min(bt.firstIndex+(DESIRED_PER_THREAD_BP-LEFT_OVER), 804);

	//		broadTasks.push_back(bt);

	//		physicsPool.AddTask(Task(BroadPhaseTask, (void*)&broadTasks.back()));
	//	}
	//	physicsPool.FinishAllTasks(); // it seems to break if you put this line BELOW the if(LEFT_OVER) below

	//	// process the leftover ones
	//	if(LEFT_OVER)
	//	{
	//		//BroadTask bt; bt.baseBody = bodies[i]; bt.bodies = &bodies; bt.firstIndex = bodies.size()-LEFT_OVER; bt.lastIndex = bodies.size(); bt.output_plist = &potentialCollisions;
	//		BroadTask bt;
	//		bt.baseBody = bodies.at(i);
	//		bt.bodies = &bodies;
	//		bt.firstIndex = startPos;
	//		bt.lastIndex = min(bodies.size(), 804);
	//		bt.output_plist = &potentialCollisions;
	//		BroadPhaseTask(&bt);
	//	}
		
		//if(!potentialCollisions.size()) continue;
		// when we finish we'll have a list of all potentially colliding bodies (from bounding circle test)

		// Step 4: Find actual collisions
		/* Algorithm:
		*	- For each potential
				- Find contacts
				- If 0 contacts, add key to ERASE list
				- If >0 contacts
					- If arbiter exists, update its contacts
					- Else add it to ADD list

		* Notes: This algorithm is inherently threadable. We need locks when we add to ADD or ERASE list, otherwise no locks required
		* As with previous code, we should split it across threads, with each thread accepting N items. Dont give each thread 1 potential colliding object,
		* as thats slow. With multiple, the thread could build its own ADD/ERASE list, then when its finished append the entire list to the global list (faster than locking
		* the global list every time)
		*/
		//int DESIRED_POTENTIAL_COLLISION_PROCESSES_PER_THREAD = 5; // each thread should process 5 "potentials" at once to figure out if they actually collide. Tweak this for best performance
		//LEFT_OVER = DESIRED_POTENTIAL_COLLISION_PROCESSES_PER_THREAD % potentialCollisions.size();

	//};
};

void World::BroadPhase()
{
	static vector<PotentiallyColliding> potentialCollisions(250);
	potentialCollisions.clear();

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
			else if(bi != bj)
			{
				potentialCollisions.push_back(PotentiallyColliding(bi, bj));
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

			obj.Collide(other, (f32)dt);
		}
	}

	for(u32 i=firstTriangleIndex;i<objects.size();++i)
	{
		if(objects[i]->Unmovable()) continue;

		objects[i]->Update((f32)dt);
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

		b->position += (f32)dt * b->velocity;
		b->rotation_in_rads += (f32)dt * b->angularVelocity;
		b->CalculateRotationMatrix();

		b->force.zero();
		b->torque = 0;
	}
};
void TAddForces(void *integration_data)
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

		b->velocity += (f32)dt * (gravity + b->invMass * b->force);
		b->angularVelocity += (f32)dt * b->invI * b->torque;
	}
};

void World::IntegrateBoxForces(f64 dt)
{
	integration_data.clear();
	int numPerThread = 100; // should be a multiple of 1,2,5,10,20,25,50,100,200 or 400
	for(int i=0;i<firstTriangleIndex-4;i+=numPerThread) // 0 to 800
	{
		IntegrationData idt(i, i+numPerThread, dt, this);
		integration_data.push_back(idt);
		physicsPool.AddTask(Task(TAddForces, &integration_data.back()));
	}
	IntegrationData idt(firstTriangleIndex-4, firstTriangleIndex-1, dt, this);
	Integrate(&idt);
	physicsPool.FinishAllTasks();
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

	// wait for everything to finish for physics for this frame
	physicsPool.FinishAllTasks();
};

void World::Update(f64 dt)
{
	PerfTimer pt; PerfTimer ot=pt;
	ot.start();

	dt=0.02;

	//dt = max(dt, 0.001f);

	//dt = 1.0/80.0; // constant dt makes for a MUCH more stable simulation, with dynamic dt (default) the simulation sometimes explodes :( - maybe an issue with QueryPerformanceCounter???
	double inv_dt = 1.0f/dt;

	//double inv_dt = dt==0?0:1.0/dt;

	//pt.start();
	OldUpdate(dt);
	//pt.end();
	//cout << "Old Update Time: " << pt.time() << endl;

	//pt.start();
	BroadPhase();
	//pt.end();
	//cout << "No Threads: " << pt.time() << endl;

	//pt.start();
	//ThreadedBroadPhase();
	//pt.end();
	//cout << "Threaded: " << pt.time() << endl;

	IntegrateBoxForces(dt);

	//pt.start();
	for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
	{
		arb->second.PreStep((f32)inv_dt);
	}
	//pt.end();
	//cout << "Prestep time: " << pt.time() << endl;
	
	//pt.start();
	for (int i = 0; i < 10; ++i)
	{
		for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
		{
			arb->second.ApplyImpulse(); // this slows down SIGNIFICANTLY when put on multiple threads :(
		}
	}
	//pt.end();
	//cout << "Impulse Time: " << pt.time() << endl;

	IntegrateBoxes(dt);

	ot.end();
	cout << "Frame time: " << ot.time() << endl;
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