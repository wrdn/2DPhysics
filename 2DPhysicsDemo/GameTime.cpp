#include "GameTime.h"
#include "ctypes.h"

f32 GameTime::GetCurrentTime() const { return currentTime; };
f32 GameTime::GetDeltaTime() const { return deltaTime; };
void GameTime::SetDeltaTime(f32 dt) { deltaTime = dt; };

f32 GameTime::Update()
{
	f32 temp_time = (f32)gxbase::App::GetTime();
	deltaTime = temp_time - currentTime;
	if(deltaTime >= 1) deltaTime=0;
	currentTime = temp_time;
	
	return deltaTime;
};