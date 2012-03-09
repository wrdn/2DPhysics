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
	f32 dt = gameTime.Update();

	glDisable(GL_LIGHTING);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);

	scn.Update(dt);
	scn.Draw(dt);

	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glRasterPos2f(0.5f, 0.9f);
	Printf("Text");

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();   
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glEnable(GL_DEPTH_TEST);

	SwapBuffers();
};

void FizzyWindow::OnKeyboard(i32 key, bool down)
{
	if(key == VK_ESCAPE && down)
	{
		Close();
	}
};

void FizzyWindow::OnCreate()
{
	GLWindowEx::OnCreate();
	glex::Load();
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glClearColor(0,0,0,1);

	glViewport(0,0,windowResolution.x, windowResolution.y);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
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

	gameTime.Update();
};

void FizzyWindow::OnDestroy()
{
};

void FizzyWindow::OnIdle()
{
	Redraw();
};