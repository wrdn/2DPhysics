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
	ResourceManager::get().Cleanup();
	CleanupVector(objects);
	CleanupVector(bodies);
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
	assert(massCounts[0]+massCounts[1]+massCounts[2] >= box_cnt);

	SimBody baseBox;
	baseBox.mesh = boxMesh;
	baseBox.extents.set(box_width/2, box_height/2);
	baseBox.objectMaterial.SetObjectColor(Color::RED);
	baseBox.objectMaterial.AddTexture(mass_textures[0]);
	baseBox.mass = 500; baseBox.invMass = 1.0f/500.0f;
	baseBox.rotation_in_rads = 0; baseBox.CalculateRotationMatrix();
	{
		const float2 &extents = baseBox.extents;
		baseBox. vertices.push_back(float2(-extents.x, -extents.y));
		baseBox.vertices.push_back(float2(extents.x, -extents.y));
		baseBox.vertices.push_back(float2(extents.x, extents.y));
		baseBox.vertices.push_back(float2(-extents.x, extents.y));
	}
	SAT::GenerateSeperatingAxes(baseBox.vertices, baseBox.seperatingAxis, 2);
	baseBox.boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &baseBox.vertices[0], baseBox.vertices.size());

	// Generate boxes
	for(u32 i=0;i<box_row_cnt;++i)
	{
		for(u32 j=0;j<box_col_cnt;++j)
		{
			SimBody *b = new SimBody(baseBox);
			b->position.set((j*box_width)+(j*xOffset), (i*box_height)+(i*yOffset));

			i32 t = 0;
			while(!massCounts[t=rand(0,2)]);

			b->rotation_in_rads = randflt(-TWOPI, TWOPI);
			b->CalculateRotationMatrix();

			b->mass = masses[t];
			b->invMass = invMasses[t];

			b->CalculateInertia();

			b->position.x += randflt(0, 0.8f);

			b->fillMode = GL_LINE;

			objects.push_back(b);
		}
	}
};

void World::CreateTriangles()
{
	f32 triangle_len = meters(conf.Read("TriangleLength", 1.0f));
	MeshHandle triMesh = CreateEquilateralTriangle(triangle_len);

	SimBody baseTriangle;
	baseTriangle.mesh = triMesh;
	baseTriangle.rotation_in_rads = 0; baseTriangle.CalculateRotationMatrix();
	baseTriangle.objectMaterial.SetObjectColor(Color::RED);
	baseTriangle.objectMaterial.AddTexture(mass_textures[0]);
	baseTriangle.mass = 0; baseTriangle.invMass = 0;
	baseTriangle.side_len = triangle_len;
	{
		float SL = baseTriangle.side_len;
		baseTriangle.vertices.push_back(float2(0, SL));
		baseTriangle.vertices.push_back(float2(SL, -SL));
		baseTriangle.vertices.push_back(float2(-SL, -SL));
	}
	SAT::GenerateSeperatingAxes(baseTriangle.vertices, baseTriangle.seperatingAxis);
	baseTriangle.boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &baseTriangle.vertices[0], baseTriangle.vertices.size());

	for(int i=0;i<10;++i)
	{
		SimBody *tri = new SimBody(baseTriangle);

		int t = rand(0,2);
		tri->position.set(1.0f*i,10);

		tri->rotation_in_rads = randflt(-TWOPI, TWOPI);
		tri->CalculateRotationMatrix();

		tri->mass = masses[t];
		tri->invMass = invMasses[t];
		tri->CalculateInertia();
		tri->fillMode = GL_LINE;

		objects.push_back(tri);
	}
};

void World::CreateWalls()
{
	SimBody *bottomWall = new SimBody();
	SimBody *leftWall, *rightWall, *topWall;

	bottomWall->objectMaterial.SetObjectColor(Color::RED);
	bottomWall->mass = bottomWall->invMass = 0;
	bottomWall->rotation_in_rads = 0;
	bottomWall->CalculateRotationMatrix();
	bottomWall->fillMode = GL_LINE;
	leftWall = new SimBody(*bottomWall); rightWall = new SimBody(*bottomWall); topWall = new SimBody(*bottomWall);
	bottomWall->vertices.push_back(float2(-30,0));
	bottomWall->vertices.push_back(float2(30,0));
	SAT::GenerateSeperatingAxes(bottomWall->vertices, bottomWall->seperatingAxis);
	bottomWall->position.set(0,-30);
	objects.push_back(bottomWall);

	leftWall->vertices.push_back(float2(0,30));
	leftWall->vertices.push_back(float2(0,-30));
	SAT::GenerateSeperatingAxes(leftWall->vertices, leftWall->seperatingAxis);
	leftWall->position.set(-30,0);
	objects.push_back(leftWall);

	rightWall->vertices.push_back(float2(0,30));
	rightWall->vertices.push_back(float2(0,-30));
	SAT::GenerateSeperatingAxes(rightWall->vertices, rightWall->seperatingAxis);
	rightWall->position.set(30,0);
	objects.push_back(rightWall);

	topWall->vertices.push_back(float2(-30,0));
	topWall->vertices.push_back(float2(30,0));
	SAT::GenerateSeperatingAxes(topWall->vertices, topWall->seperatingAxis);
	topWall->position.set(0,30);
	objects.push_back(topWall);
};

#include "Contact.h"
void World::Load()
{
	Unload();
	srand((u32)time(NULL));

	conf.ParseConfigFile("Data/ConfigFile.txt");
	
	zoom = conf.Read("ZoomLevel", -3.45f);
	camPos = conf.Read("CameraPosition", float2(-1.9f, -2.4f));
	camSpeed = conf.Read("CameraSpeed", 5.0f);

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
	CreateTriangles();
	total_cnt = objects.size();

	Body *b = new Body();
	b->Set(float2(100.0f, 20.0f), FLT_MAX);
	b->position.set(0.0f, -0.5f * b->width.y);
	b->mass = b->invMass = b->invI = b->I = 0;
	b->boundingCircleRadius = 150;;
	bodies.push_back(new Body(*b));

	float bottomPos = b->position.y + b->width.y/2 + 0.6f;

	for(int i=0;i<20;++i)
	{
		for(int j=0;j<20;++j)
		{
			b->Set(float2(1.0f, 1.0f), 200.0f);
			b->position.set(i*b->width.x+(0.1*i), bottomPos+j*b->width.y+(j*0.15f));
			b->boundingCircleRadius = 1.1;
			bodies.push_back(new Body(*b));
		}
	}

	delete b;

	/*Body *b = new Body();
	b->Set(float2(100.0f, 20.0f), FLT_MAX);
	b->position.set(0.0f, -0.5f * b->width.y);
	b->mass = b->invMass = b->invI = b->I = 0;
	bodies.push_back(new Body(*b));

	b->Set(float2(1.0f, 1.0f), 200.0f);
	b->position.set(0.0f, 4.0f);
	bodies.push_back(new Body(*b));

	b->Set(float2(1.0f, 1.0f), 200.0f);
	b->position.set(0.4,8);
	bodies.push_back(new Body(*b));

	delete b;*/




	/*float boxWidth = 100, boxHeight = 20;
	Body *testBox = new Body();
	testBox->mass = FLT_MAX; testBox->invMass = 0;
	testBox->pos.set(0,-10);
	testBox->dimensions.set(boxWidth, boxHeight);
	testBox->vertices.push_back(float2(-boxWidth/2, boxHeight/2));
	testBox->vertices.push_back(float2(-boxWidth/2, -boxHeight/2));
	testBox->vertices.push_back(float2(boxWidth/2, -boxHeight/2));
	testBox->vertices.push_back(float2(boxWidth/2, boxHeight/2));
	testBox->restitution=0;
	testBox->inertia = FLT_MAX; testBox->invInertia=0;
	bodies.push_back(testBox);

	{
		Box *n = new Body();
		n->friction = 0.2;
		n->restitution = 0;
		n->inertia = n->invInertia = 0;
		n->dimensions.set(1,1);
		n->pos.set(0,4);
		boxWidth=n->dimensions.x; boxHeight=n->dimensions.y;
		n->vertices.push_back(float2(-boxWidth/2, boxHeight/2));
		n->vertices.push_back(float2(-boxWidth/2, -boxHeight/2));
		n->vertices.push_back(float2(boxWidth/2, -boxHeight/2));
		n->vertices.push_back(float2(boxWidth/2, boxHeight/2));
		n->mass = 200; n->invMass = 1.0f/n->mass;
		n->inertia = n->mass*(n->dimensions.x*n->dimensions.x + 
			n->dimensions.y*n->dimensions.y)/12.0f;
		n->invInertia=1.0f/n->inertia;
		bodies.push_back(n);
	}

	{
		Box *n = new Body();
		n->friction = 0.2;
		n->restitution = 0;
		n->inertia = n->invInertia = 0;
		n->dimensions.set(1,1);
		n->pos.set(0.4,8);
		boxWidth=n->dimensions.x; boxHeight=n->dimensions.y;
		n->vertices.push_back(float2(-boxWidth/2, boxHeight/2));
		n->vertices.push_back(float2(-boxWidth/2, -boxHeight/2));
		n->vertices.push_back(float2(boxWidth/2, -boxHeight/2));
		n->vertices.push_back(float2(boxWidth/2, boxHeight/2));
		n->mass = 200; n->invMass = 1.0f/n->mass;
		n->inertia = n->mass*(n->dimensions.x*n->dimensions.x + 
			n->dimensions.y*n->dimensions.y)/12.0f;
		n->invInertia=1.0f/n->inertia;
		bodies.push_back(n);
	}*/

	
};