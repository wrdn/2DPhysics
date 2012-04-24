#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include "SATCollision.h"
#include "Contacts.h"

using namespace std;

World::World(void) : zoom(-3.45f), objects(0), GLOBAL_FILL_MODE(GL_LINE), drawBoundingCircles(false) {}
World::~World(void) { UnLoad(); }
void DrawCircle(float2 &pos, f32 radius);
void DrawPoint(Vector pos, float r, float g, float b);

void World::Draw(f32 dt)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	if(zoom <= 0.05f) zoom = 0.05f;
	//glScalef(zoom,zoom,1);
	glScalef(0.02,0.02,1);
	glTranslatef(cameraPosition.x, cameraPosition.y, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	float t=1.0f;
	Vector N, CA[2], CB[2]; int Cnum=0;
	
	body_box->angle += (PI/4) * dt;
	body_box->orientationMatrix = Matrix(body_box->angle);
	bool hasCollided = Collide(*body_box, *body_triangle, N, t);

	if(hasCollided)
	{
		body_box->bodyColor = body_triangle->bodyColor = col(1,1,1);

		glPushMatrix();
		glBegin(GL_LINES);
		glVertex2f(body_box->pos.x, body_box->pos.y);
		glVertex2f(N.x, N.y);
		glEnd();
		glPopMatrix();

		FindContacts2(
			&body_box->vertices[0], body_box->vertices.size(), body_box->pos, Vector(0,0), body_box->orientationMatrix,
			&body_triangle->vertices[0], body_triangle->vertices.size(), body_triangle->pos, Vector(0,0), body_triangle->orientationMatrix,
			N, t, CA, CB, Cnum);
		
		for(int i=0;i<Cnum;++i)
		{
			DrawPoint(CA[i], 1,0,0);
			DrawPoint(CB[i], 1,0,0);
		}
		glColor3f(1,1,1);
	}
	else
	{
		body_box->bodyColor = body_triangle->bodyColor = col(1,0,0);
	}
	
	body_box->Render();
	body_triangle->Render();
	glPopMatrix();
};

void DrawPoint(Vector pos, float r, float g, float b)
{
	glPushMatrix();
	glColor3f(1,0,0);
	glPointSize(5);
	glBegin(GL_POINTS);
	glVertex2f(pos.x, pos.y);
	glEnd();
	glColor3f(1,1,1);
	glPopMatrix();
};

void DrawCircle(float2 &pos, f32 radius)
{
	// for a more efficient way of drawing a circle, see http://slabode.exofire.net/circle_draw.shtml
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_LOOP);
	for(u32 i=0;i<360;++i)
	{
		f32 f = DEGTORAD((f32)i);
		glVertex2f(pos.x + sin(f) * radius, pos.y + cos(f) * radius);
	}
	glEnd();
};

void World::Update(f32 dt)
{
};