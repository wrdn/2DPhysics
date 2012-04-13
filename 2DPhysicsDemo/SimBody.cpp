#include "SimBody.h"

float2 SimBody::gravity = float2(0, meters(-9.81f));

SimBody::SimBody(void)
{
	position = float2(0.0f);
	rotation = 0.0f;
	velocity = float2(0.0f);
	angularVelocity = 0.0f;
	force = float2(0.0f);
	torque = 0.0f;
	friction = 0.2f;

	mass = I = 10;
	invMass = invI = 1.0f/mass;

	fillMode = GL_FILL;
	mesh = MeshHandle(0);

	dragCoefficient = 0.1f;

	use_textures = use_shaders = draw = update = true;
};

void SimBody::Draw()
{
	if(!mesh || !draw) return;

	// activate shader and textures
	if(use_shaders && objectMaterial.GetShader())
		objectMaterial.GetShader()->Activate();
	if(use_textures && fillMode == GL_FILL) // only enable textures when GL_FILL is the fill mode, otherwise the object gets darker as it gets closer to the screen
	{
		for(u32 i=0;i<objectMaterial.GetTextures().size();++i)
			objectMaterial.GetTextures()[i]->Activate();
	}
	else
	{
		glDisable(GL_TEXTURE_2D);
	}

	glPushMatrix();

	// translate and rotate
	glTranslatef(position.x(), position.y(), 0);
	glRotatef(rotation, 0,0,1);

	// draw
	glDisable(GL_CULL_FACE);
	glColor3fv(objectMaterial.GetObjectColor().GetVec());
	glPolygonMode(GL_FRONT_AND_BACK, fillMode);

	mesh->Draw();

	glPopMatrix();

	// cleanup state
	glColor3fv(Color::WHITE.GetVec());
	mesh->glUseProgram(0);
	mesh->glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, 0);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
};

bool BoundingCircleIntersects(const SimBody &av, const SimBody &bv)
{
	f32 a = av.boundingCircleRadius + bv.boundingCircleRadius;
	float2 dm = av.position - bv.position;
	return (a*a) > dm.length_squared();
};

// Temp code, this data could later be cached
/*
void CalculateBoxVertices(const Box &b, float2 *verts)
{
	verts[0].set( b.position.x() - b.extents.x(), b.position.y() - b.extents.y() );
	verts[1].set( b.position.x() + b.extents.x(), b.position.y() - b.extents.y() );
	verts[2].set( b.position.x() + b.extents.x(), b.position.y() + b.extents.y() );
	verts[3].set( b.position.x() - b.extents.x(), b.position.y() + b.extents.y() );
};
*/

bool overlaps(MinMaxProjection &ax, MinMaxProjection &bx)
{
	f32 d0 = ax.min - bx.max;
	f32 d1 = bx.min - ax.max;
	if(d0 > 0.0f || d1 > 0.0f) { return false; }
	return true;
};

// Tests if "axis" seperates polygon A and polygon B (i.e. space on that axis between them)
// This is done by projecting all verts of both polygons onto the axis, then testing for an
// overlap between them (Seperating Hyperplane Theorem). This should work for ANY convex polygon.
// Note: axis does NOT have to be normalized
// Assumes polyAverts and polyBverts not null
//bool SeperatingAxis(const float2 &axis, const float2 *polyAverts, const float2 *polyBverts,
//	u32 polyAcount, u32 polyBcount, const float2 &relativePosition, f32 &taxis)
//{
//	MinMaxProjection aproj, bproj;
//
//	// project polygon a
//	aproj.min = aproj.max = polyAverts[0].dot(axis);
//	for(u32 i=1;i<polyAcount;++i)
//	{
//		aproj.min = min(aproj.min, polyAverts[i].dot(axis));
//		aproj.max = max(aproj.max, polyAverts[i].dot(axis));
//	}
//
//	// project polygon b
//	bproj.min = bproj.max = polyBverts[0].dot(axis);
//	for(u32 i=1;i<polyBcount;++i)
//	{
//		bproj.min = min(bproj.min, polyBverts[i].dot(axis));
//		bproj.max = max(bproj.max, polyBverts[i].dot(axis));
//	}
//
//	// Seperating Axis Found (no collision)
//	if(aproj.min > bproj.max || bproj.min > aproj.max) { return true; }
//
//	f32 d0 = aproj.max - bproj.min;
//	f32 d1 = bproj.max - aproj.min;
//	f32 depth = min(d0, d1);
//
//	return false; // intersecting on this axis
//};
void GetInterval(const float2 &axis, const float2 const * verts, const u32 vertCount, MinMaxProjection &proj)
{
	proj.min = proj.max = verts[0].dot(axis);
	for(u32 i=1;i<vertCount;++i)
	{
		const f32 D = verts[i].dot(axis);
		proj.min = min(proj.min, D);
		proj.max = max(proj.max, D);
	}
};

bool SeperatingAxis(const float2 &axis, const float2 *polyAverts, const float2 *polyBverts,
	u32 polyAcount, u32 polyBcount, const float2 &relativePosition, f32 &taxis)
{
	MinMaxProjection aproj, bproj;

	GetInterval(axis, polyAverts, polyAcount, aproj);
	GetInterval(axis, polyBverts, polyBcount, bproj);

	f32 h = relativePosition.dot(axis);
	aproj.min += h;
	aproj.max += h;

	f32 d0 = aproj.min - bproj.max;
	f32 d1 = bproj.min - aproj.max;

	if(d0 > 0.0f || d1 > 0.0f)
	{
		return false;
	}

	taxis = d0 > d1 ? d0 : d1;
	return true;
};

bool FindMinimumTranslationDistance(const float2 const * axis, u32 axisCount,
	f32 *taxis, float2 &N, f32 &t)
{
	i32 mini = -1;

	t = 0;
	N.setall(0);

	for(u32 i=0;i<axisCount;++i)
	{
		float2 _axis = axis[i];
		f32 Len = _axis.magnitude();
		_axis.normalize();

		taxis[i] /= Len;

		if(taxis[i] > t || mini == -1)
		{
			mini = i;
			t = taxis[i];
			N = _axis;
		}
	}

	return mini != -1;
};

// Perform SAT intersection testing on 2 boxes - using SAT as we will later extend it to
// generate a "push" vector, then change to OBBs
bool Intersect(const Box &a, const Box &b, float2 &out_mtd_vec, f32 &t)
{
	float2 relativePosition = a.position - b.position; // relative position
	const float2 AXIS[2] = { float2(1,0), float2(0,1) };
	f32 taxis[2];

	if(!SeperatingAxis(AXIS[0], a._cached_vertices, b._cached_vertices, 
		4, 4, relativePosition, taxis[0]))
	{
		return false;
	}
	if(!SeperatingAxis(AXIS[1], a._cached_vertices, b._cached_vertices, 
		4, 4, relativePosition, taxis[1]))
	{
		return false;
	}

	if(!FindMinimumTranslationDistance(AXIS, 2, 
		taxis, out_mtd_vec, t))
	{
		return false;
	}

	f32 mtd_dot_rp = out_mtd_vec.dot(relativePosition);

	// Ignore the self assignment here. It is a possible optimisation as sometimes,
	// the ternary (sp?) operator will using floating point selects, resulting in
	// branchless code - a big win :)
	out_mtd_vec = mtd_dot_rp < 0.0f ? out_mtd_vec.negate() : out_mtd_vec;

	return true;

};

/*bool Intersect(const Box &a, const Box &b, float2 &out_mtd_vec)
{
	float2 relativePosition = a.position - b.position; // relative position

	const float2 AXIS[2] = 
	{
		float2(1,0),
		float2(0,1)
	};
	
	f32 taxis[2];

	float2 box_a_verts[4], box_b_verts[4];
	CalculateBoxVertices(a, box_a_verts);
	CalculateBoxVertices(b, box_b_verts);

	if(SeperatingAxis(AXIS[0], box_a_verts, box_b_verts, 4, 4, relativePosition, taxis[0])) { return false; }
	if(SeperatingAxis(AXIS[1], box_a_verts, box_b_verts, 4, 4, relativePosition, taxis[1])) { return false; }

	out_mtd_vec = axis_push_vectors[0];
	if(axis_push_vectors[1].length_squared() < axis_push_vectors[0].length_squared())
	{
		out_mtd_vec = axis_push_vectors[1];
	}

	float2 D = a.position - b.position;
	if(D.dot(out_mtd_vec) < 0.0f) { out_mtd_vec = -out_mtd_vec; };

	return true;
};*/