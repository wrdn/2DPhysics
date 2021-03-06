#pragma once

#include "NetworkController.h"
#include "ResourceManager.h"
#include "AppConfig.h"
#include "SimBody.h"
#include "GameTime.h"
#include <map>
#include "Body.h"
#include "ThreadPool.h"

void physthread(void *d);
void netthread(void *d);

// we render a rectangle to show where the other peer is looking
struct PeerViewRectangle
{
	float2 bl, tr;
};

class World
{
public:
	bool alive;
	bool physicsPaused;

	int numberOfObjectsSent;
	int numberOfObjectsRecv;

	float2 springForce;
	
	PeerViewRectangle mypvr; // my own pvr (used when sending to other machine)
	PeerViewRectangle pvr; // pvr of the connected machine

	bool doOwnershipUpdates;

	float mx,my;
	bool mouseDown;
	SimBody *jointedBody;

	struct IntegrationData
	{
		int firstindex;
		int lastindex;
		f64 dt;
		World *w;

		IntegrationData() {};
		IntegrationData(int _first, int _last, f64 _dt, World *_w)
			: firstindex(_first), lastindex(_last), dt(_dt), w(_w) {};
		~IntegrationData() {};
	};

	// thread pool should be used by physics code only - we are going to make assumptions about when a set of tasks has finished (when queue is empty)
	// so don't use this pool for anything else
	ThreadPool *physicsPool;
	//ThreadPool *primaryTaskPool; // used to manage threads that we're using to run the Render(), Step() etc

	ThreadPool *primaryTaskPool_physThread;
	ThreadPool *primaryTaskPool_netThread;


	NetworkController *netController;

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

	vector<IntegrationData> integration_data;

	double frameTime;

	struct PotentiallyColliding
	{
		SimBody *body1, *body2;

		PotentiallyColliding() {};
		PotentiallyColliding(SimBody *b1, SimBody *b2)
			: body1(b1), body2(b2) {};
		~PotentiallyColliding() {};
	};
	struct BroadTask
	{
		SimBody *baseBody; // the body we are testing for collision against all the other bodies in 'bodies' vector
		vector<SimBody*> *bodies;
		int firstIndex; // first body to process
		int lastIndex; // last body to process
		vector<PotentiallyColliding> *output_plist;
	};


	vector<BroadTask> broadTasks;
	vector<SimBody*> bodies;
	vector<PotentiallyColliding> potentialCollisions;


	void CreateBoxes();
	void CreateTriangles();
	void CreateWalls();

	void GeneratePyramid(int levels, const float2 & startPos); // startPos is the pos of the bottom left triangle

	void BroadPhase();

	void AddForces(f64 dt);
	
	void IntegrateBoxForces(f64 dt);
	void IntegrateBoxes(f64 dt);

	void object_ownership_updates(std::vector<unsigned short> &indices);

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

	// The Load() function will create the walls for us (first 4 objects). When we connect to another peer,
	// this function will be called to allocate the objects for the rest of the scene. Then, the initialisation
	// process will take place in the NetworkController to setup the physical properties of the objects
	void CreateBaseObjects(float boxWidth, float boxHeight, float triangleSideLength,
		int boxCount, int triangleCount);
};