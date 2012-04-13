#pragma once

#include "float2.h"

class Mat22
{
private:
	f32 mat[4];
	/*
	[ 0  1]   [m11 m12]
	[ 2  3]   [m21 m22]
	*/

public:
	Mat22(void);
	Mat22(const f32 * const fpArray);
	Mat22(const f32 m11, const f32 m12, const f32 m21, const f32 m22);
	~Mat22(void) {};

	const f32 * GetMatrix() const { return mat; };
	
	void SetMatrix(const f32 * const fpArray);
	void SetMatrix(const f32 m11, const f32 m12, const f32 m21, const f32 m22);

	void Identity();

	Mat22 Add(const Mat22 &other) const;
	Mat22 Add(const f32 v) const;
	
	Mat22 Sub(const Mat22 &other) const;
	Mat22 Sub(const f32 v) const;
	
	Mat22 Mul(const f32 scaleFactor) const;
	Mat22 Mul(const Mat22 &other) const;
	float2 Mul(const float2 &vec) const;
	
	f32 Determinant() const;
	Mat22 Inverse() const;

	inline const Mat22& operator+=(const Mat22 &rhs) { *this = Add(rhs); return *this; }
	inline const Mat22& operator-=(const Mat22 &rhs) { *this = Sub(rhs); return *this; }
	inline const Mat22& operator*=(const Mat22 &rhs) { *this = Mul(rhs); return *this; }
};

inline Mat22 operator+(const Mat22 &a, const Mat22 &b) { return Mat22(a)+=b; }
inline Mat22 operator-(const Mat22 &a, const Mat22 &b) { return Mat22(a)-=b; }
inline Mat22 operator*(const Mat22 &a, const Mat22 &b) { return Mat22(a)*=b; }

inline Mat22 operator+(const Mat22 &a, const f32 b) { return a.Add(b); };
inline Mat22 operator-(const Mat22 &a, const f32 b) { return a.Sub(b); };
inline Mat22 operator*(const Mat22 &a, const f32 b) { return a.Mul(b); };

/*
// NEVER PUT THE FLOAT ON THE LEFT HAND SIDE
inline Mat22 operator+(const f32 a, const Mat22 &b) { return b.Add(a); };
inline Mat22 operator-(const f32 a, const Mat22 &b) { return b.Sub(a); };
inline Mat22 operator*(const f32 a, const Mat22 &b) { return b.Mul(a); };
*/

inline float2 operator*(const Mat22 &a, const float2 &b) { return a.Mul(b); };
inline float2 operator*(const float2 &a, const Mat22 &b) { return b.Mul(a); };