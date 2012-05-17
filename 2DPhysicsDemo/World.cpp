#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include "Collision.h"
#include "chipCollide.h"

World::World() : zoom(-3.45f), objects(0), alive(true)
{
	physicsPaused = false;
};

World::~World()
{
	Unload();
};

typedef map<ArbiterKey, Arbiter>::iterator ArbIter;
typedef pair<ArbiterKey, Arbiter> ArbPair;
float2 gravity(0.0f, -10.0f);

CriticalSection broadPhaseCS;

void BroadPhaseTask(void *bp)
{
	World::BroadTask *bt = (World::BroadTask*)bp;

	vector<SimBody*> *bodies = bt->bodies;

	SimBody *base = bt->baseBody;
	for(int i=bt->firstIndex;i<bt->lastIndex;++i)
	{
		SimBody *other = bodies->at(i);;
		
		if(base == other) continue;
		if(base->invMass == 0 && other->invMass == 0) continue;

		if(BoundingCircleHit(base->position, base->boundingCircleRadius,
			other->position, other->boundingCircleRadius))
		{
			bt->output_plist->push_back(World::PotentiallyColliding(base, other));
		}
	}
};

struct Arbiter_ADD
{
	Arbiter arb;
	ArbiterKey arbKey;

	Arbiter_ADD(Arbiter &_arb, ArbiterKey &akey)
		: arb(_arb), arbKey(akey)
	{
	};
};
struct Arbiter_ERASE
{
	ArbiterKey arbKey;

	Arbiter_ERASE(const ArbiterKey &akey)
		: arbKey(akey) {};
};

struct ContactFinder
{
	vector<World::PotentiallyColliding> *potentials;
	int first,last;
	vector<Arbiter_ADD> *addList;
	vector<Arbiter_ERASE> *eraseList;
	map<ArbiterKey, Arbiter> *_arbiters;
};
void FindContacts_Threaded(void *fc)
{
	static CriticalSection cs;

	ContactFinder *cf = (ContactFinder*)fc;

	map<ArbiterKey, Arbiter> &arbitersf = *cf->_arbiters;

	cf->last = min(cf->last, (i32)cf->potentials->size());

	for(int i=cf->first;i<cf->last;++i)
	{
		World::PotentiallyColliding pc = cf->potentials->at(i);

		Arbiter arb(pc.body1, pc.body2);
		ArbiterKey arbKey(pc.body1, pc.body2);

		if(arb.DoCollision())
		{
			ArbIter iter = arbitersf.find(arbKey);
			if(iter != arbitersf.end())
			{
				iter->second.Update(arb.contacts, arb.numContacts);
			}
			else
			{
				cs.Lock();
				cf->addList->push_back(Arbiter_ADD(arb, arbKey));
				cs.Unlock();
			}
		}
		else
		{
			cs.Lock();
			cf->eraseList->push_back(Arbiter_ERASE(arbKey));
			cs.Unlock();
		}
	}
};
void FindContacts_Single(void *fc)
{
	ContactFinder *cf = (ContactFinder*)fc;

	map<ArbiterKey, Arbiter> &arbitersf = *cf->_arbiters;

	cf->last = min(cf->last, (i32)cf->potentials->size());

	for(int i=cf->first;i<cf->last;++i)
	{
		World::PotentiallyColliding pc = cf->potentials->at(i);

		//Arbiter arb(pc.body1, pc.body2);
		Arbiter arb(pc.body1, pc.body2);
		ArbiterKey arbKey(pc.body1, pc.body2);

		if(arb.DoCollision())
		{
			ArbIter iter = arbitersf.find(arbKey);
			if(iter != arbitersf.end())
			{
				iter->second.Update(arb.contacts, arb.numContacts);
			}
			else
			{
				cf->addList->push_back(Arbiter_ADD(arb, arbKey));
			}
		}
		else
		{
			cf->eraseList->push_back(Arbiter_ERASE(arbKey));
		}
	}
};

void World::BroadPhase()
{
	// Step 1: Generate list of boxes we own, currently no point as no networking
	//bodies.clear();
	//bodies = objects;

	//for(int i=0;i<objects.size();++i)
	//{
	//	if(objects[i]->isbox)
	//	{
	//		bodies.push_back(objects[i]);
	//	}
	//}

	static vector<PotentiallyColliding> potentials;
	static vector<Arbiter_ADD> ADD_LIST;
	static vector<Arbiter_ERASE> ERASE_LIST;

	static ContactFinder finders[10000];
	int numFinders=0;

	// Note: This is currently just processing up to the first triangle (i.e. boxes only). Change this later for triangles also (if we port Chipmunk)
	for(u32 i=0;i<bodies.size();++i)
	{
		// Get potential collisions (bounding circle tests)
		potentials.clear();
		
		// This code runs extremely quickly. Dont bother to thread it as you wont see any benefits (and may get a performance hit!)
		// A possible improvement to the codebase would be to move positions and bounding circle radius' into their own arrays so we
		// get good cache performance
		BroadTask bt; bt.bodies = &bodies; bt.baseBody = bodies[i];
		bt.output_plist = &potentials;
		bt.firstIndex = i+1;
		bt.lastIndex = bodies.size();
		//bt.lastIndex = objects.size();
		BroadPhaseTask(&bt);

		if(!potentials.size()) continue;

		ADD_LIST.clear(); ERASE_LIST.clear();
		ContactFinder *n = &finders[numFinders];
		++numFinders;

		n->addList = &ADD_LIST;
		n->eraseList = &ERASE_LIST;
		n->_arbiters = &arbiters;
		n->potentials = &potentials;

		n->first = 0;
		n->last = potentials.size();

		FindContacts_Single(n);
		
		// Add/Remove arbiters from add/remove list
		for(u32 i=0;i<ERASE_LIST.size();++i) arbiters.erase(ERASE_LIST[i].arbKey);
		for(u32 i=0;i<ADD_LIST.size();++i) arbiters.insert(ArbPair(ADD_LIST[i].arbKey, ADD_LIST[i].arb));
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
			if(!BoundingCircleHit(obj.position, obj.boundingCircleRadius, objects[i]->position, objects[i]->boundingCircleRadius)) continue;
			if(i==j) continue;

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
	/*integration_data.clear();
	int numPerThread = 100; // should be a multiple of 1,2,5,10,20,25,50,100,200 or 400
	for(int i=0;i<firstTriangleIndex-4;i+=numPerThread) // 0 to 800
	{
		IntegrationData idt(i, i+numPerThread, dt, this);
		integration_data.push_back(idt);
		physicsPool->AddTask(Task(TAddForces, &integration_data.back()));
	}*/
	IntegrationData idt(0, firstTriangleIndex, dt, this);
	Integrate(&idt);
	//physicsPool->FinishAllTasks();
};

void World::IntegrateBoxes(f64 dt)
{
	// This is thread safe as objects are updated without changing other objects. Therefore we can thread the update to
	// put it on as many as we want. We can tweak the value to update per thread but it should be fairly large (maybe ~100 a time?)
	// as the process is very fast
	//integration_data.clear();
	/*int numPerThread = 100; // should be a multiple of 1,2,5,10,20,25,50,100,200 or 400
	for(int i=0;i<firstTriangleIndex-4;i+=numPerThread) // 0 to 800
	{
		IntegrationData idt(i, i+numPerThread, dt, this);
		integration_data.push_back(idt);
		physicsPool->AddTask(Task(Integrate, &integration_data.back()));
	}*/
	IntegrationData idt(0, firstTriangleIndex, dt, this);
	Integrate(&idt);

	// wait for everything to finish for physics for this frame
	//physicsPool->FinishAllTasks();
};

void World::Update(f64 dt)
{
	if(!alive)
		return;
	
	PerfTimer pt; PerfTimer ot=pt;
	ot.start();

	//dt = gt->Update();
	//dt = min(dt, 0.016); // keep dt in check, too big and bad stuff happens :(
	//dt = 0.0005f;

	dt=0.016f;

	bodies.clear();
	
	vector<unsigned short> indices; // has an element for each body in bodies, used so we can send the correct data over the network (updating the right index on the other side)

	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(3);

	// everyone owns the walls
	bodies.push_back(objects[0]);
	bodies.push_back(objects[1]);
	bodies.push_back(objects[2]);
	bodies.push_back(objects[3]);

	for(unsigned int i=4;i<objects.size();++i)
	{
		if(objects[i]->owner == SimBody::whoami)
		{
			bodies.push_back(objects[i]);
			indices.push_back(i);
		}
	}

	//cout << bodies.size() << endl;

	// transform vertices into new positions (for every object we own)
	for(unsigned int i=0;i<objects.size();++i)
	{
		objects[i]->UpdateWorldSpaceProperties();
	}

	//dt = max(dt, 0.001f);

	//dt = 1.0/80.0; // constant dt makes for a MUCH more stable simulation, with dynamic dt (default) the simulation sometimes explodes :( - maybe an issue with QueryPerformanceCounter???
	double inv_dt = 1.0f/dt;

	//double inv_dt = dt==0?0:1.0/dt;

	//OldUpdate(dt);

	//pt.start();
	BroadPhase();
	//pt.end();
	//cout << "Threaded: " << pt.time() << endl;

	//IntegrateBoxForces(dt);
	for (u32 i = 0; i < bodies.size(); ++i)
	{
		SimBody *b = bodies[i];
		if(b->invMass != 0)
		{
			b->velocity += (f32)dt * (gravity + b->invMass * b->force);
			b->angularVelocity += (f32)dt * b->invI * b->torque;
		}
	}

	//pt.start();
	for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
	{
		arb->second.PreStep((f32)inv_dt);
	}
	//pt.end();
	//cout << "Prestep time: " << pt.time() << endl;
	
	//pt.start();
	for (int i = 0; i < 15; ++i)
	{
		for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
		{
			arb->second.ApplyImpulse(); // this slows down SIGNIFICANTLY when put on multiple threads :(
		}
	}
	//pt.end();
	//cout << "Impulse Time: " << pt.time() << endl;

	for (u32 i = 0; i < bodies.size(); ++i)
	{
		SimBody *b = bodies[i];
		//if(!b->isbox) continue;

		b->position += (f32)dt * b->velocity;
		b->rotation_in_rads += (f32)dt * b->angularVelocity;
		b->CalculateRotationMatrix();

		b->force.zero();
		b->torque = 0;
	}

	//IntegrateBoxes(dt);

	ot.end();
	frameTime = ot.time();

	if(netController->mode & NetworkController::Connected)
	{
		for(int i=0;i<=netController->fdmax;++i)
		{
			PositionOrientationUpdatePacket pop;
			pop.Prepare(1, float2(0,80), 0);
			send(i, (char*)&pop, sizeof(pop), 0);
		}
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

	for(u32 i=0;i<objects.size();++i)
	{
		objects[i]->Draw();
	}

	glPopMatrix();
};