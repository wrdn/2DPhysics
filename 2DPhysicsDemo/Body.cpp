#include "Body.h"
#include <GXBase.h>
#include "util.h"

Body::~Body() {};

void Body::Draw()
{
	glPushMatrix();
	
	Vector2f x = position;
	glTranslatef(x.x, x.y,0);
	
	float RotationInDegrees = RADTODEG(rotation);
	glRotatef(RotationInDegrees,0,0,1);

	Vector2f h = 0.5f * width;
	Vector2f v1 = Vector2f(-h.x, -h.y);
	Vector2f v2 = Vector2f( h.x, -h.y);
	Vector2f v3 = Vector2f( h.x,  h.y);
	Vector2f v4 = Vector2f(-h.x,  h.y);

	glColor3f(0.8f, 0.8f, 0.9f);

	glBegin(GL_LINE_LOOP);
	glVertex2f(v1.x, v1.y);
	glVertex2f(v2.x, v2.y);
	glVertex2f(v3.x, v3.y);
	glVertex2f(v4.x, v4.y);
	glEnd();

	glPopMatrix();
};

Body::Body()
{
	position.Set(0.0f, 0.0f);
	rotation = 0.0f;
	velocity.Set(0.0f, 0.0f);
	angularVelocity = 0.0f;
	force.Set(0.0f, 0.0f);
	torque = 0.0f;
	friction = 0.2f;

	width.Set(1.0f, 1.0f);
	mass = FLT_MAX;
	invMass = 0.0f;
	I = FLT_MAX;
	invI = 0.0f;
}

void Body::Set(const Vector2f& w, float m)
{
	position.Set(0.0f, 0.0f);
	rotation = 0.0f;
	velocity.Set(0.0f, 0.0f);
	angularVelocity = 0.0f;
	force.Set(0.0f, 0.0f);
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
