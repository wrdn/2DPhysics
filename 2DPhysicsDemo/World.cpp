#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include "Collision.h"
#include "chipCollide.h"

World::World() : zoom(-3.45f), objects(0), alive(true)
{
	physicsPaused = false;
	doOwnershipUpdates = false;
	springForce.zero();
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
	for (int i = 0; i < (int)bodies.size(); ++i)
	{
		SimBody* bi = bodies[i];

		for (int j = i + 1; j < (int)bodies.size(); ++j)
		{
			SimBody* bj = bodies[j];

			if(!BoundingCircleHit(bi->position, bi->boundingCircleRadius, bj->position, bj->boundingCircleRadius))
			{ continue; }


			if (bi->invMass == 0.0f && bj->invMass == 0.0f)
				continue;

			ArbiterKey key(bi, bj);
			Arbiter newArb = Collide::CollidePoly2Poly(bi, bj);

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

	const f32 CLOSE = 0.001f;
	if(a.x >= b.x - CLOSE && a.x <= b.x + CLOSE)
		if(a.y >= b.y - CLOSE && a.y <= b.y + CLOSE)
			return true;

	return false;
};

struct ObjectBlob { SimBody *b; int index; };

void sort(vector<ObjectBlob> &inp)
{
	bool swapped=false;
	int n = inp.size();

	do
	{
		swapped=false;
		for(int i=1;i<n;++i)
		{
			if(inp[i-1].b->position.x > inp[i].b->position.x)
			{
				std::swap(inp[i-1], inp[i]);
				swapped=true;
			}	
		}
		--n;
	} while(swapped);
};


void World::Update(f64 dt)
{
	if(!alive)
		return;

	static float t_time = 0, f_time=0;
	static float owner_update_time = 0;

	PerfTimer pt;
	PerfTimer ot=pt;
	ot.start();

	dt=0.016f;

	bodies.clear();

	if(mouseDown)
	{
		float sk=550;
		if(jointedBody)
		{
			SimBody *p = jointedBody;
			
			springForce = (float2(mx,my)-p->position)*dt*sk;
			
			p->velocity += springForce;
			p->velocity = p->velocity * 0.999f;
		}
	}

	if(netController->mode & NetworkController::Connected)
	{
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
			}
		}
	}
	else
	{
		bodies = objects;
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
		
		if(fabs(b->velocity.length_squared()) > 1000)
			b->velocity = b->velocity.normalize() * 15;
		if(fabs(b->angularVelocity) > 300)
			b->angularVelocity /= 20;

		b->position += (f32)dt * b->velocity;
		b->rotation_in_rads += (f32)dt * b->angularVelocity;

		b->force.zero();
		b->torque = 0;
	}

	ot.end();
	frameTime = ot.time();

	//printf("Frame Time: %f\n", frameTime);

	t_time += frameTime;
	f_time += frameTime;
	
	if(t_time > 0.0f && (netController->mode & NetworkController::Connected)
		&& (netController->mode & NetworkController::Simulating))
	{
		t_time = 0;
		
		int sentCount=0;
		
		static vector<OwnershipUpdatePacket> opacks;
		opacks.clear();
		if(doOwnershipUpdates)
		{
			/***************************************/
			/******* OBJECT MIGRATION PACKETS ******/
			/***************************************/
			static vector<ObjectBlob> sortedBodies;
			sortedBodies.clear();
			for(int i=4;i<objects.size();++i)
			{
				ObjectBlob b;
				b.b = objects[i];
				b.index=i;
				sortedBodies.push_back(b);
			}
			sort(sortedBodies);

			ObjectBlob *mid = &sortedBodies[sortedBodies.size()/2];
			vector<ObjectBlob*> onLeft, onRight;

			// make a list of objects we own on the left/right of mid
			for(int i=0;i<sortedBodies.size();++i)
			{
				ObjectBlob *blob = &sortedBodies[i];
				if(blob->b->owner != SimBody::whoami) continue;
				if(blob->b->position.x <= mid->b->position.x) onLeft.push_back(blob);
				else onRight.push_back(blob);
			}
			
			vector<ObjectBlob*> &listToSend = onLeft.size()>=onRight.size() ? onRight : onLeft;

			for(int i=0;i<listToSend.size();++i)
			{
				OwnershipUpdatePacket op;
				ObjectBlob &b = *listToSend[i];
				op.Prepare(b.index, b.b->velocity, b.b->angularVelocity);
				b.b->owner = b.b->owner == 1 ? 2 : 1;

				opacks.push_back(op);
			}
		}
		
		/**************************************/
		/********** UPDATE PACKETS ************/
		/**************************************/
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

					++sentCount;
				}
			}
		}
		
		/*********** SEND CAMERA UPDATE ***********/
		CameraUpdatePacket cap;
		cap.Prepare(mypvr.bl, mypvr.tr);
		int amountSent = 0;
		while(amountSent < sizeof(cap))
		{
			amountSent=0;
			for(int i=0;i<netController->peers.size();++i)
			{
				amountSent += send(netController->peers[i].socket, (char*)&cap, sizeof(cap),0);

				if(amountSent == -1)
				{
					amountSent = sizeof(cap);
					break;
				}
			}
		}

		/*************** SEND POSITION AND ORIENTATION UPDATES ***********/
		if(updatePacks.size())
		{
			int dataSize = sizeof(PositionOrientationUpdatePacket)*updatePacks.size();

			for(int i=0;i<netController->peers.size();++i)
			{
				amountSent = 0;

				//cout << "Update pack size: " << updatePacks.size() << endl;
				while(amountSent < dataSize)
				{
					amountSent += send(netController->peers[i].socket, (char*)(&updatePacks[0]), dataSize, 0);

					if(amountSent == -1)
					{
						amountSent = dataSize;
						break;
					}
				}
			}
		}


		/*********** SEND OBJECT MIGRATION UPDATES ****************/
		if(opacks.size())
		{
			int ownershipDataSize = sizeof(OwnershipUpdatePacket)*opacks.size();
			int ownershipAmountSent = 0;

			for(int i=0;i<netController->peers.size();++i)
			{
				ownershipAmountSent = 0;

				while(ownershipAmountSent < ownershipDataSize)
				{
					ownershipAmountSent += send(netController->peers[i].socket, (char*)(&opacks[0]), ownershipDataSize, 0);

					if(ownershipAmountSent == -1)
					{
						ownershipAmountSent = ownershipDataSize;
						break;
					}
				}
			}
		}
		
		numberOfObjectsSent = sentCount;
	} // end of if(t_time>0 ...)
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
			col = float4(0,1,1, 1);
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

	glColor3f(1,0,0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(mx, my);
	glEnd();
	glPointSize(1);

	if(jointedBody)
	{
		float2 pos = jointedBody->position;
		glBegin(GL_LINE_LOOP);
		glVertex2f(mx, my);
		glVertex2f(jointedBody->position.x, jointedBody->position.y);
		glEnd();

		glPointSize(2);
		glBegin(GL_POINTS);
		glVertex2f(jointedBody->position.x, jointedBody->position.y);
		glEnd();
		glPointSize(1);
	}

	if(netController->mode & NetworkController::Simulating)
	{
		// Draw the peer view rectangle
		glColor3f(0,0,1);
		glBegin(GL_LINE_LOOP);
		glVertex2f(pvr.bl.x, pvr.bl.y);
		glVertex2f(pvr.bl.x, pvr.tr.y);
		glVertex2f(pvr.tr.x, pvr.tr.y);
		glVertex2f(pvr.tr.x, pvr.bl.y);
		glEnd();
		glColor3f(1,1,1);
	}

	glPopMatrix();
};