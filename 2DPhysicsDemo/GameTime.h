#pragma once

#include "ctypes.h"
#include <Windows.h>

class GameTime
{
private:
	DWORD oldTime;
	f32 deltaTime;
	f32 currentTime;

public:
	GameTime();
	~GameTime();

	f32 GetCurrentTime() const { return currentTime; };
	f32 GetDeltaTime();
	f32 Update();
};