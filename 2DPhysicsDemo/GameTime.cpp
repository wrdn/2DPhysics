#include "GameTime.h"
#include "ctypes.h"
#include <GXBase.h>

GameTime::GameTime() : pt(), dt(0)
{
	//timeBeginPeriod(1); // calling this, timeGetTime() now has 1ms accuracy
};

GameTime::~GameTime() {};

/*
GameTime::~GameTime()
{
	timeEndPeriod(1);
};

f32 GameTime::GetDeltaTime() { return deltaTime; };

f32 GameTime::Update()
{
	DWORD now = timeGetTime();
	DWORD diff = now - oldTime;
	oldTime = now;
	currentTime += deltaTime;
	deltaTime = 0.001f * (f32)diff;
	return deltaTime;
};
*/