#include "World.h"
#include "util.h"

World::World(void)
{
}

World::~World(void)
{
	UnLoad();
}

void World::Draw(f32 dt)
{
	if(dt){};
};

void World::Update(f32 dt)
{
	if(dt){};
};

void World::Load()
{
	ResourceManager::get(); // initialise resource manager (singleton)
	
	conf.ParseConfigFile("Data/ConfigFile.txt");
};

void World::UnLoad()
{
	ResourceManager::get().Cleanup();
};