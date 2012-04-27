#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include "SAT.h"

using namespace std;

World::World(void) : zoom(-3.45f), objects(0), GLOBAL_FILL_MODE(GL_LINE), drawBoundingCircles(false) {}
World::~World(void) { UnLoad(); }
void DrawCircle(float2 &pos, f32 radius);
void DrawPoint(float2 pos, float r, float g, float b);

void World::Draw(f32 dt)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	if(zoom <= 0.05f) zoom = 0.05f;
	//glScalef(zoom,zoom,1);
	glScalef(0.02f,0.02f,1);
	glTranslatef(cameraPosition.x, cameraPosition.y, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	
	f32 t=1.0f;
	float2 N, CA[2], CB[2]; u32 Cnum=0;

	body_box->rotation_in_rads += (PI/4)*dt;
	body_box->CalculateRotationMatrix();
	body_triangle->rotation_in_rads -= (PI/6) * dt;
	body_triangle->CalculateRotationMatrix();

	bool hasCollided = SAT::Collide(*body_box, *body_triangle, N, t);
	if(hasCollided)
	{
		body_box->objectMaterial.SetObjectColor(Color::RED);
		body_triangle->objectMaterial.SetObjectColor(Color::RED);

		FindContacts(*body_box, *body_triangle, N, t, CA, CB, Cnum);

		for(u32 i=0;i<Cnum;++i)
		{
			DrawPoint(CA[i], 1,0,0);
			DrawPoint(CB[i], 1,0,0);
		}
		glColor3f(1,1,1);
	}
	else
	{
		body_box->objectMaterial.SetObjectColor(Color::WHITE);
		body_triangle->objectMaterial.SetObjectColor(Color::WHITE);
	}

	body_box->Draw();
	body_triangle->Draw();

	//bool hasCollided = Collide(*body_box, *body_triangle, N, t);

	/*float t=1.0f;
	Vector N, CA[2], CB[2]; int Cnum=0;
	
	body_box->angle += (PI/4) * dt;
	body_box->orientationMatrix = Matrix(body_box->angle);
	
	body_triangle->angle -= (PI/6) * dt;
	body_triangle->orientationMatrix = Matrix(body_triangle->angle);

	bool hasCollided = Collide(*body_box, *body_triangle, N, t);
	//bool hasCollided = Collide(*body_triangle, *body_box, N, t);

	if(hasCollided)
	{
		body_box->bodyColor = body_triangle->bodyColor = col(1,1,1);

		FindContacts2(
			&body_box->vertices[0], body_box->vertices.size(), body_box->pos, Vector(0,0), body_box->orientationMatrix,
			&body_triangle->vertices[0], body_triangle->vertices.size(), body_triangle->pos, Vector(0,0), body_triangle->orientationMatrix,
			N, t, CA, CB, Cnum);
		
		glPushMatrix();
		glBegin(GL_LINES);
		glVertex2f(CB[0].x, CB[0].y);
		glVertex2f(N.x, N.y);
		glEnd();
		glPopMatrix();

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
	body_triangle->Render();*/

	glPopMatrix();
};

void DrawPoint(float2 pos, float r, float g, float b)
{
	glPushMatrix();
	glColor3f(r,g,b);
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