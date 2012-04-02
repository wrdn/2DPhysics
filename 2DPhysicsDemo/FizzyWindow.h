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

	void OnResize(i32 w, i32 h)
	{
		windowResolution.x = w;
		windowResolution.y = h;

		f32 nRange = 1;

		glViewport(0,0,windowResolution.x, windowResolution.y);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		if(w <= h)
		{
			f32 hw = (f32)h/(f32)w;
			glOrtho(-nRange, nRange, -nRange*hw, nRange*hw, -nRange, nRange);
		}
		else
		{
			f32 hw = (f32)w/(f32)h;
			glOrtho(-nRange*hw, nRange*hw, -nRange, nRange, -nRange, nRange);
		}

		glMatrixMode(GL_MODELVIEW);
	};

	void OnDisplay();
	void OnIdle();

	void OnKeyboard(i32 key, bool down);
	
	static vec2i GetWindowResolution() { return windowResolution; };
};