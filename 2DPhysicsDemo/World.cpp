#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include "SAT.h"

World::World() : zoom(-3.45f), objects(0) {};
World::~World() { Unload(); };

void World::Update(f32 dt)
{
	dt = 1.0f/220.0f;

	const float2 &gravity = SimBody::gravity;

	/************************************/
	/************ ADD FORCES ************/
	/************************************/
	for(u32 i=0;i<total_cnt;++i)
	{
		SimBody &obj = *objects[i];
		
		if(obj.Unmovable()) continue;

		obj.AddForce(float2(0, meters(-9.81f)*obj.mass));
	}

	/************************************/
	/********** TEST COLLISION **********/
	/************************************/
	for(u32 i=0;i<total_cnt;++i)
	{
		SimBody &obj = *objects[i];

		for(u32 j=0;j<total_cnt;++j)
		{
			if(i==j) continue;

			SimBody &other = *objects[j];

			if(obj.Unmovable() && other.Unmovable()) continue;

			obj.Collide(other, dt);
		}
	}

	/***********************************/
	/************ INTEGRATE ************/
	/***********************************/
	for(u32 i=0;i<total_cnt;++i)
	{
		if(objects[i]->Unmovable()) continue;

		objects[i]->Update(dt);
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
	
	{ // bottom wall
		const SimBody &wall = *objects[0];
		DrawLine(wall.position+wall.vertices[0], wall.position+wall.vertices[1], 1,0,0,2.0f);
	}
	{ // left wall
		const SimBody &wall = *objects[1];
		DrawLine(wall.position+wall.vertices[0], wall.position+wall.vertices[1], 1,0,0,2.0f);
	}
	{ // right wall
		const SimBody &wall = *objects[2];
		DrawLine(wall.position+wall.vertices[0], wall.position+wall.vertices[1], 1,0,0,2.0f);
	}
	{ // top wall
		const SimBody &wall = *objects[3];
		DrawLine(wall.position+wall.vertices[0], wall.position+wall.vertices[1], 1,0,0,2.0f);
	}

	//DrawLine(objects[0]->vertices[0], objects[0]->vertices[1], 1,0,0,2.0f);

	for(u32 i=1;i<total_cnt;++i)
	{
		objects[i]->Draw();
	}

	glPopMatrix();
};