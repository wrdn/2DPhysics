#include "CBODY.h"
#include <GXBase.h>

CBODY::CBODY(void)
{
}

CBODY::~CBODY(void)
{
}

void CBODY::Draw()
{
	glPushMatrix();

	glColor3f(r,g,b);

	glTranslatef(position.x, position.y,0);
	glRotatef(rotation, 0,0,1);

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<vertices.size();++i)
	{
		Vector v = vertices[i];
		glVertex2f(v.x, v.y);
	}
	glEnd();

	glPopMatrix();

	glColor3f(1,1,1);
};