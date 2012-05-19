#include "World.h"
#include "GraphicsUtils.h"
#include <time.h>
#include "SAT.h"

// returns most tight fitting circle you can get given a set of vertices and a center position for the circle
// used to get bounding circle for box and triangle (given their vertices and center positions)
f32 CalculateBoundingCircle(const float2 &center, const float2 *verts, const u32 vertexCount)
{
	if(!verts) return 0;

	f32 rlensqr = (verts[0] - center).length_squared();
	for(u32 i=1;i<vertexCount;++i)
	{
		rlensqr = max(rlensqr, (verts[i]-center).length_squared());
	}
	return sqrtf(rlensqr);
};

void World::Unload()
{
	if(physicsPool)
		physicsPool->SigKill();

	ResourceManager::get().Cleanup();
	CleanupVector(objects);
	arbiters.clear();
}

void World::CreateBoxes()
{
	f32 box_width  = meters(conf.Read("BoxWidth"  , 1.0f));
	f32 box_height = meters(conf.Read("BoxHeight" , 1.0f));
	f32 xOffset = conf.Read("BoxXOffset", 0.003f);
	f32 yOffset = conf.Read("BoxYOffset", 0.003f);
	MeshHandle boxMesh = Create2DBox(box_width, box_height);

	box_row_cnt = conf.Read("BoxRowCount", 32U);
	box_col_cnt = conf.Read("BoxColumnCount", 25U);
	box_cnt = box_row_cnt * box_col_cnt;
	u32 th = box_cnt / 3;
	i32 massCounts[] = { th, th, th + box_cnt%3 };
	assert(massCounts[0]+massCounts[1]+massCounts[2] >= (i32)box_cnt);

	SimBody baseBox;
	baseBox.mesh = boxMesh;
	baseBox.width.set(box_width, box_height);
	baseBox.objectMaterial.SetObjectColor(Color::RED);
	//baseBox.objectMaterial.AddTexture(mass_textures[0]);
	baseBox.mass = 200; baseBox.invMass = 1.0f/200.0f;
	baseBox.rotation_in_rads = 0; baseBox.CalculateRotationMatrix();
	baseBox.MakeBox(box_width, box_height);
	baseBox.UpdateWorldSpaceProperties();
	baseBox.boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &baseBox.vertices[0], baseBox.vertices.size());
	baseBox.side_len = 1;

	float startX = meters(-80);
	float startY=meters(0.45f);

	int lastIndex = !objects.size() ? 0 : objects.back()->hashid;

	// Generate boxes
	for(u32 i=0;i<box_row_cnt;++i)
	{
		for(u32 j=0;j<box_col_cnt;++j)
		{
			SimBody *b = new SimBody(baseBox);
			b->hashid = ++lastIndex;

			b->position.set(startX+(j*box_width)+(j*xOffset), startY+(i*box_height)+(i*yOffset));

			i32 t = 0;
			while(!massCounts[t=rand(0,2)]);

			//b->rotation_in_rads = randflt(-TWOPI, TWOPI);
			//b->CalculateRotationMatrix();

			b->objectMaterial.AddTexture(mass_textures[t]);

			b->mass = masses[t];
			b->invMass = invMasses[t];

			b->CalculateInertia();

			//b->position.x += randflt(0, 0.8f);

			b->side_len = 0;
			b->last_pos_sent.zero();
			b->last_rotation_sent = 0;

			b->fillMode = GL_FILL;

			b->side_len = 1;

			b->friction = 0.6f;

			objects.push_back(b);
		}
	}
};

void World::GeneratePyramid(int levels, const float2 &startPos)
{
	SimBody triangle;
	triangle.friction = 0.8f;
	triangle.rotation_in_rads = 0; triangle.CalculateRotationMatrix();
	triangle.objectMaterial.SetObjectColor(Color::RED);
	triangle.objectMaterial.AddTexture(mass_textures[0]);
	triangle.mass = 20; triangle.invMass = 20;
	triangle.MakeTriangle(1);
	triangle.boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &triangle.vertices[0], triangle.vertices.size());

	for(int row=levels;row>=0;--row) // for each row of the pyramid
	{
		float2 rowStartPos = startPos + (levels-row)*0.5f;

		// generate triangles facing upwards
		for(int i=0;i<row;++i)
		{
		}
	}
};

void World::CreateTriangles()
{
	masses[0] = masses[1] = masses[2] = 20;
	invMasses[0] = invMasses[1] = invMasses[2] = 1.0f/masses[0];

	f32 triangle_len = meters(conf.Read("TriangleLength", 1.0f));
	MeshHandle triMesh = CreateEquilateralTriangle(triangle_len);
	
	SimBody baseTriangle;
	baseTriangle.hashid = ++SimBody::GUID_GEN;
	baseTriangle.friction = 0.8f;
	baseTriangle.mesh = triMesh;
	baseTriangle.rotation_in_rads = 0;
	baseTriangle.CalculateRotationMatrix();
	baseTriangle.objectMaterial.SetObjectColor(Color::RED);
	baseTriangle.objectMaterial.AddTexture(mass_textures[0]);
	baseTriangle.mass = 20; baseTriangle.invMass = 1.0f/20.0f;
	baseTriangle.owner = 1;
	baseTriangle.side_len = triangle_len/2;
	{
		float SL = baseTriangle.side_len;
		baseTriangle.vertices.push_back(float2(0, SL));
		baseTriangle.vertices.push_back(float2(SL, -SL));
		baseTriangle.vertices.push_back(float2(-SL, -SL));
	}
	SAT::GenerateSeperatingAxes(baseTriangle.vertices, baseTriangle.seperatingAxis);
	baseTriangle.boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &baseTriangle.vertices[0], baseTriangle.vertices.size());
	baseTriangle.isbox=true;
	baseTriangle.MakeTriangle(triangle_len);

	float startX = meters(-15);
	float startY = 11.5;

	{
		float triXSeperation = 0.5f;
		float triYSeperation = 0.866f;
		float pyramidXSeperation = 20;
		int rowCount = 19;
		int rowNum = 0;
		int rowRemain = rowCount;


		for(int i=0;i<100;++i)
		{
			SimBody *tri = new SimBody(baseTriangle);
			tri->hashid = ++SimBody::GUID_GEN;
			int t = rand(0,2);
			tri->position.set(startX+(1.0f*i), startY);
			tri->rotation_in_rads = 0;
			tri->CalculateRotationMatrix();
			tri->mass = masses[t];
			tri->invMass = invMasses[t];
			tri->CalculateInertia();
			tri->fillMode = GL_FILL;
			tri->position.x += (i * 0.2f);

			float orientation = (i+rowNum)%2;
			tri->rotation_in_rads = DEGTORAD(180*orientation);

			tri->position.set(
				-30+(i)%160*triXSeperation-20-triXSeperation*19*
				rowNum+triXSeperation*rowNum*rowNum,
				50+triYSeperation*rowNum-44.711+0.288*orientation);

			tri->position.x ;
			tri->position.y ;

			if(--rowRemain < 1)
			{
				rowCount -= 2;
				rowRemain = rowCount;
				rowNum = 9-(rowCount/2);
			}

			tri->boundingCircleRadius = CalculateBoundingCircle(tri->position, &tri->vertices[0], tri->vertices.size());

			tri->UpdateWorldSpaceProperties();
			objects.push_back(tri);
		}
	}

	{
		float triXSeperation = 0.5f;
		float triYSeperation = 0.866f;
		float pyramidXSeperation = 20;
		int rowCount = 19;
		int rowNum = 0;
		int rowRemain = rowCount;


		for(int i=0;i<100;++i)
		{
			SimBody *tri = new SimBody(baseTriangle);
			tri->hashid = ++SimBody::GUID_GEN;
			int t = rand(0,2);
			tri->position.set(startX+(1.0f*i), startY);
			tri->rotation_in_rads = 0;
			tri->CalculateRotationMatrix();
			tri->mass = masses[t];
			tri->invMass = invMasses[t];
			tri->CalculateInertia();
			tri->fillMode = GL_FILL;
			tri->position.x += (i * 0.2f);

			float orientation = (i+rowNum)%2;
			tri->rotation_in_rads = DEGTORAD(180*orientation);

			tri->position.set(
				60+(i)%160*triXSeperation-20-triXSeperation*19*
				rowNum+triXSeperation*rowNum*rowNum,
				50+triYSeperation*rowNum-44.711+0.288*orientation);

			tri->position.x ;
			tri->position.y ;

			if(--rowRemain < 1)
			{
				rowCount -= 2;
				rowRemain = rowCount;
				rowNum = 9-(rowCount/2);
			}

			tri->boundingCircleRadius = CalculateBoundingCircle(tri->position, &tri->vertices[0], tri->vertices.size());

			tri->UpdateWorldSpaceProperties();
			objects.push_back(tri);
		}
	}



	return;














	// First row
	for(int i=0;i<2;++i)
	{
		SimBody *tri = new SimBody(baseTriangle);
		tri->hashid = ++SimBody::GUID_GEN;
		int t = rand(0,2);
		tri->position.set(startX+(1.0f*i), startY);
		tri->rotation_in_rads = 0;
		tri->CalculateRotationMatrix();
		tri->mass = masses[t];
		tri->invMass = invMasses[t];
		tri->CalculateInertia();
		tri->fillMode = GL_FILL;
		tri->position.x += (i * 0.2f);
		tri->UpdateWorldSpaceProperties();
		objects.push_back(tri);
	}

	/*startX = meters(-15);
	for(int i=0;i<9;++i)
	{
		SimBody *tri = new SimBody(baseTriangle);
		int t = rand(0,2);
		tri->position.set(startX+(1.0f*i), startY);
		tri->rotation_in_rads=PI;
		tri->CalculateRotationMatrix();
		tri->mass = masses[t];
		tri->invMass = invMasses[t];
		tri->CalculateInertia();
		tri->fillMode = GL_LINE;
		objects.push_back(tri);
	}
	
	
	// Second row
	startX = meters(-15) - 0.1f;
	startY += 1;
	for(int i=0;i<9;++i)
	{
		SimBody *tri = new SimBody(baseTriangle);
		int t = rand(0,2);
		tri->position.set(startX+(1.0f*i), startY);
		tri->rotation_in_rads=0;
		tri->CalculateRotationMatrix();
		tri->mass = masses[t];
		tri->invMass = invMasses[t];
		tri->CalculateInertia();
		tri->fillMode = GL_LINE;
		objects.push_back(tri);
	}
	*/
};

void World::CreateWalls()
{
	MeshHandle meshHandle = Create2DBox(1,1);

	SimBody *bottomBox = new SimBody();
	bottomBox->boundingCircleRadius = 500;
	bottomBox->mesh = meshHandle;
	//bottomBox->mesh = objects.back()->mesh;
	bottomBox->width.set(meters(200), -5);
	bottomBox->position.set(0, 0);
	bottomBox->fillMode = GL_LINE;
	//bottomBox->position.y = -10;
	bottomBox->objectMaterial.SetObjectColor(Color::RED);
	bottomBox->objectMaterial.AddTexture(mass_textures[0]);
	bottomBox->mass = 0; bottomBox->invMass = 0;
	bottomBox->inertia = 0; bottomBox->invInertia = 0; bottomBox->I = 0; bottomBox->invI = 0;
	bottomBox->rotation_in_rads = 0; bottomBox->CalculateRotationMatrix();
	{
		const float2 &extents = bottomBox->width/2;
		bottomBox->vertices.push_back(float2(-extents.x, -extents.y));
		bottomBox->vertices.push_back(float2(extents.x, -extents.y));
		bottomBox->vertices.push_back(float2(extents.x, extents.y));
		bottomBox->vertices.push_back(float2(-extents.x, extents.y));
	}
	SAT::GenerateSeperatingAxes(bottomBox->vertices, bottomBox->seperatingAxis);

	bottomBox->angularVelocity = 0;
	bottomBox->density = 0;
	bottomBox->force.zero();
	bottomBox->friction = 0.75f;
	bottomBox->lastAxis = 0;
	bottomBox->last_rotation_sent = 0;
	bottomBox->last_pos_sent.zero();
	bottomBox->side_len = 1;
	bottomBox->torque = 0;
	bottomBox->width.set(1);

	bottomBox->MakeBox(meters(200), 0.01f);
	bottomBox->UpdateWorldSpaceProperties();
	objects.push_back(bottomBox);

	SimBody *topBox = new SimBody(*bottomBox);
	topBox->hashid = ++SimBody::GUID_GEN;
	topBox->position.set(0, meters(100));
	topBox->UpdateWorldSpaceProperties();
	objects.push_back(topBox);

	SimBody *leftBox = new SimBody();
	leftBox->fillMode = GL_LINE;
	leftBox->hashid = ++SimBody::GUID_GEN;
	leftBox->boundingCircleRadius = 500;
	//leftBox->mesh = objects.back()->mesh;
	leftBox->mesh = meshHandle;
	leftBox->width.set(meters(0.1f), meters(100));
	leftBox->position.set(-meters(100), meters(50));
	leftBox->objectMaterial.SetObjectColor(Color::RED);
	leftBox->objectMaterial.AddTexture(mass_textures[0]);
	leftBox->mass = 0; leftBox->invMass = 0;
	leftBox->inertia = 0; leftBox->invI = 0; leftBox->invInertia = 0;
	leftBox->rotation_in_rads = 0; leftBox->CalculateRotationMatrix();
	{
		const float2 &extents = leftBox->width/2;
		leftBox->vertices.push_back(float2(-extents.x, -extents.y));
		leftBox->vertices.push_back(float2(extents.x, -extents.y));
		leftBox->vertices.push_back(float2(extents.x, extents.y));
		leftBox->vertices.push_back(float2(-extents.x, extents.y));
	}
	SAT::GenerateSeperatingAxes(leftBox->vertices, leftBox->seperatingAxis);

	leftBox->angularVelocity = 0;
	leftBox->density = 0;
	leftBox->force.zero();
	leftBox->friction = 0.75f;
	leftBox->lastAxis = 0;
	leftBox->last_rotation_sent = 0;
	leftBox->last_pos_sent.zero();
	leftBox->side_len = 1;
	leftBox->torque = 0;
	leftBox->width.set(1);

	leftBox->MakeBox(meters(0.1f), meters(100));
	leftBox->UpdateWorldSpaceProperties();
	objects.push_back(leftBox);

	SimBody *rightBox = new SimBody(*leftBox);
	rightBox->hashid = ++SimBody::GUID_GEN;
	rightBox->position.set(meters(100), meters(50));
	rightBox->UpdateWorldSpaceProperties();
	objects.push_back(rightBox);
};

#include "Contact.h"
#include "chipCollide.h"
#include "Arbiter.h"

void physthread(void *d)
{
	World *w = (World*)d;
	while(w->alive)
	{
		w->Update(0.016f);
	}
};

void netthread(void *d)
{
	NetworkController *nc = (NetworkController*)d;
	nc->Run();
};

void World::Load()
{
	Unload();
	srand((u32)time(NULL));

	conf.ParseConfigFile("Data/ConfigFile.txt");
	
	zoom = conf.Read("ZoomLevel", -3.45f);
	camPos = conf.Read("CameraPosition", float2(-1.9f, -2.4f));
	camSpeed = conf.Read("CameraSpeed", 5.0f);

	zoomSpeed = conf.Read("ZoomSpeed", 0.03f);

	SimBody::gravity = conf.Read("gravity", default_gravity);
	//if(conf.TryRead("gravity", SimBody::gravity, default_gravity))
	//SimBody::gravity.set(meters(SimBody::gravity.x), meters(SimBody::gravity.y));
	
	updateRate = conf.Read("UpdateRate", 100U);

	DContact::cmat.coFriction = conf.Read("Friction", DContact::cmat.coFriction);
	DContact::cmat.coRestitution = conf.Read("Restitution", DContact::cmat.coRestitution);
	DContact::cmat.coStaticFriction = conf.Read("StaticFriction", DContact::cmat.coStaticFriction);

	mass_textures[0] = LoadTexture("Data/" + conf.Read("LightTexture", "Light.bmp"));
	mass_textures[1] = LoadTexture("Data/" + conf.Read("MediumTexture", "Medium.bmp"));
	mass_textures[2] = LoadTexture("Data/" + conf.Read("HeavyTexture", "Heavy.bmp"));

	masses[0] = conf.Read("MassLight", 100.0f);
	masses[1] = conf.Read("MassMedium", 200.0f);
	masses[2] = conf.Read("MassHeavy", 300.0f);
	invMasses[0] = 1.0f/masses[0];
	invMasses[1] = 1.0f/masses[1];
	invMasses[2] = 1.0f/masses[2];

	CreateWalls();
	
	CreateBoxes();

	firstTriangleIndex = objects.size();
	
	CreateTriangles();

	total_cnt = objects.size();

	int physThreadCount = 3;
	if(conf.TryRead("PhysicsThreadCount", physThreadCount, 3))
	{
		if(physThreadCount < 1 || physThreadCount > 4) // thread count must be in range 1 <= threadCount <= 4, else default to 3 threads
			physThreadCount = 3;
	}

	//physicsPool = new ThreadPool();
	//physicsPool->InitPool(0);
	//physicsPool->ClearTaskList();

	unsigned short _port = conf.Read("Port", (unsigned short)9171U);

	netController = new NetworkController();
	netController->SetWorldPointer(this);
	//netController->StartListening(conf.Read("Port", (unsigned short)9171U));
	//netController->StartListening(9171,5);
	netController->StartListening(_port,5);

	// the only other thread is the 'physics' thread
	//primaryTaskPool = new ThreadPool();
	//primaryTaskPool->InitPool(2);
	//primaryTaskPool->ClearTaskList();

	primaryTaskPool_physThread = new ThreadPool();
	primaryTaskPool_physThread->InitPool(1);
	primaryTaskPool_physThread->ClearTaskList();

	primaryTaskPool_netThread = new ThreadPool();
	primaryTaskPool_netThread->InitPool(1);
	primaryTaskPool_netThread->ClearTaskList();

	alive = true;

	// make array big enough that it will never need to be made bigger (memory alloc = slow!)
	integration_data.reserve(1024);

	for(unsigned int i=0;i<objects.size();++i)
		objects[i]->UpdateWorldSpaceProperties();

	//netController->Connect("127.0.0.1", 80);

	primaryTaskPool_physThread->AddTask(Task(physthread, this));
	primaryTaskPool_netThread->AddTask(Task(netthread, netController));

	//primaryTaskPool->AddTask(Task(physthread, this));
	//primaryTaskPool->AddTask(Task(netthread, netController));

};

void World::CreateBaseObjects(float boxWidth, float boxHeight, float triangleSideLength,
		int boxCount, int triangleCount)
{
	physicsPaused = true;

	vector<SimBody*> oldObjects = objects;

	vector<SimBody*> newBodies;
	for(int i=0;i<4;++i)
	{
		newBodies.push_back(objects[i]);
	}

	// Generate the base objects for the boxes:
	SimBody baseBox;
	baseBox.MakeBox(boxWidth, boxHeight);
	baseBox.objectMaterial.SetObjectColor(Color::RED);
	baseBox.objectMaterial.AddTexture(mass_textures[0]);
	baseBox.rotation_in_rads = 0;
	baseBox.fillMode = GL_FILL;
	baseBox.boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &baseBox.vertices[0], baseBox.vertices.size());
	baseBox.UpdateWorldSpaceProperties();

	for(int i=0;i<boxCount;++i)
	{
		SimBody *box = new SimBody(baseBox);
		box->hashid = ++SimBody::GUID_GEN;
		newBodies.push_back(box);
	}


	// Now the triangles:
	SimBody baseTriangle;
	baseTriangle.MakeTriangle(triangleSideLength);
	baseTriangle.objectMaterial.SetObjectColor(Color::RED);
	baseTriangle.objectMaterial.AddTexture(mass_textures[0]);
	baseTriangle.rotation_in_rads = 0;
	baseTriangle.fillMode = GL_FILL;
	baseTriangle.boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &baseTriangle.vertices[0], baseTriangle.vertices.size());
	baseTriangle.UpdateWorldSpaceProperties();

	firstTriangleIndex = newBodies.size();

	for(int i=0;i<triangleCount;++i)
	{
		SimBody *tri = new SimBody(baseTriangle);
		tri->hashid = ++SimBody::GUID_GEN;
		newBodies.push_back(tri);
	}


	objects = newBodies;

	for(unsigned int i=4;i<oldObjects.size();++i)
	{
		delete oldObjects[i];
	}

	physicsPaused = false;
};