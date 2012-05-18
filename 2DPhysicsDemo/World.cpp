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

bool close(float2 &a, float2 &b)
{
	//Near: return val >= target-EPSILON && val <= target+EPSILON;

	const f32 CLOSE = 0.01f;
	if(a.x >= b.x - CLOSE && a.x <= b.x + CLOSE)
		if(a.y >= b.y - CLOSE && a.y <= b.y + CLOSE)
			return true;

	return false;
};

void World::object_ownership_updates(vector<unsigned short> &indices)
{
	
};

struct ObjectBlob { SimBody *b; int index; };

void World::Update(f64 dt)
{
	if(!alive)
		return;

	static float t_time = 0, f_time=0;
	static float owner_update_time = 0;

	PerfTimer pt; PerfTimer ot=pt;
	ot.start();

	dt=0.008f;

	bodies.clear();
	
	//arbiters.clear();

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

	// transform vertices into new positions (for every object we own)
	for(unsigned int i=0;i<objects.size();++i)
	{
		objects[i]->UpdateWorldSpaceProperties();
	}

	BroadPhase();
	
	double inv_dt = 1.0f/dt;
	for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
	{
		arb->second.PreStep((f32)inv_dt);
	}
	
	for (u32 i = 0; i < bodies.size(); ++i)
	{
		SimBody *b = bodies[i];
		if(b->invMass != 0)
		{
			b->velocity += (f32)dt * (gravity + b->invMass * b->force);
			b->angularVelocity += (f32)dt * b->invI * b->torque;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		for (ArbIter arb = arbiters.begin(); arb != arbiters.end(); ++arb)
		{
			arb->second.ApplyImpulse(); // this slows down SIGNIFICANTLY when put on multiple threads :(
		}
	}
	
	for (u32 i = 0; i < bodies.size(); ++i)
	{
		SimBody *b = bodies[i];
		
		b->position += (f32)dt * b->velocity;
		b->rotation_in_rads += (f32)dt * b->angularVelocity;
		b->CalculateRotationMatrix();

		b->force.zero();
		b->torque = 0;
	}

	ot.end();
	frameTime = ot.time();

	t_time += frameTime;
	f_time += frameTime;

	if(t_time > 0.0f && (netController->mode & NetworkController::Connected)
		&& (netController->mode & NetworkController::Simulating))
	{
		t_time = 0;
		
		// Calculate the update packets (for objects that have moved a "reasonable" amount)
		static vector<PositionOrientationUpdatePacket> updatePacks;
		updatePacks.clear();
		for(int j=4;j<objects.size();++j)
		{
			if(objects[j]->owner == SimBody::whoami)
			{
				if(!close(objects[j]->position, objects[j]->last_pos_sent))
				{
					PositionOrientationUpdatePacket pop;
					pop.Prepare(j, objects[j]->position, objects[j]->rotation_in_rads);
					updatePacks.push_back(pop);
					objects[j]->last_pos_sent = objects[j]->position;
				}
			}
		}

		// Calculate the ownership updates
		float minx = objects[4]->position.x; float maxx = minx; // get min and max x and midpoint (min+max)*0.5
		for(int i=5;i<objects.size();++i)
		{
			minx = min(objects[i]->position.x, minx);
			maxx = max(objects[i]->position.x, maxx);
		}
		const float midX = (minx + maxx) * 0.5f;
		static vector<ObjectBlob> L, R;
		L.clear(); R.clear();
		for(int i=4;i<objects.size();++i) // sort into a Left and Right list depending on side of midpoint the object lies on
		{
			if(objects[i]->owner != SimBody::whoami) continue;
			ObjectBlob blob; blob.b = objects[i]; blob.index = i;
			if(objects[i]->position.x < midX) L.push_back(blob);
			else R.push_back(blob);
		}
		
		// send items in list F to the other machine
		vector<ObjectBlob> &F = L.size()<R.size() ? L : R;

		const int other_machine = SimBody::whoami == 1 ? 2 : 1;

		// make a list of ownership packets ready to send
		vector<OwnershipUpdatePacket> opacks;
		for(int i=0;i<F.size();++i)
		{
			OwnershipUpdatePacket op; op.Prepare(F[i].index);
			//F[i].b->owner = other_machine;
			opacks.push_back(op);
		}

		// send the ownership update data
		int ownershipDataSize = sizeof(OwnershipUpdatePacket)*opacks.size();
		int ownershipAmountSent = 0;
		if(opacks.size())
		{
			//for(int i=0;i<opacks.size();++i) cout << opacks[i].Unprepare().objectIndex << "  ";
			//cout << endl;
			for(int i=0;i<netController->peers.size();++i)
			{
				/*while(ownershipAmountSent < ownershipDataSize)
				{
					ownershipAmountSent += send(netController->peers[i].socket, (char*)(&opacks[0]), ownershipDataSize, 0);
				}*/
			}
		}

		// send the position and orientation update data
		int dataSize = sizeof(PositionOrientationUpdatePacket)*updatePacks.size();
		int amountSent = 0;
		
		if(updatePacks.size())
		{
			for(int i=0;i<netController->peers.size();++i)
			{
				//cout << "Update pack size: " << updatePacks.size() << endl;
				while(amountSent < dataSize)
				{
					amountSent += send(netController->peers[i].socket, (char*)(&updatePacks[0]), dataSize, 0);
				}
			}
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

	glDisable(GL_DEPTH_TEST);

	for(int i=4;i<objects.size();++i)
	{
		SimBody &obj = *objects[i];

		glLineWidth(1.0f);

		float4 col = Color::RED;

		if(obj.velocity.length_squared() > 0.1f || obj.angularVelocity > 0.05f)
		{
			col = float4(1, 0.45, 0.6, 1);
		}

		glColor3fv(col.GetVec());
		glBegin(GL_LINE_LOOP);
		for(u32 i=0;i<obj.transformedVertices.size();++i)
		{
			glVertex2f(obj.transformedVertices[i].x, obj.transformedVertices[i].y);
		}
		glEnd();

		glLineWidth(1.0f);
	}
	glColor3f(1,1,1);

	glEnable(GL_DEPTH_TEST);

	glPopMatrix();
};