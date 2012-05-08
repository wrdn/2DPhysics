/*
* Copyright (c) 2006-2007 Erin Catto http://www.gphysics.com
*
* Permission to use, copy, modify, distribute and sell this software
* and its documentation for any purpose is hereby granted without fee,
* provided that the above copyright notice appear in all copies.
* Erin Catto makes no representations about the suitability 
* of this software for any purpose.  
* It is provided "as is" without express or implied warranty.
*/

#ifndef MATHUTILS_H
#define MATHUTILS_H

#include <math.h>
#include <float.h>
#include <assert.h>
#include <stdlib.h>
#include "float2.h"

const float k_pi = 3.14159265358979323846264f;

struct Vector2f
{
	Vector2f() {}
	Vector2f(float x, float y) : x(x), y(y) {}
	Vector2f(float2 f)
	{
		x = f.x;
		y = f.y;
	}

	float2 tofloat2() { return float2(x,y); };

	void Set(float x_, float y_) { x = x_; y = y_; }

	Vector2f operator -() { return Vector2f(-x, -y); }
	
	void operator += (const Vector2f& v)
	{
		x += v.x; y += v.y;
	}
	
	void operator -= (const Vector2f& v)
	{
		x -= v.x; y -= v.y;
	}

	void operator *= (float a)
	{
		x *= a; y *= a;
	}

	float Length() const
	{
		return sqrtf(x * x + y * y);
	}

	float x, y;
};

struct Matrix22
{
	Matrix22() {}
	Matrix22(float angle)
	{
		float c = cosf(angle), s = sinf(angle);
		col1.x = c; col2.x = -s;
		col1.y = s; col2.y = c;
	}

	Matrix22(const Vector2f& col1, const Vector2f& col2) : col1(col1), col2(col2) {}

	Matrix22 Transpose() const
	{
		return Matrix22(Vector2f(col1.x, col2.x), Vector2f(col1.y, col2.y));
	}

	Matrix22 Invert() const
	{
		float a = col1.x, b = col2.x, c = col1.y, d = col2.y;
		Matrix22 B;
		float det = a * d - b * c;
		assert(det != 0.0f);
		det = 1.0f / det;
		B.col1.x =  det * d;	B.col2.x = -det * b;
		B.col1.y = -det * c;	B.col2.y =  det * a;
		return B;
	}

	union
	{
		struct { float data[4]; };
		struct { Vector2f col1, col2; };
	};
};

inline float Dot(const Vector2f& a, const Vector2f& b)
{
	return a.x * b.x + a.y * b.y;
}

inline float Cross(const Vector2f& a, const Vector2f& b)
{
	return a.x * b.y - a.y * b.x;
}

inline Vector2f Cross(const Vector2f& a, float s)
{
	return Vector2f(s * a.y, -s * a.x);
}

inline Vector2f Cross(float s, const Vector2f& a)
{
	return Vector2f(-s * a.y, s * a.x);
}

inline Vector2f operator * (const Matrix22& A, const Vector2f& v)
{
	return Vector2f(A.col1.x * v.x + A.col2.x * v.y, A.col1.y * v.x + A.col2.y * v.y);
}

inline Vector2f operator + (const Vector2f& a, const Vector2f& b)
{
	return Vector2f(a.x + b.x, a.y + b.y);
}

inline Vector2f operator - (const Vector2f& a, const Vector2f& b)
{
	return Vector2f(a.x - b.x, a.y - b.y);
}

inline Vector2f operator * (float s, const Vector2f& v)
{
	return Vector2f(s * v.x, s * v.y);
}

inline Matrix22 operator + (const Matrix22& A, const Matrix22& B)
{
	return Matrix22(A.col1 + B.col1, A.col2 + B.col2);
}

inline Matrix22 operator * (const Matrix22& A, const Matrix22& B)
{
	return Matrix22(A * B.col1, A * B.col2);
}

inline float Abs(float a)
{
	return a > 0.0f ? a : -a;
}

inline Vector2f Abs(const Vector2f& a)
{
	return Vector2f(fabsf(a.x), fabsf(a.y));
}

inline Matrix22 Abs(const Matrix22& A)
{
	return Matrix22(Abs(A.col1), Abs(A.col2));
}

inline float Sign(float x)
{
	return x < 0.0f ? -1.0f : 1.0f;
}

inline float Min(float a, float b)
{
	return a < b ? a : b;
}

inline float Max(float a, float b)
{
	return a > b ? a : b;
}

inline float Clamp(float a, float low, float high)
{
	return Max(low, Min(a, high));
}

template<typename T> inline void Swap(T& a, T& b)
{
	T tmp = a;
	a = b;
	b = tmp;
}

// Random number in range [-1,1]
inline float Random()
{
	float r = (float)rand();
	r /= RAND_MAX;
	r = 2.0f * r - 1.0f;
	return r;
}

inline float Random(float lo, float hi)
{
	float r = (float)rand();
	r /= RAND_MAX;
	r = (hi - lo) * r + lo;
	return r;
}

#endif

