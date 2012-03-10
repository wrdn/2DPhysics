#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include <time.h>
using namespace std;

World::World(void) : zoom(-3.45f)
{
}

World::~World(void)
{
	UnLoad();
}

void World::Draw()
{
	glMatrixMode(GL_PROJECTION); glLoadIdentity();
	glOrtho(zoom,-zoom,zoom,-zoom,0,1);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();

	glTranslatef(cameraPosition.x(), cameraPosition.y(), 0);

	for(u32 i=0;i<1001;++i)
	{
		objects[i].Draw();
	}
};

void World::Update(f32 dt)
{
	if(dt){};
};

void World::Load()
{
	// parse configuration file
	conf.ParseConfigFile("Data/ConfigFile.txt");

	// initialise resource manager (singleton)
	ResourceManager::get();

	// Setup camera
	zoom = conf.Read("ZoomLevel", -3.45f);
	cameraPosition = conf.Read("CameraPosition", float2(-1.9f, -2.4f));

	// Load textures
	massTextures[0] = LoadTexture("Data/" + conf.Read("LightTexture", "Light.bmp"));
	massTextures[1] = LoadTexture("Data/" + conf.Read("MediumTexture", "Medium.bmp"));
	massTextures[2] = LoadTexture("Data/" + conf.Read("HeavyTexture", "Heavy.bmp"));

	// Build meshes
	const f32
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
	u32 ROW_COUNT = conf.Read("BoxRowCount", 32U);
	u32 COLUMN_COUNT = conf.Read("BoxColumnCount", 25U);
	if(ROW_COUNT * COLUMN_COUNT != 800)
	{
		ROW_COUNT = 20;
		COLUMN_COUNT = 40;
	}

	// around 1/3 of light, medium and heavy boxes, tune these parameters as you wish (note: they should NEVER drop below 800 when summed)
	i32 massCounts[] = { 267, 267, 266 };
	assert(massCounts[0]+massCounts[1]+massCounts[2] >= 800);

	srand((u32)time(NULL));

	// Create boxes
	for(u32 i=0;i<ROW_COUNT;++i)
	{
		for(u32 j=0;j<COLUMN_COUNT;++j)
		{
			const u32 index = (i * COLUMN_COUNT) + j;
			objects[index].SetMesh(boxMesh);
			objects[index].SetPosition( float2( (j*BOX_WIDTH), i*BOX_HEIGHT) );

			// randomise mass from light, medium and heavy set
			i32 t = 0;
			while(!massCounts[t=rand(0,2)]);

			objects[index].AddTexture( massTextures[t] );
			objects[index].SetColor( objectColors[t] );
			objects[index].SetPolygonFillMode(t);

			--massCounts[t];
		}
	}
};

void World::UnLoad()
{
	ResourceManager::get().Cleanup();
};