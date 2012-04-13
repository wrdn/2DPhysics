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
	gameTime.Update();

	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	scn.Update(gameTime.GetDeltaTime());
	scn.Draw();

	/*glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2f(0.5f, 0.9f);
	Printf("Delta Time: %f", gameTime.GetDeltaTime());

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();   
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);*/

	SwapBuffers();
};

void FizzyWindow::OnKeyboard(i32 key, bool down)
{
	gameTime.Update();

	if(key == VK_ESCAPE && down)
	{
		Close();
	}

	float2 camPos = scn.GetCameraPosition();
	f32 dt = gameTime.GetDeltaTime();
	f32 camSpeed = scn.GetCameraSpeed();

	switch(tolower(key))
	{
	case 'q':
		scn.SetZoom(scn.GetZoom() + dt * camSpeed);
		break;
	case 'e':
		scn.SetZoom(scn.GetZoom() - dt * camSpeed);
		break;
	case 'w':
		camPos.y( camPos.y() - dt * camSpeed);
		break;
	case 's':
		camPos.y( camPos.y() + dt * camSpeed);
		break;
	case 'a':
		camPos.x( camPos.x() + dt * camSpeed);
		break;
	case 'd':
		camPos.x( camPos.x() - dt * camSpeed);
		break;
	case 'r':
		scn.Load();
		break;
	case 'f':
		if(!down) break;
		scn.SetGlobalFillMode(scn.GetGlobalFillMode() == GL_LINE ? GL_FILL : GL_LINE);
		break;
	}

	scn.SetCameraPosition(camPos);
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

	scn.Load();

	glMatrixMode(GL_PROJECTION); glPopMatrix();   
	glMatrixMode(GL_MODELVIEW); glPopMatrix();
	glEnable(GL_DEPTH_TEST);

	scn.gt = &gameTime;
	gameTime.Update();
};

void FizzyWindow::OnDestroy()
{
};

void FizzyWindow::OnIdle()
{
	gameTime.Update();
	Redraw();
};