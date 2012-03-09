#pragma once

#include "ResourceManager.h"
#include "AppConfig.h"

class World
{
private:
	AppConfig conf;

public:
	World(void);
	~World(void);
	
	void Draw(f32 dt);
	void Update(f32 dt);
	void Load();
	void UnLoad();
};

