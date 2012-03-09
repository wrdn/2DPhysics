#pragma once

#include "ctypes.h"
#include <iostream>

class float3;
class float4
{
private:
	f32 vec[4];

public:
	f32 * GetVec() const { return (f32*)vec; };

	static const float4 ZERO;
	static const float4 ONE;

	float4(); // sets all to 0
	explicit float4(const f32 v);
	float4(const f32 _x, f32 _y, f32 _z);
	float4(const f32 _x, f32 _y, f32 _z, f32 _w);
	explicit float4(const f32 * v); // copy from 4 element array

	f32 x() const { return vec[0]; };
	f32 y() const { return vec[1]; };
	f32 z() const { return vec[2]; };
	f32 w() const { return vec[3]; };

	f32 r() const { return x(); };
	f32 g() const { return y(); };
	f32 b() const { return z(); };
	f32 a() const { return w(); };

	void x(const f32 v) { vec[0]=v; };
	void y(const f32 v) { vec[1]=v; };
	void z(const f32 v) { vec[2]=v; };
	void w(const f32 v) { vec[3]=v; };

	void set(f32 _x, f32 _y, f32 _z, f32 _w)
	{
		x(_x); y(_y);
		z(_z), w(_w);
	}

	float3 ToFloat3() const;

	static float4 FromXYZ(const f32 * v); 

	void zero(); // zero's the current vector
	void setall(const f32 v);

	float4 add(const float4 &v) const;
	float4 sub(const float4 &v) const;
	float4 mul(const float4 &v) const;
	float4 div(const float4 &v) const;
	
	float4 add(const f32 t) const;
	float4 sub(const f32 t) const;
	float4 mul(const f32 t) const;
	float4 div(const f32 t) const;

	f32 dot(const float4 &v) const;
	float4 cross(const float4 &v) const;
	void cross(const float4 &v, f32 * const output3d) const;

	float4 normalize() const;
	void normalize();

	f32 magnitude() const;
	f32 LengthSquared() const;
	f32 distance(const float4 &v) const;
	f32 DistanceSquared(const float4 &v) const;

	float4 negate() const;
	float4 absolute() const;

	float4 vec_lerp(const float4 &target, f32 lerpFactor);

	inline const float4& operator+=(const float4 &rhs) { *this = add(rhs); return *this; }
	inline const float4& operator-=(const float4 &rhs) { *this = sub(rhs); return *this; }
	inline const float4& operator*=(const float4 &rhs) { *this = mul(rhs); return *this; }
	inline const float4& operator/=(const float4 &rhs) { *this = div(rhs); return *this; }
	inline const float4& operator^=(const float4 &rhs) { *this = cross(rhs); return *this; }
};

// Auxiliary Functions (operator overloads)
inline float4 operator+(const float4 &a, const float4 &b) { return float4(a)+=b; }
inline float4 operator-(const float4 &a, const float4 &b) { return float4(a)-=b; }
inline float4 operator*(const float4 &a, const float4 &b) { return float4(a)*=b; }
inline float4 operator/(const float4 &a, const float4 &b) { return float4(a)/=b; }

inline float4 operator+(const float4 &a, const f32 b) { return float4(a)+=float4(b); }
inline float4 operator-(const float4 &a, const f32 b) { return float4(a)-=float4(b); }
inline float4 operator*(const float4 &a, const f32 b) { return float4(a)*=float4(b); }
inline float4 operator/(const float4 &a, const f32 b) { return float4(a)/=float4(b); }

inline float4 operator+(const f32 a, const float4 &b) { return float4(a)+=b; }
inline float4 operator-(const f32 a, const float4 &b) { return float4(a)-=b; }
inline float4 operator*(const f32 a, const float4 &b) { return float4(a)*=b; }
inline float4 operator/(const f32 a, const float4 &b) { return float4(a)/=b; }

inline float4 operator^(const float4 &a, const float4 &b) { return float4(a)^=b; }

std::ostream& operator<<(std::ostream &out, const float4 &m);
std::istream& operator>>(std::istream &in, float4& out);