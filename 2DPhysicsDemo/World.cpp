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
		glVertex2f(pos.x + sin(f) * radius, pos.y + cos(f) * radius);
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

	glTranslatef(cameraPosition.x, cameraPosition.y, 0);

	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	//box->Draw();
	//triangle->Draw();

	for(u32 i=0;i<TOTAL_OBJECT_COUNT;++i)
	{
		SimBody &o = *objects[i];

		o.fillMode = GLOBAL_FILL_MODE;
		
		// Draw object
		o.Draw();

		// Draw vertices
		glPointSize(1);
		glBegin(GL_POINTS);
		glVertex2f(o.position.x, o.position.y);
		glEnd();
		glPushMatrix();
		glPointSize(5);
		glTranslatef(o.position.x, o.position.y, 0);
		glRotatef(o.rotation,0,0,1);
		glBegin(GL_POINTS);
		for(int j=0;j<o.vertices.size();++j)
			glVertex2f(o.vertices[j].x, o.vertices[j].y);
		glEnd();
		glPopMatrix();
	}
	
	// Draw bounding circles
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
	f32 tmp = pos.x+vel.x;
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

void World::test_collisions_tri_box(f32 dt)
{
	if(dt){}
	Triangle *triangle = (Triangle*)objects[1];
	Box *box = (Box*)objects[0];

	triangle->position.x = 0.01f;
	triangle->rotation += 0.02f;

	box->rotation = 0;

	triangle->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(triangle->rotation));
	box->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(box->rotation));

	float2 mtd;
	f32 tx=0;

	if(Intersect(*triangle, *box, mtd, tx))
	{
		triangle->objectMaterial.SetObjectColor(Color::WHITE);
		box->objectMaterial.SetObjectColor(Color::WHITE);
	}
	else
	{
		triangle->objectMaterial.SetObjectColor(Color::RED);
		box->objectMaterial.SetObjectColor(Color::RED);
	}

	if(Intersect(*box, *triangle, mtd, tx))
	{
		triangle->objectMaterial.SetObjectColor(Color::WHITE);
		box->objectMaterial.SetObjectColor(Color::WHITE);
	}
	else
	{
		triangle->objectMaterial.SetObjectColor(Color::RED);
		box->objectMaterial.SetObjectColor(Color::RED);
	}
};

void World::update_triangles(f32 dt)
{
	if(dt){}

	for(u32 i=BOX_COUNT;i<TOTAL_OBJECT_COUNT;++i)
	{
		Triangle *t = (Triangle*)objects[i];

		f32 v[] = { -1, 1 };
		t->rotation += 0.02f * v[i%2];
		t->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(t->rotation));

		float2 mtd;
		f32 tx=0;

		// Triangle - triangle updates
		for(u32 j=BOX_COUNT;j<TOTAL_OBJECT_COUNT;++j)
		{
			if(i == j) continue; // dont test self

			Triangle *ot = (Triangle*)objects[j];
			ot->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(ot->rotation));

			if(Intersect(*t, *ot, mtd, tx))
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
	if(dt){}

	for(u32 i=0;i<BOX_COUNT;++i)
	{
		Box *b = (Box*)objects[i];
		if(!b->update) continue;

		//rkintegrate(*b, dt);
		b->position.y = max(0, b->position.y);

		b->rotation += randflt(0.02f, 0.05f);
		b->rotation = b->rotation >= 360.0f ? b->rotation - 360.0f : b->rotation;
		b->_cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(b->rotation));

		float2 mtd;
		f32 t=0;

		for(u32 j=0;j<BOX_COUNT;++j)
		{
			if(i==j) continue; // dont test self

			Box *otherBox = (Box*)objects[j];
			if(!BoundingCircleIntersects(*b, *otherBox)) continue;

			if(Intersect(*b, *otherBox, mtd, t))
			{
				b->objectMaterial.SetObjectColor(Color::WHITE);
				otherBox->objectMaterial.SetObjectColor(Color::WHITE);
			}
			else
			{
				b->objectMaterial.SetObjectColor(Color::RED);
				otherBox->objectMaterial.SetObjectColor(Color::RED);
			}
		}
	}
};

f32 t; float2 tmp;
void World::Update(f32 dt)
{
	dt = 1.0f / updateRate;

	/*triangle->rotation += 0.01f;
	box->rotation -= 0.01f;

	triangle->CalculateRotationMatrix();
	box->CalculateRotationMatrix();

	if(Intersect(*box, *triangle, tmp, t))
	{
		box->objectMaterial.SetObjectColor(Color::WHITE);
		triangle->objectMaterial.SetObjectColor(Color::WHITE);
	}
	else
	{
		box->objectMaterial.SetObjectColor(Color::RED);
		triangle->objectMaterial.SetObjectColor(Color::RED);
	}*/

	//test_collisions_tri_box(0);
	//update_triangles(dt);
	update_boxes(dt);
};