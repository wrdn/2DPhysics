#include "GraphicsUtils.h"
#include "ResourceManager.h"

MeshHandle Create2DBox(f32 width, f32 height, const c8 *resourceName)
{
	f32 w2 = width / 2.0f, h2 = height / 2.0f;

	// The Create2DBox() function is only called at Load time. However, since we can reload the entire app at runtime,
	// when we may have a different box width and height, we'll delete the resource and recreate it
	// Alternative approach: create a 1x1 box once, then scale it by the width and height
	ResourceManager::get().RemoveResource(resourceName);

	MeshHandle mh = ResourceManager::get().CreateAndGetResource<Mesh>(resourceName);
	if(mh->Valid()) return mh; // dont recreate a mesh under the resourceName

	mh->SetName(resourceName);
	mh->SetGeometryDataFormat(GL_QUADS);

	VERTEX verts[4];

	// CCW vertex order
	verts[0] = VERTEX( float2(-w2, h2), float2(0, 1) ); // top left
	verts[1] = VERTEX( float2(-w2, -h2), float2(0, 0) ); // bottom left
	verts[2] = VERTEX( float2(w2, -h2), float2(1, 0) ); // bottom right
	verts[3] = VERTEX( float2(w2, h2), float2(1, 1) ); // top right

	u32 indices[] = { 0, 1, 2, 3 };

	if(!mh->BuildVBO(verts, 4, indices, 4))
	{
		mh.reset();
		ResourceManager::get().RemoveResource(mh->GetResourceID());
	}

	return mh;
};

MeshHandle CreateEquilateralTriangle(f32 length, const c8 *resourceName)
{
	// The CreateEquilateralTriangle() function is only called at Load time. However, since we can reload the entire app at runtime,
	// when we may have a different box width and height, we'll delete the resource and recreate it
	// Alternative approach: create a 1x1 box once, then scale it by the width and height
	ResourceManager::get().RemoveResource(resourceName);

	MeshHandle mh = ResourceManager::get().CreateAndGetResource<Mesh>(resourceName);
	if(mh->Valid()) return mh; // dont recreate a mesh under the resourceName

	mh->SetName(resourceName);

	VERTEX verts[3];

	f32 l2 = length;

	verts[0] = VERTEX( float2(0, l2), float2(0.5f, 1) ); // top
	verts[1] = VERTEX( float2(-l2, -l2), float2(0, 0) ); // bottom left
	verts[2] = VERTEX( float2(l2, -l2), float2(1, 0) ); // bottom right

	u32 indices[] = { 0, 1, 2 };

	if(!mh->BuildVBO(verts, 3, indices, 3))
	{
		mh.reset();
		ResourceManager::get().RemoveResource(mh->GetResourceID());
	}
	return mh;
};

MeshHandle CreateLine(float2 start, float2 end, const c8 *resourceName)
{
	ResourceManager::get().RemoveResource(resourceName);

	MeshHandle mh = ResourceManager::get().CreateAndGetResource<Mesh>(resourceName);
	if(mh->Valid()) return mh;

	mh->SetName(resourceName);

	VERTEX verts[2]; // ccw order
	verts[0] = VERTEX( float2(end.x, end.y), float2(1, 0) ); // right
	verts[1] = VERTEX( float2(start.x, start.y), float2(0, 0) ); // left
	u32 indices[] = { 0, 1 };

	if(!mh->BuildVBO(verts, 2, indices, 2))
	{
		mh.reset();
		ResourceManager::get().RemoveResource(mh->GetResourceID());
	}
	return mh;
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

void DrawLine(const float2 &start, const float2 &end,
	const float r, const float g, const float b, const float lineWidth)
{
	float outf=0; glGetFloatv(GL_LINE_WIDTH, &outf);
	glLineWidth(lineWidth);
	glColor3f(r,g,b);

	glBegin(GL_LINES);
	glVertex2fv(start.vec);
	glVertex2fv(end.vec);
	glEnd();

	glColor3f(1,1,1);
	glLineWidth(outf);
};