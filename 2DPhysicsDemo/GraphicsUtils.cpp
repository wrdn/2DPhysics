#include "GraphicsUtils.h"
#include "ResourceManager.h"

MeshHandle Create2DBox(f32 width, f32 height, const char *resourceName)
{
	f32 w2 = width / 2.0f, h2 = height / 2.0f;

	MeshHandle mh = ResourceManager::get().CreateAndGetResource<Mesh>(resourceName);
	if(mh->Valid()) return mh; // dont recreate a mesh under the resourceName

	mh->SetName(resourceName);
	mh->SetGeometryDataFormat(GL_QUADS);

	VERTEX verts[4];

	float2 sharedNormal(0,0);

	// CCW vertex order
	verts[0] = VERTEX( float2(-w2, h2),  sharedNormal, float2(0, 1) ); // top left
	verts[1] = VERTEX( float2(-w2, -h2), sharedNormal, float2(0, 0) ); // bottom left
	verts[2] = VERTEX( float2(w2, -h2),  sharedNormal, float2(1, 0) ); // bottom right
	verts[3] = VERTEX( float2(w2, h2),   sharedNormal, float2(1, 1) ); // top right

	u32 indices[] = { 0, 1, 2, 3 };

	if(!mh->BuildVBO(verts, 4, indices, 4))
	{
		mh.reset();
		ResourceManager::get().RemoveResource(mh->GetResourceID());
	}

	return mh;
};

MeshHandle CreateEquilateralTriangle(f32 length, const char *resourceName)
{
	f32 l2 = length / 2.0f;

	MeshHandle mh = ResourceManager::get().CreateAndGetResource<Mesh>(resourceName);
	if(mh->Valid()) return mh; // dont recreate a mesh under the resourceName

	mh->SetName(resourceName);

	VERTEX verts[3];
	float2 sharedNormal(0,0);

	verts[0] = VERTEX( float2(0, l2),  sharedNormal, float2(0.5f, 1) ); // top
	verts[1] = VERTEX( float2(-l2, -l2), sharedNormal, float2(0, 0) ); // bottom left
	verts[2] = VERTEX( float2(l2, -l2),  sharedNormal, float2(1, 0) ); // bottom right

	u32 indices[] = { 0, 1, 2 };

	if(!mh->BuildVBO(verts, 3, indices, 3))
	{
		mh.reset();
		ResourceManager::get().RemoveResource(mh->GetResourceID());
	}
	return mh;
};