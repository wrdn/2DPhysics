#pragma once

#include "ctypes.h"
#include <GXBase.h>
#include "float2.h"
#include "GameTime.h"
#include "World.h"

// Primary window class for the application, containing main Draw functions (etc)
class FizzyWindow : public gxbase::GLWindowEx
{
private:
	static vec2i windowResolution;
	GameTime gameTime;

	World scn;

public:
	FizzyWindow(void);
	~FizzyWindow(void);

	void OnCreate();
	void OnDestroy();

	void OnDisplay();
	void OnIdle();

	void OnKeyboard(i32 key, bool down);
	
	static vec2i GetWindowResolution() { return windowResolution; };
};