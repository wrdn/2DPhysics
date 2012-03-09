#pragma once

#include "ctypes.h"
#include <GXBase.h>

class GameTime
{
private:
	f32 currentTime;
	f32 deltaTime;
public:
	GameTime() : currentTime(0), deltaTime(0) { };

	f32 GetCurrentTime() const;
	f32 GetDeltaTime() const;
	void SetDeltaTime(f32 dt);
	f32 Update();
};