#include "FizzyWindow.h"

vec2i FizzyWindow::windowResolution = vec2i(800,600);

FizzyWindow::FizzyWindow(void)
{
	SetSize(windowResolution.x, windowResolution.y);
	SetDepthBits(24);
	SetStencilBits(1);
	SetTitle("2D Physics Demo - William Dann");
}

FizzyWindow::~FizzyWindow(void)
{
}

void FizzyWindow::OnDisplay()
{
	//double DT = gameTime.Update();

	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	//scn.Update(DT);
	scn.Draw();

	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2f(0.5f, 0.9f);
	Printf("Frame Time: %f", scn.frameTime);
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();   
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);

	SwapBuffers();
};

void FizzyWindow::OnKeyboard(i32 key, bool down)
{
	gameTime.Update();

	if(key == VK_ESCAPE && down)
	{
		Close();
	}

	float2 camPos = scn.get_cam_pos();
	f32 dt = (f32)gameTime.GetDeltaTime();
	dt = 0.016f;
	f32 camSpeed = scn.get_cam_speed();
	f32 zoomSpeed = scn.zoomSpeed;

	switch(tolower(key))
	{
	case 'q':
		scn.set_zoom(scn.get_zoom() + dt * zoomSpeed);
		break;
	case 'e':
		scn.set_zoom(scn.get_zoom() - dt * zoomSpeed);
		break;
	case 'w':
		//camPos.y( camPos.y() - dt * camSpeed);
		camPos.y -= dt * camSpeed;
		break;
	case 's':
		//camPos.y( camPos.y() + dt * camSpeed);
		camPos.y += dt * camSpeed;
		break;
	case 'a':
		//camPos.x( camPos.x() + dt * camSpeed);
		camPos.x += dt * camSpeed;
		break;
	case 'd':
		//camPos.x( camPos.x() - dt * camSpeed);
		camPos.x -= dt * camSpeed;
		break;
	case 'r':
		scn.alive = false;
		scn.primaryTaskPool->Join();
		scn.Load();
		return;
		break;
	case 'f':
		if(!down) break;
		scn.set_global_fill_mode(scn.get_global_fill_mode() == GL_LINE ? GL_FILL : GL_LINE);
		break;
	}

	scn.set_cam_pos(camPos);
};

void FizzyWindow::OnCreate()
{
	GLWindowEx::OnCreate();
	glex::Load();

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearColor(0,0,0,1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// Loading screen
	glClear(GL_COLOR_BUFFER_BIT);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix(); glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix(); glLoadIdentity();
	glRasterPos2f(-0.15f, 0);
	Printf("Loading . . .");
	SwapBuffers();

	scn.gt = &gameTime;
	scn.Load();

	glMatrixMode(GL_PROJECTION); glPopMatrix();   
	glMatrixMode(GL_MODELVIEW); glPopMatrix();
	glEnable(GL_DEPTH_TEST);

	gameTime.Update();
	gameTime.Update();
};

void FizzyWindow::OnDestroy()
{
	// Do not change the order of destruction
	// Kill in reverse order so things are shut down properly
	scn.alive = false;
	scn.primaryTaskPool->SigKill();
	scn.Unload();
};

void FizzyWindow::OnIdle()
{
	//return;
	//scn.Update(gameTime.Update());
	Redraw();
};