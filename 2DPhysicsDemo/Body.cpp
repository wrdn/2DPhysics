#include "Body.h"
#include <GXBase.h>
#include "util.h"
#include <math.h>

Body::~Body() {};

void Body::GetVertices(vector<float2> &out)
{
	out.clear();

	float cos = (float)cosf(rotation);
	float sin = (float)sinf(rotation);

	for(int i=0;i<vertices.size();++i)
	{
		float x = vertices[i].x * cos - vertices[i].y * sin;
		float y = vertices[i].y * cos + vertices[i].x * sin;
		x += position.x;
		y += position.y;

		out.push_back(float2(x,y));
	}
};

void Body::Draw()
{
	/*glPushMatrix();
	
	float2 x = position;
	glTranslatef(x.x, x.y,0);
	
	float RotationInDegrees = RADTODEG(rotation);
	glRotatef(RotationInDegrees,0,0,1);

	float2 h = 0.5f * width;
	float2 v1 = float2(-h.x, -h.y);
	float2 v2 = float2( h.x, -h.y);
	float2 v3 = float2( h.x,  h.y);
	float2 v4 = float2(-h.x,  h.y);

	glColor3f(0.8f, 0.8f, 0.9f);

	glBegin(GL_LINE_LOOP);
	glVertex2f(v1.x, v1.y);
	glVertex2f(v2.x, v2.y);
	glVertex2f(v3.x, v3.y);
	glVertex2f(v4.x, v4.y);
	glEnd();

	glPopMatrix();*/

	glPushMatrix();
	
	float2 x = position;
	glTranslatef(x.x, x.y,0);
	glRotatef(RADTODEG(rotation), 0,0,1);

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<vertices.size();++i)
	{
		glVertex2f(vertices[i].x, vertices[i].y);
	}
	glEnd();

	glPopMatrix();
};

Body::Body()
{
	position.set(0.0f, 0.0f);
	rotation = 0.0f;
	velocity.set(0.0f, 0.0f);
	angularVelocity = 0.0f;
	force.set(0.0f, 0.0f);
	torque = 0.0f;
	friction = 0.2f;

	width.set(1.0f, 1.0f);
	mass = FLT_MAX;
	invMass = 0.0f;
	I = FLT_MAX;
	invI = 0.0f;

	m_radius = 0.009f;
}

void Body::Set(const float2& w, float m)
{
	position.set(0.0f, 0.0f);
	rotation = 0.0f;
	velocity.set(0.0f, 0.0f);
	angularVelocity = 0.0f;
	force.set(0.0f, 0.0f);
	torque = 0.0f;
	friction = 0.2f;

	width = w;
	mass = m;

	if (mass < FLT_MAX)
	{
		invMass = 1.0f / mass;
		I = mass * (width.x * width.x + width.y * width.y) / 12.0f;
		invI = 1.0f / I;
	}
	else
	{
		invMass = 0.0f;
		I = FLT_MAX;
		invI = 0.0f;
	}
}
