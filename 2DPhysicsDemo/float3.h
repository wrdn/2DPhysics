#pragma once

#include "ctypes.h"
#include <iostream>

class float4;
class float3
{
private:
	f32 vec[3];

public:
	f32 * GetVec() const { return (f32*)vec; };

	//static const float3 ZERO;
	//static const float3 ONE;

	f32 x() const { return vec[0]; };
	f32 y() const { return vec[1]; };
	f32 z() const { return vec[2]; };

	f32 r() const { return x(); };
	f32 g() const { return y(); };
	f32 b() const { return z(); };

	void x(const f32 v) { vec[0]=v; };
	void y(const f32 v) { vec[1]=v; };
	void z(const f32 v) { vec[2]=v; };

	void set(const f32 x, const f32 y, const f32 z)
	{
		vec[0] = x;
		vec[1] = y;
		vec[2] = z;
	};
	void set(const f32 * const v)
	{
		vec[0] = v[0];
		vec[1] = v[1];
		vec[2] = v[2];
	};

	~float3();
	float3(); // sets all to 0
	explicit float3(const f32 v);
	float3(const f32 _x, f32 _y, f32 _z);
	explicit float3(const f32 * v);

	float4 ToFloat4() const;

	void zero(); // zero's the current vector
	void setall(const f32 v);

	float3 add(const float3 &v) const;
	float3 sub(const float3 &v) const;
	float3 mul(const float3 &v) const;
	float3 div(const float3 &v) const;
	
	float3 add(const f32 t) const;
	float3 sub(const f32 t) const;
	float3 mul(const f32 t) const;
	float3 div(const f32 t) const;

	f32 dot(const float3 &v) const;
	float3 cross(const float3 &v) const;
	void cross(const float3 &v, f32 * const output3d) const;

	float3 normalize() const;
	void normalize();

	f32 magnitude() const;
	f32 LengthSquared() const;
	f32 distance(const float3 &v) const;
	f32 DistanceSquared(const float3 &v) const;

	float3 negate() const;
	float3 absolute() const;

	float3 vec_lerp(const float3 &target, f32 lerpFactor);

	inline const float3& operator+=(const float3 &rhs) { *this = add(rhs); return *this; }
	inline const float3& operator-=(const float3 &rhs) { *this = sub(rhs); return *this; }
	inline const float3& operator*=(const float3 &rhs) { *this = mul(rhs); return *this; }
	inline const float3& operator/=(const float3 &rhs) { *this = div(rhs); return *this; }
	inline const float3& operator^=(const float3 &rhs) { *this = cross(rhs); return *this; }
};

// Auxiliary Functions (operator overloads)
inline float3 operator+(const float3 &a, const float3 &b) { return float3(a)+=b; }
inline float3 operator-(const float3 &a, const float3 &b) { return float3(a)-=b; }
inline float3 operator*(const float3 &a, const float3 &b) { return float3(a)*=b; }
inline float3 operator/(const float3 &a, const float3 &b) { return float3(a)/=b; }

inline float3 operator+(const float3 &a, const f32 b) { return float3(a)+=float3(b); }
inline float3 operator-(const float3 &a, const f32 b) { return float3(a)-=float3(b); }
inline float3 operator*(const float3 &a, const f32 b) { return float3(a)*=float3(b); }
inline float3 operator/(const float3 &a, const f32 b) { return float3(a)/=float3(b); }

/*
// NEVER PUT THE FLOAT ON THE LEFT HAND SIDE
inline float3 operator+(const f32 a, const float3 &b) { return float3(a)+=b; }
inline float3 operator-(const f32 a, const float3 &b) { return float3(a)-=b; }
inline float3 operator*(const f32 a, const float3 &b) { return float3(a)*=b; }
inline float3 operator/(const f32 a, const float3 &b) { return float3(a)/=b; }
*/

inline float3 operator^(const float3 &a, const float3 &b) { return float3(a)^=b; }

std::ostream& operator<<(std::ostream &out, const float3 &m);
std::istream& operator>>(std::istream &in, float3& out);