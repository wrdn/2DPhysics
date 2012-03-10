#pragma once

#include "ResourceManager.h"
#include "AppConfig.h"
#include "SceneObject.h"

class World
{
private:
	AppConfig conf;

	// 800 boxes, 200 triangles (in 2 pyramids), and 1 blobby object
	SceneObject objects[1001];

	TextureHandle massTextures[3]; // light [0], medium [1], heavy [2]

	f32 zoom;
	float2 cameraPosition;

public:
	World(void);
	~World(void);
	
	void Draw();
	void Update(f32 dt);
	void Load();
	void UnLoad();

	f32 GetZoom() { return zoom; }
	void SetZoom(f32 z) { zoom = z; }

	float2 GetCameraPosition() { return cameraPosition; };
	void SetCameraPosition(float2 v) { cameraPosition = v; };
};