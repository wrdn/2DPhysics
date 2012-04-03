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
	SimBody objects[1001];

	TextureHandle massTextures[3]; // light [0], medium [1], heavy [2]

	f32 zoom;
	float2 cameraPosition;
	f32 cameraSpeed;
public:
	GameTime *gt;

	World(void);
	~World(void);
	
	void Draw();
	void Update(f32 dt);
	void Load();
	void UnLoad();

	f32 GetZoom() { return zoom; }
	void SetZoom(f32 z) { zoom = z; }

	float GetCameraSpeed() const { return cameraSpeed; };
	float2 GetCameraPosition() { return cameraPosition; };
	void SetCameraPosition(float2 v) { cameraPosition = v; };
};