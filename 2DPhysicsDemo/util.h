#ifndef __UTIL_H__ // common utility functions (with no need to be in a class)
#define __UTIL_H__

#include "ctypes.h"
#include <string>
#include <vector>

const f32 EPSILON = 0.000001f; // rough epsilon
const f32 PI = 3.1415926f;
const f32 PIOVER180 = PI/180.0f;

void SAFE_DELETE(const void *p);
void SAFE_DELETE_ARRAY(const void *p);

void set_bit(u32 &opt, const u32 bit);
i32 bit_set(const u32 &opt, const u32 bit);
void clear_bit(u32 &opt, const u32 bit);
void toggle_bit(u32 &opt, const u32 bit);

void clamp(u32 &v, u32 lower, u32 upper);
void clamp(i32 &v, i32 lower, i32 upper);

bool NearZero(const f32 v);

f32 InvSqrt(f32 x);

// djb2 string hashing
unsigned long hash_djb2(const uc8 *str);

f32 DEGTORAD(f32 degs);
f32 RADTODEG(f32 rads);

f32 fract(f32 c);

f32 lerp(f32 min, f32 max, f32 t);

const bool file_exists(const c8 *filename);

f32 randflt(f32 min, f32 max);

i32 rand(i32 min, i32 max); // range of function is min to max inclusive

f32 reciprocal_sqrt(f32 f);

std::string strtolower(const std::string &s);
std::string strtoupper(const std::string &s);

// Call this to loop through the vector and call delete on each element
// This is useful when you have a vector full of valid pointers to be deleted
template<class T>
void CleanupVector(std::vector<T*> &datavec)
{
	for(u32 i=0;i<datavec.size();++i)
	{
		delete datavec[i];
	}
	datavec.clear();
};

#endif