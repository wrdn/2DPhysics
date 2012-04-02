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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	if(zoom <= 0.05f) zoom = 0.05f;
	glScalef(zoom,zoom,1);

	glTranslatef(cameraPosition.x(), cameraPosition.y(), 0);

	for(u32 i=0;i<1001;++i)
	{
		objects[i].polygonFillMode = GL_LINE; // useful for debugging collision detection/response
		objects[i].Draw();
	}

	glPopMatrix();
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

	cameraSpeed = conf.Read("CameraSpeed", 5.0f);

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
	u32 ROW_COUNT = conf.Read("BoxRowCount", 32U);
	u32 COLUMN_COUNT = conf.Read("BoxColumnCount", 25U);
	
	/*if(ROW_COUNT * COLUMN_COUNT != 800)
	{
		ROW_COUNT = 20;
		COLUMN_COUNT = 40;
	}*/
	
	// around 1/3 of light, medium and heavy boxes, tune these parameters as you wish
	u32 totalBoxes = ROW_COUNT * COLUMN_COUNT;
	u32 th = totalBoxes / 3;
	i32 massCounts[] = { th, th, th + totalBoxes%3 };

	srand((u32)time(NULL));

	f32 xOffset = conf.Read("BoxXOffset", 0.003f);
	f32 yOffset = conf.Read("BoxYOffset", 0.003f);

	// Create boxes
	for(u32 i=0;i<ROW_COUNT;++i)
	{
		for(u32 j=0;j<COLUMN_COUNT;++j)
		{
			const u32 index = (i * COLUMN_COUNT) + j;
			
			objects[index].mesh = boxMesh;
			objects[index].position = float2( (j*BOX_WIDTH)+(j*xOffset), (i*BOX_HEIGHT)+(i*yOffset));
			
			i32 t = 0;
			while(!massCounts[t=rand(0,2)]);

			objects[index].objectMaterial.AddTexture(massTextures[t]);
			objects[index].objectMaterial.SetObjectColor(objectColors[t]);

			--massCounts[t];
		}
	}

	// Create triangles
};

void World::UnLoad()
{
	ResourceManager::get().Cleanup();
};