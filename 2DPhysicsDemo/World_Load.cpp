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
}

void World::Load()
{
	Unload();
	srand((u32)time(NULL));

	conf.ParseConfigFile("Data/ConfigFile.txt");
	
	zoom = conf.Read("ZoomLevel", -3.45f);
	camPos = conf.Read("CameraPosition", float2(-1.9f, -2.4f));
	camSpeed = conf.Read("CameraSpeed", 5.0f);

	if(conf.TryRead("gravity", SimBody::gravity, default_gravity))
	{
		float2 g = SimBody::gravity;
		SimBody::gravity.set(meters(g.x), meters(g.y));
	}
	
	updateRate = conf.Read("UpdateRate", 100U);

	mass_textures[0] = LoadTexture("Data/" + conf.Read("LightTexture", "Light.bmp"));
	mass_textures[1] = LoadTexture("Data/" + conf.Read("MediumTexture", "Medium.bmp"));
	mass_textures[2] = LoadTexture("Data/" + conf.Read("HeavyTexture", "Heavy.bmp"));

	f32 box_width  = meters(conf.Read("BoxWidth"  , 1.0f));
	f32 box_height = meters(conf.Read("BoxHeight" , 1.0f));
	f32 triangle_len = conf.Read("TriangleLength", 1.0f);

	MeshHandle boxMesh = Create2DBox(box_width, box_height);
	MeshHandle triMesh = CreateEquilateralTriangle(triangle_len);

	box_row_cnt = conf.Read("BoxRowCount", 32U);
	box_col_cnt = conf.Read("BoxColumnCount", 25U);
	box_cnt = box_row_cnt * box_col_cnt;
	objects.reserve(4 + box_cnt);

	u32 th = box_cnt / 3;
	i32 massCounts[] = { th, th, th + box_cnt%3 };

	f32 xOffset = conf.Read("BoxXOffset", 0.003f);
	f32 yOffset = conf.Read("BoxYOffset", 0.003f);

	const f32 masses[] = { 100, 500, 1000 };
	const f32 invMasses[] = { 1.0f/masses[0], 1.0f/masses[1], 1.0f/masses[2] };

	/********** CREATE WALLS ***********/


	/********** CREATE BOXES ***********/
	// Create a base box that will be copied for each new box we create
	// For a shared property, set it here and at load time, it will be put
	// in EVERY box. Easier and faster than doing it in the loop itself
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
	baseBox.boundingCircleRadius = CalculateBoundingCircle(float2(0,0), &baseBox.vertices[0],
		baseBox.vertices.size());
	
	// Generate boxes
	for(u32 i=0;i<box_row_cnt;++i)
	{
		for(u32 j=0;j<box_col_cnt;++j)
		{
			SimBody *b = new SimBody(baseBox);
			b->position.set((j*box_width)+(j*xOffset), (i*box_height)+(i*yOffset));
			//b->position.x -= j*0.03f;
			
			b->fillMode = GL_LINE;

			objects.push_back(b);
		}
	}
	total_cnt = box_cnt;

	/********** CREATE TRIANGLES ***********/
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
};