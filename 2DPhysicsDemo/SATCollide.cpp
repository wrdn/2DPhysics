#include "Body.h"
#include "Arbiter.h"
#include "Mat22.h"
#include <math.h>

SATProjection GetInterval(const std::vector<float2> &vertices, const float2 &axis)
{
	if(!vertices.size()) return SATProjection();

	SATProjection proj;

	proj.min = proj.max = vertices[0].dot(axis);
	for(u32 i=1;i<vertices.size();++i)
	{
		f32 d = vertices[i].dot(axis);
		proj.min = min(d, proj.min);
		proj.max = max(d, proj.max);
	}
	return proj;
};

bool IntervalIntersect(const std::vector<float2> &aVertices,
		const std::vector<float2> &bVertices, const float2 &axis, const float2 &relPos,
		const Mat22 &xOrient, f32 &taxis, f32 tmax)
{
	SATProjection proj0 = GetInterval(aVertices, axis * xOrient.Transpose());
	SATProjection proj1 = GetInterval(bVertices, axis);
	
	f32 h = relPos.dot(axis);
	proj0.min += h;
	proj0.max += h;

	f32 d0 = proj0.min - proj1.max;
	f32 d1 = proj1.min - proj0.max;

	if(d0 > 0.0f || d1 > 0.0f)
	{
		return false;
	}

	taxis = d0 > d1 ? d0 : d1;
	return true;
};

bool GetMinimumTranslationVector(float2 *axis, f32 *taxis, u32 numAxes, float2 &N, f32 &t)
{
	i32 mini = -1;
	for(u32 i=0;i<numAxes;++i)
	{
		f32 n = axis[i].magnitude();
		axis[i] = axis[i].normalize();
		taxis[i] /= n;

		if(taxis[i] > t || mini == -1)
		{
			mini = i;
			t = taxis[i];
			N = axis[i];
		}
	}
	return mini != -1;
};

bool SATCollide(SimBody *body1, SimBody *body2, float2 &N, f32 &t)
{
	SimBody &a = *body1;
	SimBody &b = *body2;

	if(a.vertices.size() < 2 && b.vertices.size() < 2) return false;

	Mat22 &OA = Mat22::RotationMatrix(a.rotation_in_rads);
	Mat22 &OB = Mat22::RotationMatrix(b.rotation_in_rads);
	Mat22 OB_T = OB.Transpose();

	Mat22 xOrient = OA * OB_T;
	float2 xOffset = (a.position - b.position) * OB_T;

	const u32 MAX_SEPERATING_AXIS = 16; 
	float2 xAxis[MAX_SEPERATING_AXIS];
	f32 taxis[MAX_SEPERATING_AXIS];
	u32 axisCount = 0;

	for(u32 i=0;i<a.seperatingAxis.size();++i)
	{
		xAxis[axisCount] = a.seperatingAxis[i] * xOrient;
		if(!IntervalIntersect(a.vertices, b.vertices, xAxis[axisCount],
			xOffset, xOrient, taxis[axisCount], t))
		{
			return false;
		}
		++axisCount;
	};
	for(u32 i=0;i<b.seperatingAxis.size();++i)
	{
		xAxis[axisCount] = b.seperatingAxis[i];
		if(!IntervalIntersect(a.vertices, b.vertices, xAxis[axisCount],
			xOffset, xOrient, taxis[axisCount], t))
		{
			return false;
		}
		++axisCount;
	};

	if(!GetMinimumTranslationVector(xAxis, taxis, axisCount, N, t))
	{
		return false;
	}

	f32 D = N.dot(xOffset);
	N =  D < 0.0f ? -N : N;

	N = N * OB;

	return true;
};