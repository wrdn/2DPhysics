#include "World.h"
#include "GraphicsUtils.h"
#include "util.h"
#include "SATCollision.h"

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
		f32 f = DEGTORAD((f32)i);
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

		glPointSize(1);
		glBegin(GL_POINTS);
		glVertex2f(objects[i]->position.x(), objects[i]->position.y());
		glEnd();
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
	f32 tmp = pos.x()+vel.x();
	if(tmp){};

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
};

void World::update_triangles(f32 dt)
{
	for(u32 i=BOX_COUNT;i<TOTAL_OBJECT_COUNT;++i)
	{
		Triangle *t = (Triangle*)objects[i];
		t->rotation += 0.02f;
		t->rotation = t->rotation >= 360.0f ? t->rotation - 360.0f : t->rotation;
		t->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(t->rotation));

		float2 mtd;

		// Triangle - box updates
		for(u32 j=0;j<BOX_COUNT;++j)
		{
			Box *b = (Box*)objects[j];
			//if(!BoundingCircleIntersects(*t, *b)) continue;

			f32 tx=0;
			if(IntersectOBBTriangle(*b, *t, mtd, tx))
			{
				t->objectMaterial.SetObjectColor(Color::WHITE);
				b->objectMaterial.SetObjectColor(Color::WHITE);
			}
			else
			{
				t->objectMaterial.SetObjectColor(Color::RED);
				b->objectMaterial.SetObjectColor(Color::RED);
			}
		}

		// Triangle - triangle updates
		for(u32 j=BOX_COUNT;j<i;++j)
		{
			Triangle *ot = (Triangle*)objects[j];
			if(!BoundingCircleIntersects(*t, *ot)) continue;

			f32 tx=0;
			if(IntersectTriangleTriangle(*t, *ot, mtd, tx))
			{
				t->objectMaterial.SetObjectColor(Color::WHITE);
				ot->objectMaterial.SetObjectColor(Color::WHITE);
			}
			else
			{
				t->objectMaterial.SetObjectColor(Color::RED);
				ot->objectMaterial.SetObjectColor(Color::RED);
			}
		}
		for(u32 j=i+1;j<TOTAL_OBJECT_COUNT;++j)
		{
			Triangle *ot = (Triangle*)objects[j];
			if(!BoundingCircleIntersects(*t, *ot)) continue;

			f32 tx=0;
			if(IntersectTriangleTriangle(*t, *ot, mtd, tx))
			{
				t->objectMaterial.SetObjectColor(Color::WHITE);
				ot->objectMaterial.SetObjectColor(Color::WHITE);
			}
			else
			{
				t->objectMaterial.SetObjectColor(Color::RED);
				ot->objectMaterial.SetObjectColor(Color::RED);
			}
		}
	}
};

void World::update_boxes(f32 dt)
{
	for(u32 i=0;i<BOX_COUNT;++i)
	{
		Box *b = (Box*)objects[i];
		if(!b->update) continue;

		//rkintegrate(*b, dt);
		b->position.y( max(0, b->position.y()));
		b->position.y( min(b->position.y(), 0.5f));

		b->rotation += 0.02f;
		b->rotation = b->rotation >= 360.0f ? b->rotation - 360.0f : b->rotation;
		b->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(b->rotation));
		continue;

		float2 mtd;
		
		// test for collisions (but DONT test collisions with self)
		for(u32 j=0;j<i;++j)
		{
			Box *ob = (Box*)objects[j];
			if(!BoundingCircleIntersects(*b, *ob)) continue;

			f32 t=0;
			if(IntersectOBB(*b, *ob, mtd, t))
			{
				b->objectMaterial.SetObjectColor(Color::WHITE);
				ob->objectMaterial.SetObjectColor(Color::WHITE);
				//b->position -= mtd * (t*0.5f);
				//ob->position += mtd * (t*0.5f);
			}
			else
			{
				b->objectMaterial.SetObjectColor(Color::RED);
				ob->objectMaterial.SetObjectColor(Color::RED);
			}
		}

		for(u32 j=i+1;j<BOX_COUNT;++j)
		{
			Box *ob = (Box*)objects[j];
			if(!BoundingCircleIntersects(*b, *ob)) continue;

			f32 t=0;
			if(IntersectOBB(*b, *ob, mtd, t))
			{
				b->objectMaterial.SetObjectColor(Color::WHITE);
				ob->objectMaterial.SetObjectColor(Color::WHITE);
				//b->position -= mtd * (t*0.5f);
				//ob->position += mtd * (t*0.5f);
			}
			else
			{
				b->objectMaterial.SetObjectColor(Color::RED);
				ob->objectMaterial.SetObjectColor(Color::RED);
			}
		}
	}
};

void World::Update(f32 dt)
{
	dt = 1.0f / updateRate;

	//update_boxes(dt);
	update_triangles(dt);
};