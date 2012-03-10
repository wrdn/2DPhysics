#pragma once

#include "ctypes.h"
#include <Windows.h>

class GameTime
{
private:
	DWORD oldTime;
	f32 deltaTime;
public:
	GameTime();
	~GameTime();

	f32 GetDeltaTime();
	f32 Update();
};