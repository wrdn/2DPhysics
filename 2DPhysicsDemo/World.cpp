#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include "SAT.h"

World::World() : zoom(-3.45f), objects(0) {};
World::~World() { Unload(); };

void World::Update(f32 dt)
{
	dt = 1.0f/60.0f;

	const float2 &gravity = SimBody::gravity;

	// add gravity
	for(u32 i=1;i<total_cnt;++i)
	{
		SimBody &obj = *objects[i];
		float2 accel = gravity/obj.mass;
		obj.velocity += accel*dt;
		obj.position += obj.velocity * dt;
	}

	for(u32 i=0;i<total_cnt;++i)
	{
		for(u32 j=0;j<total_cnt;++j)
		{
			if(i==j)continue;

			SimBody &obj = *objects[i];
			SimBody &other = *objects[j];
			
			obj.Collide(other, dt);
		}
	}
};

void World::Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
	glScalef(zoom,zoom,1);
	glTranslatef(camPos.x, camPos.y, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	
	const SimBody &wall = *objects[0];

	DrawLine(wall.position+wall.vertices[0], wall.position+wall.vertices[1],
		1,0,0,2.0f);

	//DrawLine(objects[0]->vertices[0], objects[0]->vertices[1], 1,0,0,2.0f);

	for(u32 i=1;i<total_cnt;++i)
	{
		objects[i]->Draw();
	}

	glPopMatrix();
};