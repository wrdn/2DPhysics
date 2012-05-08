#include "Body.h"
#include "util.h"

void CalculateInertia(vector<float2> &vertices,
	float mass, float &inertia, float &invInertia)
{
	if(vertices.size() == 1) { inertia = invInertia = 0; return; }

	float denom=0, numer=0;
	float2 *A = &vertices[0];

	for(int j=vertices.size()-1,i=0;i<vertices.size();j=i,i++)
	{
		float2 P0 = A[j], P1 = A[i];
		float a = fabs(P0 ^ P1);
		float b = P1.dot(P1) + P1.dot(P0) + P0.dot(P0);

		denom += (a * b);
		numer += a;
	}
	inertia = (mass/6) * (denom/numer);
	invInertia = 1.0f/inertia;
};

void Body::Draw()
{
	glPushMatrix();
	glColor3f(1,1,1);

	glTranslated(pos.x, pos.y, 0);
	glRotatef((rotation), 0,0,-1);

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<vertices.size();++i)
		glVertex2f(vertices[i].x, vertices[i].y);
	glEnd();

	glPopMatrix();
};