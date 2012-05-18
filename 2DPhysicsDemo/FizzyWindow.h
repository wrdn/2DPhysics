#pragma once

#include "NetworkController.h"
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

	float frameTimeBuffer[25];
	int currentFrameTimeBufferPos;

	float currentTime, prevTime;

	GLdouble mx, my;

	SimBody *jointedBody;
	bool down;

public:
	FizzyWindow(void);
	~FizzyWindow(void);

	void OnCreate();
	void OnDestroy();

	void OnMouseButton(gxbase::GLWindow::MouseButton button, bool down);

	void OnMouseMove(i32 x, i32 y);

	void OnResize(i32 w, i32 h)
	{
		windowResolution.x = w;
		windowResolution.y = h;

		glViewport(0,0,w,h);

		float scale = 2.5*min((float)w/640.0f, (float)h/480.0f);
		float hw = w*(0.5/scale);
		float hh = h*(0.5/scale);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho(-hw,hw,-hh,hh,-1,1);

		glTranslatef(0.5,0.5,0);

		/*windowResolution.x = w;
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
		glLoadIdentity();*/
	};

	void OnDisplay();
	void OnIdle();

	void OnKeyboard(i32 key, bool down);
	
	static vec2i GetWindowResolution() { return windowResolution; };
};