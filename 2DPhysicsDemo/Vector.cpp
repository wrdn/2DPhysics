#include "Vector.h"
#include "Matrix.h"

Vector Vector::operator * (const Matrix& M) const
{
	Vector T;
	T.x = x * M.e11 + y * M.e12;
	T.y = x * M.e21 + y * M.e22;
	return T;
}

Vector Vector::operator ^ (const Matrix& M) const
{
	Vector T;
	T.x = x * M.e11 + y * M.e21;
	T.y = x * M.e12 + y * M.e22;
	return T;
}

Vector& Vector::operator *=(const Matrix& M)
{
	Vector T = *this;
	x = T.x * M.e11 + T.y * M.e12;
	y = T.x * M.e21 + T.y * M.e22;
	return *this;
}

Vector& Vector::operator ^=(const Matrix& M)
{
	Vector T = *this;
	x = T.x * M.e11 + T.y * M.e21;
	y = T.x * M.e12 + T.y * M.e22;
	return *this;
}

bool FindRoots(float a, float b, float c, float& t0, float& t1)
{
	float d = b*b - (4.0f * a * c);

	if (d < 0.0f)
		return false;

	d = (float) sqrt(d);

	float one_over_two_a = 1.0f / (2.0f * a);

	t0 = (-b - d) * one_over_two_a;
	t1 = (-b + d) * one_over_two_a;

	if (t1 < t0)
	{
		float t = t0;
		t0 = t1;
		t1 = t;
	}
	return true;
}


bool RaySphereIntersection(const Vector& C, float r, const Vector& O, const Vector& D, float tmin, float tmax, float& t)
{
	float t0, t1;

	Vector H = (O - C);
	float  a = (D * D);
	float  b = (H * D) * 2.0f;
	float  c = (H * H) - r*r;

	if (!FindRoots(a, b, c, t0, t1))
		return false;

	if (t0 > tmax || t1 < tmin)
		return false;

	t = t0;

	if (t0 < tmin)
		t = t1;

	return true;
}