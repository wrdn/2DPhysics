#include "util.h"
#include <math.h>
#include <sys/stat.h>
#include <Windows.h>

void SAFE_DELETE(const void *p) { if(p) { delete p; p = 0; } };
void SAFE_DELETE_ARRAY(const void *p)
{
	if(p)
	{
		delete [] p;
		p = 0;
	}
};

void set_bit(u32 &opt, const u32 bit)
{
	opt |= bit;
};

i32 bit_set(const u32 &opt, const u32 bit)
{
	return (opt & bit);
};

void clear_bit(u32 &opt, const u32 bit)
{
	opt &= (~bit);
};

void toggle_bit(u32 &opt, const u32 bit)
{
	opt ^= bit;
};

void clamp(u32 &v, u32 lower, u32 upper)
{
	if(v < lower) { v = lower; }
	else if(v > upper) { v = upper; }
};

void clamp(i32 &v, i32 lower, i32 upper)
{
	if(v < lower) { v = lower; }
	else if(v > upper) { v = upper; }
};

bool NearZero(const f32 v)
{
		return fabs(v) < EPSILON;
};

// Fast inverse square root, from http://pizer.wordpress.com/2008/10/12/fast-inverse-square-root/
f32 InvSqrt(f32 x)
{
   u32 i = 0x5F1F1412 - (*(u32*)&x >> 1);
   f32 tmp = *(f32*)&i;
   return tmp * (1.69000231f - 0.714158168f * x * tmp * tmp);
};

// Source: http://www.cse.yorku.ca/~oz/hash.html
unsigned long hash_djb2(const uc8 *str)
{
	unsigned long hash = 5381;
	u32 c='a'; // give c a valid value so we can get into the loop

	while(c) // rewrote this slightly to get rid of Parasoft and Visual Studio Release mode warning (assignment in conditional expression)
	{
		c = *str;
		if(c==0) { break; }
		hash = ((hash << 5) + hash) + c;
		++str;
	}

	return hash;
}

f32 DEGTORAD(f32 degs)
{
	return (degs * (PI / 180.0f));
};

f32 RADTODEG(f32 rads)
{
	return (rads * (180.0f / PI));
};

f32 fract(f32 c)
{
	return (c - floor(c));
};

f32 lerp(f32 min, f32 max, f32 t)
{
	return (min + (t * (max-min)));
};

const bool file_exists(const c8 *filename)
{
	struct stat f; // careful not to mix up the structure and function
	return (stat(filename,&f) == 0); // 0 if file exists
}

f32 randflt(f32 min, f32 max)
{
    f32 random = ((f32) rand()) / (f32) RAND_MAX;

    // generate (in your case) a float between 0 and (4.5-.78)
    // then add .78, giving you a float between .78 and 4.5
    f32 range = max - min;  
    return (random*range) + min;
};

i32 rand(i32 min, i32 max)
{
	return (rand()%(max-min+1))+min;
};

f32 reciprocal_sqrt(f32 f)
{
	/*
	// SSE Version (Fast):
	f32 result; // reciprocal square root using SSE (accurate to ~11/12 mantissa bits)
	_mm_store_ss(&result, _mm_rsqrt_ss( _mm_load_ss(&f) ));
	return result;

	// More accurate scalar version:
	return 1.0f / sqrt(f);
	*/
	f32 result; // reciprocal square root using SSE (accurate to ~11/12 mantissa bits)
	_mm_store_ss(&result, _mm_rsqrt_ss( _mm_load_ss(&f) ));
	return result;
};

std::string strtolower(const std::string &sp)
{
	std::string s = sp;
	for(u32 i=0;i<s.size();++i)
		s[i] = (c8)tolower(s[i]);
	return s;
};

std::string strtoupper(const std::string &sp)
{
	std::string s = sp;
	for(u32 i=0;i<s.size();++i)
		s[i] = (c8)toupper(s[i]);
	return s;
};

f32 wrapf(f32 x, f32 min, f32 max)
{
	if(x < min)
	{
		return (x-min)+max;
	}
	else if(x > max)
	{
		return (x-max)+min;
	}

	return x;
};