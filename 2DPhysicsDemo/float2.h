#pragma once
#pragma warning(disable : 4201) // disable "nonstandard extension used", for anonymous unions

#include "ctypes.h"
#include <iosfwd>

struct vec2i
{
public:
	i32 x,y;
	vec2i() : x(0), y(0) { };
	vec2i(i32 _x, i32 _y): x(_x), y(_y) { };

	void set(i32 _x, i32 _y) { x = _x; y = _y; }
};

class float2
{
public:
	union
	{
		struct { f32 x, y; };
		struct { f32 vec[2]; };
	};

	~float2();
	float2();
	explicit float2(const f32 v);
	explicit float2(const f32 _x, f32 _y);
	explicit float2(const f32 * v);

	f32* GetVec() const { return (f32*)vec; };

	void set(const f32 _x, const f32 _y)
	{
		x = _x;
		y = _y;
	};
	void set(const f32 * const v)
	{
		x = v[0];
		y = v[1];
	};

	void zero(); // zero's the current vector
	void setall(const f32 v);

	float2 add(const float2 &v) const;
	float2 sub(const float2 &v) const;
	float2 mul(const float2 &v) const;
	float2 div(const float2 &v) const;
	
	float2 add(const f32 t) const;
	float2 sub(const f32 t) const;
	float2 mul(const f32 t) const;
	float2 div(const f32 t) const;

	f32 dot(const float2 &v) const;

	f32 magnitude() const;
	f32 length_squared() const;
	float2 normalize() const;

	f32 distance(const float2 &other) const;
	f32 distance_squared(const float2 &other) const;

	// projects 'this' onto 'other'. 'other' is automatically normalized
	float2 project(const float2 &other) const;

	// similar to output of cross product in 3D, left hand perp vector points to left of vector,
	// right hand perp vector points to right of vector
	// default perp() calls the right hand version
	float2 perp() const { return perpendicular_vector_right(); };
	float2 perpendicular_vector_left() const;
	float2 perpendicular_vector_right() const;

	float2 absolute() const;
	float2 negate() const;

	float2 vec_lerp(const float2 &target, f32 lerpFactor);

	// New operators (implementing + etc in terms of +=)
	inline const float2& operator+=(const float2 &rhs) { *this = add(rhs); return *this; }
	inline const float2& operator-=(const float2 &rhs) { *this = sub(rhs); return *this; }
	inline const float2& operator*=(const float2 &rhs) { *this = mul(rhs); return *this; }
	inline const float2& operator/=(const float2 &rhs) { *this = div(rhs); return *this; }
};

// Auxiliary Functions (operator overloads)
inline float2 operator-(const float2 &a) { return a.negate(); }; // negation operator
inline float2 operator+(const float2 &a, const float2 &b) { return float2(a)+=b; };
inline float2 operator-(const float2 &a, const float2 &b) { return float2(a)-=b; };
inline float2 operator*(const float2 &a, const float2 &b) { return float2(a)*=b; };
inline float2 operator/(const float2 &a, const float2 &b) { return float2(a)/=b; };

inline float2 operator+(const float2 &a, const f32 b) { return float2(a)+=float2(b); };
inline float2 operator-(const float2 &a, const f32 b) { return float2(a)-=float2(b); };
inline float2 operator*(const float2 &a, const f32 b) { return float2(a)*=float2(b); };
inline float2 operator/(const float2 &a, const f32 b) { return float2(a)/=float2(b); };

std::ostream& operator<<(std::ostream &out, float2 &m);
std::istream& operator>>(std::istream &in, float2& out);