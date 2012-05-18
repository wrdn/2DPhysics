#include "FizzyWindow.h"
#include "Collision.h"

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

#define MAXSAMPLES 100
int tickindex=0;
float ticksum=0;
float ticklist[MAXSAMPLES];
double CalcAverageTick(float newtick)
{
    ticksum-=ticklist[tickindex];  /* subtract value falling off */
    ticksum+=newtick;              /* add new value */
    ticklist[tickindex]=newtick;   /* save new value so it can be subtracted later */
    if(++tickindex==MAXSAMPLES)    /* inc buffer index */
        tickindex=0;

    /* return average */
    return((double)ticksum/MAXSAMPLES);
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
	glRasterPos2f(0.4f, 0.9f);

	//prevTime = currentTime;
	//currentTime = 1.0f/scn.frameTime;
	//float avgTime = currentTime * 0.9 + prevTime*0.1f;

	float avgTime = 1.0f/(float)CalcAverageTick((float)scn.frameTime);

	Printf("Frame Rate: %d", (int)avgTime);
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
	case 'c':
		{
			if(!down)
			{
				scn.netController->cs.Lock();
				scn.netController->netAlive = false;
				scn.netController->cs.Unlock();

				scn.netController->Close();

				scn.primaryTaskPool_netThread->SigKill();
				scn.primaryTaskPool_netThread->InitPool(1);

				scn.netController->writeOffset = 0;
				memset(scn.netController->buff, 0, sizeof(scn.netController->buff));
				
				scn.netController->Close();
				//if(scn.netController->Connect("127.0.0.1", 80))
				//if(scn.netController->Connect(
				//	scn.conf.Read("ConnectionAddress","127.0.0.1").c_str(),
				//	scn.conf.Read("Port", (unsigned short)9171U)))
				//if(scn.netController->Connect(
				//	scn.conf.Read("ConnectionAddress","127.0.0.1").c_str(),
				//	9171))

				string caddr = scn.conf.Read("ConnectionAddress", "127.0.0.1");
				const char *c = caddr.c_str();

				unsigned short _port = scn.conf.Read("Port", (unsigned short)9171U);

				if(scn.netController->Connect(c, _port))
				{
					scn.netController->connectionType = NetworkController::ClientConnection;

					scn.netController->peers.clear();

					Peer p; p.socket = scn.netController->sock;
					scn.netController->peers.push_back(p);
				}
				else
				{
					scn.netController->Close();
					//if(scn.netController->StartListening(scn.conf.Read("Port", (unsigned short)9171U)))
					if(scn.netController->StartListening(_port))
					{
						cout << "started listening again" << endl;
					}
				}

				scn.netController->cs.Lock();
				scn.netController->netAlive = true;
				scn.netController->cs.Unlock();
				
				scn.primaryTaskPool_netThread->AddTask(Task(netthread, scn.netController));

				//scn.netController->netAlive = false;
				//scn.primaryTaskPool_netThread->Join();
				//scn.netController->netAlive = true;
				//scn.netController->Close();
				//scn.netController->connectionType = NetworkController::ClientConnection;
				//scn.netController->Connect("127.0.0.1", 80);
				//scn.primaryTaskPool_netThread->AddTask(Task(netthread, scn.netController));
			}
		} break;
	case 187: // +
		scn.set_zoom(scn.get_zoom() + dt * zoomSpeed);

		{
			glViewport(0,0,windowResolution.x,windowResolution.y);
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
			glLoadIdentity();
		}

		break;
	case 189: // -
		scn.set_zoom(scn.get_zoom() - dt * zoomSpeed);

		{
			glViewport(0,0,windowResolution.x,windowResolution.y);
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
			glLoadIdentity();
		}

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
	/*case 'r':
		scn.alive = false;
		scn.primaryTaskPool->Join();
		scn.Load();
		return;
		break;*/
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
	//scn.primaryTaskPool->SigKill();

	scn.primaryTaskPool_physThread->SigKill();
	scn.primaryTaskPool_netThread->SigKill();

	scn.Unload();
};

void FizzyWindow::OnIdle()
{
	//return;
	//scn.Update(gameTime.Update());
	Redraw();
};

void FizzyWindow::OnMouseButton(gxbase::GLWindow::MouseButton button, bool down)
{
	if(button == gxbase::GLWindow::MouseButton::MBLeft)
	{
		if(down)
		{
			scn.mouseDown=true;
			float2 point(scn.mx, scn.my);

			vector<SimBody*> &objects = scn.objects;

			for(int i=4;i<objects.size();++i)
			{
				if(objects[i]->owner != SimBody::whoami) continue;
				if(PointInCircle(point, Circle(objects[i]->position, objects[i]->boundingCircleRadius)))
				{
					scn.jointedBody = objects[i];
					break;
				}
			}
		}
		else
		{
			scn.mouseDown=false;
			scn.jointedBody=0;
		}
	}
};

float2 FizzyWindow::MouseToSpace(int x, int y, int windowResY)
{
	GLdouble model[16], proj[16];
	GLint view[4];
	glGetDoublev(GL_MODELVIEW_MATRIX, model);
	glGetDoublev(GL_PROJECTION_MATRIX, proj);
	glGetIntegerv(GL_VIEWPORT, view);
	GLdouble tmx, tmy, tmz;

	gluUnProject(x, windowResY - y, 0, model, proj, view, &tmx, &tmy, &tmz);

	return float2(-scn.camPos.x+ (tmx/scn.zoom), -scn.camPos.y+ (-tmy/scn.zoom));
};

void FizzyWindow::OnMouseMove(i32 x, i32 y)
{
	float2 v = MouseToSpace(x, y, windowResolution.y);
	scn.mx = v.x;
	scn.my = v.y;
};