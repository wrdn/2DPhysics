#include "World.h"
#include "GraphicsUtils.h"
#include <time.h>

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

void World::Load()
{
	CleanupVector(objects);

	// parse configuration file
	conf.ParseConfigFile("Data/ConfigFile.txt");

	// initialise resource manager (singleton)
	ResourceManager::get();

	// Setup camera
	zoom = conf.Read("ZoomLevel", -3.45f);
	cameraPosition = conf.Read("CameraPosition", float2(-1.9f, -2.4f));

	if(conf.TryRead("gravity", SimBody::gravity, default_gravity))
	{
		float2 g = SimBody::gravity;
		SimBody::gravity.set( meters(g.x), meters(g.y) );
	}

	cameraSpeed = conf.Read("CameraSpeed", 5.0f);

	updateRate = conf.Read("UpdateRate", 100U);

	PHYSICS_THREAD_COUNT = conf.Read("PhysicsThreadCount", 3U); // default to 3 physics threads

	drawBoundingCircles = conf.Read("DrawBoundingCircles", 0) != 0;

	// Load textures
	massTextures[0] = LoadTexture("Data/" + conf.Read("LightTexture", "Light.bmp"));
	massTextures[1] = LoadTexture("Data/" + conf.Read("MediumTexture", "Medium.bmp"));
	massTextures[2] = LoadTexture("Data/" + conf.Read("HeavyTexture", "Heavy.bmp"));

	// Build meshes
	f32
		BOX_WIDTH = meters(conf.Read("BoxWidth", 1.0f)),
		BOX_HEIGHT = meters(conf.Read("BoxHeight",1.0f)),
		TRIANGLE_LENGTH = meters(conf.Read("TriangleLength", 1.0f));
	MeshHandle boxMesh = Create2DBox(BOX_WIDTH, BOX_HEIGHT);
	MeshHandle triangleMesh = CreateEquilateralTriangle(TRIANGLE_LENGTH);

	// Get colors for light, medium and heavy masses
	color objectColors[] = {
		Color::Normalize(conf.Read("LightColor", Color::BLUE)),
		Color::Normalize(conf.Read("MediumColor", Color::PINK)),
		Color::Normalize(conf.Read("HeavyColor", Color::YELLOW)) };

	// Get row and column count (default 20,40)
	BOX_ROW_COUNT = conf.Read("BoxRowCount", 32U);
	BOX_COLUMN_COUNT = conf.Read("BoxColumnCount", 25U);
	BOX_COUNT = BOX_ROW_COUNT * BOX_COLUMN_COUNT;

	objects.reserve(BOX_COUNT); // make enough space for boxes

	u32 th = BOX_COUNT / 3;
	i32 massCounts[] = { th, th, th + BOX_COUNT%3 };

	srand((u32)time(NULL));

	f32 xOffset = conf.Read("BoxXOffset", 0.003f);
	f32 yOffset = conf.Read("BoxYOffset", 0.003f);


	const f32 masses[] = { 100, 500, 1000 };
	const f32 invMasses[] = { 1.0f/masses[0], 1.0f/masses[1], 1.0f/masses[2] };
	

	// Create boxes
	for(u32 i=0;i<BOX_ROW_COUNT;++i)
	{
		for(u32 j=0;j<BOX_COLUMN_COUNT;++j)
		{
			//const u32 index = (i * BOX_COLUMN_COUNT) + j;
			
			Box *b = new Box();

			b->mesh = boxMesh;
			b->position.set( (j*BOX_WIDTH)+(j*xOffset), (i*BOX_HEIGHT)+(i*yOffset));
			b->position.x -= j*0.03f;

			b->extents.set( BOX_WIDTH/2.0f, BOX_HEIGHT/2.0f);

			b->CalculateVerticesAndSeperatingAxis();

			b->boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &b->vertices[0], b->vertices.size());

			//b->boundingCircleRadius = max(b->extents.x(), b->extents.y());
			//b->boundingCircleRadius += b->boundingCircleRadius*0.45f; // make is slightly bigger than the box, so we dont miss collisions
			
			i32 t = 0;
			while(!massCounts[t=rand(0,2)]);

			b->mass = masses[t];
			b->invMass = invMasses[t];

			//const f32 XVELM = 0.1f;
			//f32 xvel = randflt(-XVELM, XVELM);
			//b->velocity.x(xvel);

			b->objectMaterial.AddTexture(massTextures[t]);
			b->objectMaterial.SetObjectColor(objectColors[t]);

			objects.push_back(b);

			--massCounts[t];
		}
	}
	TOTAL_OBJECT_COUNT = BOX_COUNT;

	++BOX_COUNT;
	++TOTAL_OBJECT_COUNT;
	Box *b = new Box();
	b->mesh = boxMesh;
	b->position.set( 2*TRIANGLE_LENGTH, 0.3f );
	b->extents.set( BOX_WIDTH/2.0f, BOX_HEIGHT/2.0f);
	b->CalculateVerticesAndSeperatingAxis();
	b->boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &b->vertices[0], b->vertices.size());
	b->mass = masses[0];
	b->invMass = invMasses[0];
	b->objectMaterial.SetObjectColor(Color::RED);
	b->rotation = 0;
	b->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(b->rotation));
	objects.push_back(b);

	// TEST OBJECT GENERATION
	body_box = new CBODY();
	body_box->angle = 0;
	body_box->orientationMatrix = Matrix(body_box->angle);
	body_box->pos = Vector(90,55);
	body_box->bodyColor.set(1,0,0);
	{
		float2 extents(10,10);
		body_box->vertices.push_back(Vector(-extents.x, -extents.y));
		body_box->vertices.push_back(Vector(extents.x, -extents.y));
		body_box->vertices.push_back(Vector(extents.x, extents.y));
		body_box->vertices.push_back(Vector(-extents.x, extents.y));
	}

	body_triangle = new CBODY();
	body_triangle->angle = 0;
	body_triangle->orientationMatrix = Matrix(DegreesToRadians(body_triangle->angle));
	body_triangle->pos = Vector(75,55);
	body_triangle->bodyColor.set(1,0,0);
	{
		float SL = 20;
		body_triangle->vertices.push_back(Vector(0, SL));
		body_triangle->vertices.push_back(Vector(SL, -SL));
		body_triangle->vertices.push_back(Vector(-SL, -SL));
	}
	// END OF TEST OBJECT GENERATION

	box = new SimBody();
	box->mesh = boxMesh;
	box->fillMode = GL_LINE;
	box->position = b->position;
	box->rotation = 0;
	box->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(box->rotation));
	box->objectMaterial.SetObjectColor(Color::RED);
	float2 extents = b->extents;
	box->vertices.push_back(float2(-extents.x, -extents.y));
	box->vertices.push_back(float2(extents.x, -extents.y));
	box->vertices.push_back(float2(extents.x, extents.y));
	box->vertices.push_back(float2(-extents.x, extents.y));
	{
		float2 *A = &box->vertices[0];
		u32 Anum = box->vertices.size();
		for(u32 j = Anum-1, i = 0; i < Anum; j = i, i ++)
		{
			float2 E0 = A[j], E1 = A[i];
			float2 E = E1 - E0;
			box->seperatingAxis.push_back(float2(-E.y, E.x));
		}

		// we only need 2 seperating axis for boxes
		box->seperatingAxis.erase(box->seperatingAxis.begin()+2, box->seperatingAxis.end());
	}

	triangle = new SimBody();
	triangle->mesh = triangleMesh;
	triangle->fillMode = GL_LINE;
	triangle->position.set(0.07f, 0.3f);
	triangle->rotation = 0;
	triangle->objectMaterial.SetObjectColor(Color::RED);
	float SL = TRIANGLE_LENGTH;
	triangle->vertices.push_back(float2(0, SL));
	triangle->vertices.push_back(float2(SL, -SL));
	triangle->vertices.push_back(float2(-SL, -SL));
	{
		float2 *A = &triangle->vertices[0];
		u32 Anum = triangle->vertices.size();
		for(u32 j = Anum-1, i = 0; i < Anum; j = i, i ++)
		{
			float2 E0 = A[j], E1 = A[i];
			float2 E = E1 - E0;
			triangle->seperatingAxis.push_back(float2(-E.y, E.x));
		}
	}

	// Create triangles

	// For now, we'll just create 2 triangles so we can test collisions
	TRIANGLE_COUNT = 1;
	for(u32 i=0;i<TRIANGLE_COUNT;++i)
	{
		Triangle *t = new Triangle();
		t->sideLength = TRIANGLE_LENGTH;
		t->CalculateVerticesAndSeperatingAxis();

		t->objectMaterial.SetObjectColor(Color::RED);

		t->mass = masses[0];
		t->invMass = invMasses[0];

		t->mesh = triangleMesh;
		
		t->position.x = i*TRIANGLE_LENGTH + (0.10f);
		t->position.y = 0.3f;

		t->boundingCircleRadius = CalculateBoundingCircle(float2(), &t->vertices[0], t->vertices.size());

		t->rotation = 45;
		t->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(t->rotation));

		objects.push_back(t);
	}
	TOTAL_OBJECT_COUNT += TRIANGLE_COUNT;
};

void World::UnLoad()
{
	ResourceManager::get().Cleanup();

	CleanupVector(objects);
};