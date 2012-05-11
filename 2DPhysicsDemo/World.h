#pragma once

#include "ResourceManager.h"
#include "AppConfig.h"
#include "SimBody.h"
#include "GameTime.h"
#include <map>
#include "Body.h"

class World
{
private:
	AppConfig conf;
	TextureHandle mass_textures[3];

	f32 masses[3], invMasses[3];

	vector<SimBody*> objects;
	
	vector<SimBody*> boxes;
	vector<SimBody*> triangles; // split them up as triangle update different to box update (different collision detection etc)

	//std::vector<Body*> bodies;
	std::map<ArbiterKey, Arbiter> arbiters;

	//vector<Body*> bodies;
	//std::map<PhysArbiterKey, PhysArbiter> arbiters;

	u32 box_row_cnt, box_col_cnt, box_cnt, tri_cnt, total_cnt;
	int firstTriangleIndex;

	u32 global_fill_mode;

	u32 updateRate;

	f32 zoom, camSpeed;
	float2 camPos;

	void CreateBoxes();
	void CreateTriangles();
	void CreateWalls();

	void BroadPhase();

public:

	float zoomSpeed;

	GameTime *gt;

	World();
	~World();

	void Update(f64 dt);

	void OldUpdate(f64 dt);

	void Draw();
	void Load();
	void Unload();

	void set_global_fill_mode(u32 fm) { global_fill_mode = fm; };
	u32 get_global_fill_mode() const { return global_fill_mode; };
	void set_zoom(f32 z) { zoom = z; };
	f32 get_zoom() const { return zoom; };
	f32 get_cam_speed() { return camSpeed; };
	float2 get_cam_pos() { return camPos; };
	void set_cam_pos(const float2 &p) { camPos = p; };
};