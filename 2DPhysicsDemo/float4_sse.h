#pragma once

#include <emmintrin.h> // SSE2    http://softpixel.com/~cwright/programming/simd/sse2.php
#include <pmmintrin.h> // SSE3    http://softpixel.com/~cwright/programming/simd/sse3.php
#include "ctypes.h"

const __m128 FLOAT4SSE_SIGNMASK = _mm_castsi128_ps(_mm_set1_epi32(0x80000000));
class float4_sse // note: all loads are aligned. Therefore if pointers to data are used, the data pointed to MUST be 16 byte aligned (see ALIGN() macro in util.h for compile time alignment)
{
public:
	__m128 vec;

	struct fvec { public: f32 x,y,z,w; fvec():x(0),y(0),z(0),w(0){}; ~fvec(){}; }; // used when pulling data out (i.e. SSE store)

	float4_sse(void) { zero(); }
	float4_sse(__m128 v) { vec=v; }
	float4_sse(const f32 v) { set(v); }
	float4_sse(const f32 x, const f32 y, const f32 z, const f32 w) { set(x,y,z,w); };
	float4_sse(const f32 x, const f32 y, const f32 z) { set(x,y,z,0); }
	float4_sse(const f32 *v) { set(v); }
	~float4_sse(void) {};

	void set(const f32 x, const f32 y, const f32 z, const f32 w) { vec = _mm_set_ps(w,z,y,x); }
	void set(const f32 *v) { vec = _mm_load_ps(v); }
	void set(const f32 v) { vec = _mm_load1_ps(&v); }
	void zero() { vec=_mm_setzero_ps(); }

	float4_sse add(const float4_sse &v) { return float4_sse(_mm_add_ps(vec,v.vec)); }
	float4_sse sub(const float4_sse &v) { return float4_sse(_mm_sub_ps(vec,v.vec)); }
	float4_sse mul(const float4_sse &v) { return float4_sse(_mm_mul_ps(vec,v.vec)); }
	float4_sse div(const float4_sse &v) { return float4_sse(_mm_div_ps(vec,v.vec)); }

	f32 dot(const float4_sse &v)
	{
		// http://software.intel.com/en-us/articles/implement-a-horizontal-addsubtract-with-sse3-instructions/
		__m128 mres = _mm_mul_ps(vec,v.vec);
		__m128 h = _mm_hadd_ps(mres,mres);
		__m128 fin = _mm_hadd_ps(h ,h);
		f32 ret; _mm_store_ss(&ret, fin);
		return ret;
	};

	float4_sse normalize()
	{
		__m128 l = _mm_mul_ps(vec, vec);
		l = _mm_add_ps(l, _mm_shuffle_ps(l, l, 0x4E));
		return float4_sse(_mm_div_ps(vec, _mm_sqrt_ps(_mm_add_ps(l, _mm_shuffle_ps(l, l, 0x11)))));
	};

	f32 magnitude()
	{
		__m128 l = _mm_mul_ps(vec, vec);
		l = _mm_add_ps(l, _mm_shuffle_ps(l, l, 0x4E));
		__m128 p = _mm_sqrt_ps(_mm_add_ps(l, _mm_shuffle_ps(l, l, 0x11)));
		f32 ret; _mm_store_ss(&ret, p); return ret;
	}

	float4_sse cross(const float4_sse &v)
	{
		__m128 ares = _mm_mul_ps(_mm_shuffle_ps(vec,vec,0xD8), _mm_shuffle_ps(v.vec,v.vec,0xE1));
		__m128 bres = _mm_mul_ps(_mm_shuffle_ps(vec,vec,0xE1), _mm_shuffle_ps(v.vec,v.vec,0xD8));
		__m128 sr = _mm_sub_ps(ares,bres);
		return float4_sse(_mm_shuffle_ps(sr, sr, _MM_SHUFFLE(3,0,1,2))); // shuffle data back into correct order
	};
	

	float4_sse negate() { return float4_sse(_mm_xor_ps(vec, FLOAT4SSE_SIGNMASK)); };
	float4_sse absolute() { return float4_sse(_mm_andnot_ps(FLOAT4SSE_SIGNMASK, vec)); };
};