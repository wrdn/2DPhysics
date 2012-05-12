#include "SAT.h"
#include "Collision.h"

SAT::SAT(void)  {}
SAT::~SAT(void) {}

float2 GenAxis(const float2 &E0, const float2 &E1)
{
	float2 E = E1-E0;
	return float2(-E.y, E.x);
};

void SAT::GenerateSeperatingAxes(const std::vector<float2> &vertices,
	std::vector<float2> &output_axes, i32 maxAxis)
{
	u32 Anum = vertices.size();
	if(!Anum) return;

	if(Anum == 2)
	{
		float2 ax = vertices[1] - vertices[0];
		ax = ax.perp();
		output_axes.push_back(ax);
		return;
	}

	maxAxis = maxAxis <= 0 ? (i32)Anum : min((i32)Anum, maxAxis);
	
	for(i32 j = Anum-1, i = 0; i < maxAxis; j = i, i ++)
		output_axes.push_back(GenAxis(vertices[i], vertices[j]));
};

SATProjection SAT::GetInterval(const std::vector<float2> &vertices, const float2 &axis)
{
	//if(!vertices.size()) return SATProjection();

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

bool SAT::IntervalIntersect(const std::vector<float2> &aVertices,
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

bool SAT::GetMinimumTranslationVector(float2 *axis, f32 *taxis, u32 numAxes, float2 &N, f32 &t)
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

bool SAT::Collide(SimBody &a, SimBody &b, float2 &N, f32 &t)
{
	if(a.vertices.size() < 2 && b.vertices.size() < 2) return false;

	Mat22 &OA = a.rotation_matrix;
	Mat22 &OB = b.rotation_matrix;
	Mat22 OB_T = OB.Transpose();

	Mat22 xOrient = OA * OB_T;
	float2 xOffset = (a.position - b.position) * OB_T;

	const u32 MAX_SEPERATING_AXIS = 16; 
	float2 xAxis[MAX_SEPERATING_AXIS];
	f32 taxis[MAX_SEPERATING_AXIS];
	u32 axisCount = 0;

	// First test the last axis
	xAxis[axisCount] = a.seperatingAxis[a.lastAxis] * xOrient;
	if(!IntervalIntersect(a.vertices, b.vertices, xAxis[axisCount],
		xOffset, xOrient, taxis[axisCount], t))
	{
		return false;
	}
	++axisCount;

	// Then test everything before lastAxis and after lastAxis
	for(u32 i=0;i<a.lastAxis;++i)
	{
		xAxis[axisCount] = a.seperatingAxis[i] * xOrient;
		if(!IntervalIntersect(a.vertices, b.vertices, xAxis[axisCount],
			xOffset, xOrient, taxis[axisCount], t))
		{
			a.lastAxis = i;
			return false;
		}
		++axisCount;
	}
	for(u32 i=a.lastAxis;i<a.seperatingAxis.size();++i)
	{
		xAxis[axisCount] = a.seperatingAxis[i] * xOrient;
		if(!IntervalIntersect(a.vertices, b.vertices, xAxis[axisCount],
			xOffset, xOrient, taxis[axisCount], t))
		{
			a.lastAxis = i;
			return false;
		}
		++axisCount;
	}


	xAxis[axisCount] = b.seperatingAxis[b.lastAxis];
	if(!IntervalIntersect(a.vertices, b.vertices, xAxis[axisCount],
		xOffset, xOrient, taxis[axisCount], t))
	{
		return false;
	}
	++axisCount;
	for(u32 i=0;i<b.lastAxis;++i)
	{
		xAxis[axisCount] = b.seperatingAxis[i];
		if(!IntervalIntersect(a.vertices, b.vertices, xAxis[axisCount],
			xOffset, xOrient, taxis[axisCount], t))
		{
			b.lastAxis = i;
			return false;
		}
		++axisCount;
	}
	for(u32 i=b.lastAxis;i<b.seperatingAxis.size();++i)
	{
		xAxis[axisCount] = b.seperatingAxis[i];
		if(!IntervalIntersect(a.vertices, b.vertices, xAxis[axisCount],
			xOffset, xOrient, taxis[axisCount], t))
		{
			b.lastAxis = i;
			return false;
		}
		++axisCount;
	}

	if(!GetMinimumTranslationVector(xAxis, taxis, axisCount, N, t))
	{
		return false;
	}

	f32 D = N.dot(xOffset);
	N =  D < 0.0f ? -N : N;

	N = N * OB;

	return true;
};

i32 FindSupportPoints(const float2 &N, f32 t, const float2 *A, const u32 Anum, const float2 &PA,
	const float2 &VA, const Mat22 &OA, float2 *S)
{
	float2 Norm = N * OA.Transpose();

	f32 d[32], dmin;
	dmin = d[0] = A[0].dot(Norm);

	for(u32 i=1;i<Anum;++i)
	{
		d[i] = A[i].dot(Norm);
		dmin = min(dmin, d[i]);
	}

	i32 Snum=0;
	f32 s[2];
	const f32 threshold = 1.0E-3f;
	bool sign=false;

	float2 PerpNorm(-Norm.y, Norm.x);
	f32 dmin_t = dmin+threshold;

	for(u32 i = 0; i < Anum; i ++)
	{
		if(d[i] < dmin_t)
		{
			float2 Contact = TransformVector(A[i], PA, VA, OA, t);
			f32 c = Contact.dot(PerpNorm);

			if(Snum < 2)
			{
				s[Snum] = c;
				S[Snum] = Contact;
				++Snum;

				sign = Snum>1 ? s[1]>s[0] : sign;
			}
			else
			{
				u32 sgn_index = (int)sign ^ 0x1;
				u32 sgn_index_t = (int)sign;

				f32 &min = s[sgn_index];
				float2 &Min = S[sgn_index];
				f32 &max = s[sgn_index_t];
				float2 &Max = S[sgn_index_t];

				if(c < min)
				{
					min = c;
					Min = Contact;
				}
				else if(c > max)
				{
					max = c;
					Max = Contact;
				}
			}
		}
	}
	return Snum;
};

bool ConvertSupportPointsToContacts(const float2& N, float2* S0, u32 S0num, 
	float2* S1, u32 S1num, float2* C0, float2* C1, u32& Cnum)
{
	Cnum = 0;
	if(!S0num || !S1num) return false;

	// i.e. both 1, not possible for 1 to be 0, and the other 2, as the check above would stop this
	if( (S0num+S1num) == 2)
	{
		C0[Cnum] = S0[0];
		C1[Cnum] = S1[0];
		++Cnum;
		return true;
	}
	
	float2 xPerp(-N.y, N.x);

	f32 min0 = S0[0].dot(xPerp);
	f32 min1 = S1[0].dot(xPerp);
	f32 max0 = min0, max1 = min1;

	if(S0num == 2)
	{
		max0 = S0[1].dot(xPerp);
		if(max0 < min0)
		{
			swap(min0, max0);
			swap(S0[0], S0[1]);
		}
	}
	if(S1num == 2)
	{
		max1 = S1[1].dot(xPerp);
		if(max1 < min1)
		{
			swap(min1,max1);
			swap(S1[0], S1[1]);
		}
	}

	if(min0 > max1 || min1 > max0) return false;

	if(min0 > min1)
	{
		float2 pseg; f32 tmp;
		ProjectPointOnSegment(S0[0], S1[0], S1[1], pseg, tmp);
		C0[Cnum] = S0[0];
		C1[Cnum] = pseg;
		++Cnum;
	}
	else
	{
		float2 Pseg; f32 tmp;
		ProjectPointOnSegment(S1[0], S0[0], S0[1], Pseg, tmp);
		C0[Cnum] = Pseg;
		C1[Cnum] = S1[0];
		Cnum++;
	}

	if(max0 != min0 && max1 != min1)
	{
		if(max0 < max1)
		{
			float2 Pseg; f32 tmp;
			ProjectPointOnSegment(S0[1], S1[0], S1[1], Pseg, tmp);
			C0[Cnum] = S0[1];
			C1[Cnum] = Pseg;
			Cnum++;
		}
		else
		{
			float2 Pseg; f32 tmp;
			ProjectPointOnSegment(S1[1], S0[0], S0[1], Pseg, tmp);
			C0[Cnum] = Pseg;
			C1[Cnum] = S1[1];
			Cnum++;
		}
	}
	return true;
};

bool FindContacts(const SimBody &a, const SimBody &b, const float2 &N, f32 t,
	float2 *CA, float2 *CB, u32 &Cnum)
{
	float2 S0[4], S1[4];
	u32 S0num = FindSupportPoints( N, t, &a.vertices[0], a.vertices.size(), a.position, float2(), a.rotation_matrix, S0);
	u32 S1num = FindSupportPoints(-N, t, &b.vertices[0], b.vertices.size(), b.position, float2(), b.rotation_matrix, S1);

	return ConvertSupportPointsToContacts(N, S0, S0num, S1, S1num, CA, CB, Cnum);
};