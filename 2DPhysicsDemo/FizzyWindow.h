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

	void OnMouseButton(gxbase::GLWindow::MouseButton button, bool down);
	void OnMouseMove(i32 x, i32 y);

public:
	FizzyWindow(void);
	~FizzyWindow(void);

	float2 MouseToSpace(int x, int y, int windowResY);

	void OnCreate();
	void OnDestroy();

	void OnResize(i32 w, i32 h)
	{
		windowResolution.x = w;
		windowResolution.y = h;

		glViewport(0,0,w,h);

		float scale = max(1,scn.zoom)*min((float)w/640.0f, (float)h/480.0f);

		float hw = w*(0.5/scale);

		float hh = h*(0.5/scale);

		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();

		glOrtho(-hw,hw,-hh,hh,-1,1);

		glTranslatef(0.5,0.5,0);


		/*glViewport(0,0,windowResolution.x,windowResolution.y);
			float scale = max(1,scn.zoom)*min((float)windowResolution.x/640.0f, (float)windowResolution.y/480.0f);
			float w = windowResolution.x;
			float h = windowResolution.y;
			float hw = w*(0.5/scale);
			float hh = h*(0.5/scale);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(-hw,hw,-hh,hh,-1,1);
			glTranslatef(0.5,0.5,0);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();*/
	};

	void OnDisplay();
	void OnIdle();

	void OnKeyboard(i32 key, bool down);
	
	static vec2i GetWindowResolution() { return windowResolution; };
};