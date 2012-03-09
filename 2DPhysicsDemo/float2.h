#pragma once

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
private:
	f32 vec[2];
public:
	static const float2 ZERO;
	static const float2 ONE;

	~float2();
	float2();
	explicit float2(const f32 v);
	explicit float2(const f32 _x, f32 _y);
	explicit float2(const f32 * v);

	f32 * GetVec() const { return (f32*)vec; };

	f32 x() const { return vec[0]; };
	f32 y() const { return vec[1]; };

	f32 r() const { return x(); };
	f32 g() const { return y(); };

	void x(const f32 v) { vec[0]=v; };
	void y(const f32 v) { vec[1]=v; };

	void set(const f32 _x, const f32 _y)
	{
		vec[0] = _x;
		vec[1] = _y;
	};
	void set(const f32 * const v)
	{
		vec[0] = v[0];
		vec[1] = v[1];
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

	float2 negate() const;

	float2 vec_lerp(const float2 &target, f32 lerpFactor);

	// New operators (implementing + etc in terms of +=)
	inline const float2& operator+=(const float2 &rhs) { *this = add(rhs); return *this; }
	inline const float2& operator-=(const float2 &rhs) { *this = sub(rhs); return *this; }
	inline const float2& operator*=(const float2 &rhs) { *this = mul(rhs); return *this; }
	inline const float2& operator/=(const float2 &rhs) { *this = div(rhs); return *this; }
};

// Auxiliary Functions (operator overloads)
inline float2 operator+(const float2 &a, const float2 &b) { return float2(a)+=b; }
inline float2 operator-(const float2 &a, const float2 &b) { return float2(a)-=b; };
inline float2 operator*(const float2 &a, const float2 &b) { return float2(a)*=b; };
inline float2 operator/(const float2 &a, const float2 &b) { return float2(a)/=b; };

inline float2 operator+(const float2 &a, const f32 b) { return float2(a)+=float2(b); };
inline float2 operator-(const float2 &a, const f32 b) { return float2(a)-=float2(b); };
inline float2 operator*(const float2 &a, const f32 b) { return float2(a)*=float2(b); };
inline float2 operator/(const float2 &a, const f32 b) { return float2(a)/=float2(b); };

inline float2 operator+(const f32 a, const float2 &b) { return float2(a)+=b; };
inline float2 operator-(const f32 a, const float2 &b) { return float2(a)+=b; };
inline float2 operator*(const f32 a, const float2 &b) { return float2(a)+=b; };
inline float2 operator/(const f32 a, const float2 &b) { return float2(a)+=b; };

std::ostream& operator<<(std::ostream &out, float2 &m);
std::istream& operator>>(std::istream &in, float2& out);