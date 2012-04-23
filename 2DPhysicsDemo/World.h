#pragma once

#include "ResourceManager.h"
#include "AppConfig.h"
#include "SimBody.h"
#include "GameTime.h"


class World
{
private:
	AppConfig conf;

	// 800 boxes, 200 triangles (in 2 pyramids), and 1 blobby object
	//SimBody objects[1001];
	//SimBody *objects;
	//static const u32 OBJECT_COUNT = 1001;

	// Boxes first, up to BOX_COUNT elements. Then Triangles up to TRIANGLE_COUNT elements
	// Boxes from indices 0 <= index < BOX_COUNT
	// Triangles from indices BOX_COUNT <= index < BOX_COUNT + TRIANGLE_COUNT
	vector<SimBody*> objects;


	SimBody *box, *triangle;
	

	u32 BOX_ROW_COUNT, BOX_COLUMN_COUNT;
	u32 BOX_COUNT; // = BOX_ROW_COUNT*BOX_COLUMN_COUNT

	u32 TRIANGLE_COUNT;

	u32 TOTAL_OBJECT_COUNT;

	TextureHandle massTextures[3]; // light [0], medium [1], heavy [2]

	u32 updateRate;

	f32 zoom;
	float2 cameraPosition;
	f32 cameraSpeed;

	void update_boxes(f32 dt);
	void update_triangles(f32 dt);

	void test_collisions_tri_box(f32 dt);

	u32 GLOBAL_FILL_MODE; // default GL_LINE

	u32 PHYSICS_THREAD_COUNT;

	bool drawBoundingCircles;

public:
	GameTime *gt;

	World(void);
	~World(void);
	
	void Draw();
	void Update(f32 dt);
	void Load();
	void UnLoad();

	// set to GL_LINE or GL_FILL. When GL_FILL, textures are used. When GL_LINE, textures are disabled, but edges are coloured
	void SetGlobalFillMode(u32 fillmode) { GLOBAL_FILL_MODE = fillmode; };
	u32 GetGlobalFillMode() const { return GLOBAL_FILL_MODE; };

	f32 GetZoom() { return zoom; }
	void SetZoom(f32 z) { zoom = z; }

	f32 GetCameraSpeed() const { return cameraSpeed; };
	float2 GetCameraPosition() { return cameraPosition; };
	void SetCameraPosition(float2 v) { cameraPosition = v; };
};