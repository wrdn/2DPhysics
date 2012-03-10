#include "GameTime.h"
#include "ctypes.h"

GameTime::GameTime() : oldTime(0), deltaTime(0)
{
	timeBeginPeriod(1); // calling this, timeGetTime() now has 1ms accuracy
};

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
	deltaTime = 0.001f * diff;
	return deltaTime;
};