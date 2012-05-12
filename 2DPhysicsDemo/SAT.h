#pragma once

#include <vector>
#include "ctypes.h"
#include "Mat22.h"
#include "float2.h"

class SimBody;

class SATProjection { public: f32 min, max; };

// SAT Collision Functions (Static Only)
class SAT
{
private:
	SAT(void);
	~SAT(void);

	static SATProjection GetInterval(const std::vector<float2> &vertices, const float2 &axis);
	
	static bool IntervalIntersect(const std::vector<float2> &aVertices,
		const std::vector<float2> &bVertices, const float2 &axis, const float2 &relPos,
		const Mat22 &xOrient, f32 &taxis, f32 tmax);

	static bool GetMinimumTranslationVector(float2 *axis, f32 *taxis, u32 numAxes, float2 &N, f32 &t);

public:

	// set maxAxis to <= 1 to disable it, otherwise we only generate up to maxAxis number of axis
	static void GenerateSeperatingAxes(const std::vector<float2> &vertices,
		std::vector<float2> &output_axes, i32 maxAxis=-1);

	static bool Collide(SimBody &a, SimBody &b, float2 &N, f32 &t);
};

i32 FindSupportPoints(const float2 &N, f32 t, const float2 *A, const u32 Anum, const float2 &PA,
	const float2 &VA, const Mat22 &OA, float2 *S);

bool ConvertSupportPointsToContacts(const float2& N, float2* S0, u32 S0num, 
	float2* S1, u32 S1num, float2* C0, float2* C1, u32& Cnum);

bool FindContacts(const SimBody &a, const SimBody &b, const float2 &N, f32 t,
	float2 *CA, float2 *CB, u32 &Cnum);