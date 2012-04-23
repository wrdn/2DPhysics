#include "Mat22.h"
#include <math.h>

Mat22::Mat22(void)
{
	Identity();
};

Mat22::Mat22(const f32 * const fpArray)
{
	SetMatrix(fpArray);
};

Mat22::Mat22(const f32 m11, const f32 m12, const f32 m21, const f32 m22)
{
	SetMatrix(m11, m12, m21, m22);
};

void Mat22::SetMatrix(const f32 * const fpArray)
{
	mat[0] = fpArray[0];
	mat[1] = fpArray[1];
	mat[2] = fpArray[2];
	mat[3] = fpArray[3];
};

void Mat22::SetMatrix(const f32 m11, const f32 m12, const f32 m21, const f32 m22)
{
	mat[0] = m11;
	mat[1] = m12;
	mat[2] = m21;
	mat[3] = m22;
};

void Mat22::Identity()
{
	mat[0] = 1; mat[1] = 0;
	mat[2] = 0; mat[3] = 1;
};

Mat22 Mat22::RotationMatrix(f32 angle)
{
	f32 c = cosf(angle);
	f32 s = sinf(angle);

	return Mat22(c, s, -s, c);
};

Mat22 Mat22::Add(const Mat22 &other) const
{
	return Mat22(
		mat[0]+other.mat[0],
		mat[1]+other.mat[1],
		mat[2]+other.mat[2],
		mat[3]+other.mat[3]);
};

Mat22 Mat22::Add(const f32 v) const
{
	return Mat22(
		mat[0]+v,
		mat[1]+v,
		mat[2]+v,
		mat[3]+v);
};

Mat22 Mat22::Sub(const Mat22 &other) const
{
	return Mat22(
		mat[0]-other.mat[0],
		mat[1]-other.mat[1],
		mat[2]-other.mat[2],
		mat[3]-other.mat[3]);
};

Mat22 Mat22::Sub(const f32 v) const
{
	return Mat22(
		mat[0]-v,
		mat[1]-v,
		mat[2]-v,
		mat[3]-v);
};

Mat22 Mat22::Mul(const f32 scaleFactor) const
{
	return Mat22(
		mat[0]*scaleFactor,
		mat[1]*scaleFactor,
		mat[2]*scaleFactor,
		mat[3]*scaleFactor);
};

Mat22 Mat22::Mul(const Mat22 &other) const
{
	return Mat22(
		(mat[0]*other.mat[0])+(mat[1]*other.mat[2]),
		(mat[0]*other.mat[1])+(mat[1]*other.mat[3]),
		(mat[2]*other.mat[0])+(mat[3]*other.mat[2]),
		(mat[2]*other.mat[1])+(mat[3]*other.mat[3]));
};

float2 Mat22::Mul(const float2 &vec) const
{
	return float2(mat[0]*vec.x + mat[1]*vec.y,
		mat[2]*vec.x + mat[3]*vec.y);
};

f32 Mat22::Determinant() const
{
	return (mat[0]*mat[3]) - (mat[1]*mat[2]);
};

Mat22 Mat22::Inverse() const
{
	f32 det = Determinant();
	return Mat22(mat[3], -mat[1], -mat[2], mat[0]).Mul(det);
};

Mat22 Mat22::Transpose() const
{
	return Mat22(mat[0], mat[2], mat[1], mat[3]);
};