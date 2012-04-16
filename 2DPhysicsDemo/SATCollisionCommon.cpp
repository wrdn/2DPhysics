#include "SATCollision.h"

bool FindMTD(const float2 *axis, f32 *taxis, u32 axisCount, float2 &N, f32 &t)
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

bool IntervalIntersect(
	const float2 &axis, const float2 * const polyAverts,
	const float2 * const polyBverts,
	const u32 polyAcount, const u32 polyBcount,
	const float2 &relativePosition, f32 &taxis,
	const Mat22 &xOrient)
{
	MinMaxProjection aproj, bproj;

	GetInterval(axis * xOrient.Transpose(), polyAverts, polyAcount, aproj);
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

void GetInterval(const float2 &axis, const float2 * const verts, const u32 vertCount, MinMaxProjection &proj)
{
	proj.min = proj.max = verts[0].dot(axis);
	for(u32 i=1;i<vertCount;++i)
	{
		const f32 D = verts[i].dot(axis);
		proj.min = min(proj.min, D);
		proj.max = max(proj.max, D);
	}
};