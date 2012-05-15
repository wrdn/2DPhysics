#pragma once

#include "float2.h"

//struct float2 { float x,y; float2():x(0),y(0){} float2(float _x, float _y):x(_x),y(_y){} }; // temp placeholder for the real float2
struct ivec { int x, y; ivec():x(0),y(0) {}; ivec(int _x, int _y) : x(_x), y(_y) {}; }; // These will be used when sending vector across network. We convert x and y to ints, then convert back

// Use the static functions here to marshall and unmarshall data
class Marshall
{
private:
	Marshall(){};
	
	union CV { int _int; float _flt; };

public:
	static float ConvertIntToFloat(int i) // WARNING: not portable
	{
		CV c;
		c._int = i;
		return c._flt;
	};

	static int ConvertFloatToInt(float f) // WARNING: not portable
	{
		CV c;
		c._flt = f;
		return c._int;
	};

	static ivec ConvertFloatVecToIntVector(const float2& f)
	{
		return ivec(ConvertFloatToInt(f.x), ConvertFloatToInt(f.y));
	};

	static float2 ConvertIntVecToFloatVec(const ivec& i)
	{
		return float2(ConvertIntToFloat(i.x), ConvertIntToFloat(i.y));
	};
};