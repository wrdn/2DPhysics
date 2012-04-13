#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
using namespace std;

World::World(void) : zoom(-3.45f), objects(0), GLOBAL_FILL_MODE(GL_LINE), drawBoundingCircles(false) {}
World::~World(void) { UnLoad(); }

void DrawCircle(float2 &pos, f32 radius)
{
	// for a more efficient way of drawing a circle, see http://slabode.exofire.net/circle_draw.shtml
	glEnable(GL_LINE_SMOOTH);
	glBegin(GL_LINE_LOOP);
	for(u32 i=0;i<360;++i)
	{
		f32 f = DEGTORAD(i);
		glVertex2f(pos.x() + sin(f) * radius, pos.y() + cos(f) * radius);
	}
	glEnd();
};

void World::Draw()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();

	if(zoom <= 0.05f) zoom = 0.05f;
	glScalef(zoom,zoom,1);

	glTranslatef(cameraPosition.x(), cameraPosition.y(), 0);

	for(u32 i=0;i<TOTAL_OBJECT_COUNT;++i)
	{
		//objects[i]->rotation += 0.1f;
		//if(objects[i]->rotation >= 360) { objects[i]->rotation -= 360; }

		objects[i]->fillMode = GLOBAL_FILL_MODE; // useful for debugging collision detection/response
		objects[i]->Draw();
	}
	
	// debug functionality: draw bounding circles
	if(drawBoundingCircles)
	{
		for(u32 i=0;i<TOTAL_OBJECT_COUNT;++i)
		{
			DrawCircle(objects[i]->position, objects[i]->boundingCircleRadius);
		}
	}

	glPopMatrix();
};

float2 CurrentForce(const SimBody &s)
{
	float2 totalForce = s.force;
	totalForce += SimBody::gravity*s.mass;
	return totalForce;
};
float2 CurrentForce(const float2 &pos, const float2 &vel, const SimBody &s)
{
	float2 totalForce = s.force;
	totalForce += SimBody::gravity*s.mass;
	return totalForce;
};

void rkintegrate(SimBody &s, f32 dt)
{
	float2 acceleration = CurrentForce(s)/s.mass;

	float2 xk1, xk2, xk3, xk4;
	float2 vk1, vk2, vk3, vk4;

	// k1
	{
		xk1 = s.velocity * dt;
		vk1 = acceleration * dt;
	}

	// k2
	{
		float2 midvelocity = s.velocity + (vk1 * 0.5f);
		xk2 = midvelocity * dt;
		vk2 = (CurrentForce(s.position + (xk1 * 0.5f), midvelocity, s) / s.mass) * dt;
	}

	// k3
	{
		float2 midvelocity = s.velocity + (vk2 * 0.5f);
		xk3 = midvelocity * dt;
		vk3 = (CurrentForce(s.position + (xk2 * 0.5f), midvelocity, s) / s.mass) * dt;
	}

	// k4
	{
		float2 midvelocity = s.velocity + vk3;
		xk4 = midvelocity * dt;
		vk4 = (CurrentForce(s.position + xk3, midvelocity, s) / s.mass) * dt;
	}

	s.position += (xk1 + xk2*2.0f + xk3*2.0f + xk4) / 6.0f;
	s.velocity += (vk1 + vk2*2.0f + vk3*2.0f + vk4) / 6.0f;

	//float2 xk2_2 = xk2*2.0f, xk3_2 = xk3*2.0f;
	//float2 vk2_2 = vk2*2.0f, vk3_2 = vk3*2.0f;
	//s.position += (xk1 + xk2_2 + xk3_2 + xk4) / 6.0f;
	//s.velocity += (vk1 + vk2_2 + vk3_2 + vk4) / 6.0f;
};

void World::update_boxes(f32 dt)
{
	for(u32 i=0;i<BOX_COUNT;++i)
	{
		Box *b = (Box*)objects[i];
		if(!b->update) continue;

		rkintegrate(*b, dt);
		b->position.y( max(0, b->position.y()));
		b->position.y( min(b->position.y(), 0.5));

		float2 mtd;
		
		// test for collisions (but DONT test collisions with self)
		for(u32 j=0;j<i;++j)
		{
			Box *ob = (Box*)objects[j];

			// Quick bounding circle rejection
			if(!BoundingCircleIntersects(*b, *ob)) continue;

			f32 t=0;
			if(Intersect(*b, *ob, mtd, t))
			{
				b->position -= mtd * (t*0.5f);
				ob->position += mtd * (t*0.5f);
			}
		}

		for(u32 j=i+1;j<BOX_COUNT;++j)
		{
			Box *ob = (Box*)objects[j];

			if(!BoundingCircleIntersects(*b, *ob)) continue;

			f32 t = 0;
			if(Intersect(*b, *ob, mtd, t))
			{
				b->position -= mtd * (t*0.5f);
				ob->position += mtd * (t*0.5f);
			}
		}
	}
};

void World::Update(f32 dt)
{
	dt = 1.0f / updateRate;

	update_boxes(dt);

	//for(u32 i=0;i<1001;++i)
	//{
	//	SimBody &body = *objects[i];
	//	Box *b = (Box*)&objects[i];

	//	if(!body.update) continue;

	//	// for all the boxes
	//	for(u32 i=0;i<BOX_COUNT;++i)
	//	{
	//		Box *ibox = (Box*)objects[i];


	//		/*for(u32 j=0;j<i;++j) // boxes BEFORE i
	//		{
	//			Box *otherbox = (Box*)objects[j];

	//			if(Intersect(*ibox, *otherbox))
	//			{
	//				ibox->update = false;
	//				++i; continue;
	//			}
	//		}
	//		for(u32 j=i+1;j<BOX_COUNT;++j) // boxes AFTER i
	//		{
	//			Box *otherbox = (Box*)objects[j];

	//			if(Intersect(*ibox, *otherbox))
	//			{
	//				ibox->update = false;
	//				++i; continue;
	//			}
	//		}*/
	//	}

		//rkintegrate(body, dt);

		// HACK: make sure objects can't go below Y=0. We can now do collision detection to
		// make sure they don't penetrate each other, but also never go below Y=0
		// Later on we could add similar clamps for the X axis (left and right), and possibly an upper range for the Y
		// axis, so we can keep everything inside a box. Eventually, we will do proper collisions against a plane
		// so it can interact with the edges properly
	//	body.position.y( max(0, body.position.y()) );
	//}
};