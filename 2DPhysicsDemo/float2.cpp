#include "float2.h"
#include "util.h"
#include <iostream>

//const float2 float2::ZERO = float2();
//const float2 float2::ONE = float2(1.0f);

float2::~float2() { };

float2::float2() { zero(); };

float2::float2(const f32 v) { setall(v); };

float2::float2(const f32 _x, f32 _y)
{
	vec[0] = _x;
	vec[1] = _y;
};

float2::float2(const f32 * v)
{
	vec[0] = v[0];
	vec[1] = v[1];
};

void float2::zero()
{
	setall(0);
};

void float2::setall(const f32 v)
{
	vec[0] = vec[1] = v;
};

float2 float2::add(const float2 &v) const
{
	return float2(
		vec[0] + v.vec[0],
		vec[1] + v.vec[1]);
};

float2 float2::sub(const float2 &v) const
{
	return float2(
		vec[0] - v.vec[0],
		vec[1] - v.vec[1]);
};

float2 float2::mul(const float2 &v) const
{
	return float2(
		vec[0] * v.vec[0],
		vec[1] * v.vec[1]);
};

float2 float2::div(const float2 &v) const
{
	return float2(
		vec[0] / v.vec[0],
		vec[1] / v.vec[1]);
};

float2 float2::add(const f32 t) const
{
	return float2(
		vec[0] + t,
		vec[1] + t);
};

float2 float2::sub(const f32 t) const
{
	return float2(
		vec[0] - t,
		vec[1] - t);
};

float2 float2::mul(const f32 t) const
{
	return float2(
		vec[0] * t,
		vec[1] * t);
};

float2 float2::div(const f32 t) const
{
	return float2(
		vec[0] / t,
		vec[1] / t);
};

f32 float2::dot(const float2 &v) const
{
	return 
		vec[0]*v.vec[0] +
		vec[1]*v.vec[1];
};

f32 float2::length_squared() const
{
	// equivalent to dot product with self
	return (vec[0]*vec[0]) + (vec[1]*vec[1]);
};

f32 float2::magnitude() const
{
	return sqrtf(length_squared());
};

float2 float2::normalize() const
{
	f32 lsqr = length_squared();
	f32 recip = InvSqrt(lsqr);
	return float2(vec[0]*recip, vec[1]*recip);
};

f32 float2::distance(const float2 &other) const
{
	return (*this - other).magnitude();
};
f32 float2::distance_squared(const float2 &other) const
{
	return (*this - other).length_squared();
};

float2 float2::project(const float2 &other) const
{
	float2 b = other.normalize();
	return b * this->dot(b);
};

float2 float2::perpendicular_vector_left() const
{
	return float2(y(), -x());
};

float2 float2::perpendicular_vector_right() const
{
	return float2(-y(), x());
};

float2 float2::absolute() const
{
	return float2(abs(vec[0]), abs(vec[1]));
};

float2 float2::negate() const
{
	return float2(
		-vec[0],
		-vec[1]);
};

float2 float2::vec_lerp(const float2 &target, f32 lerpFactor)
{
	return float2(
		lerp(x(), target.x(), lerpFactor),
		lerp(y(), target.y(), lerpFactor));
};

std::ostream& operator<<(std::ostream &out, float2 &m)
{
	out << m.x() << ", " << m.y() << std::endl;
	return out;
};

std::istream& operator>>(std::istream &in, float2& out)
{
	f32 x,y;
	in >> x >> y;
	out.set(x,y);
	return in;
};

std::istream& operator>>(std::istream &in, vec2i& out)
{
	i32 x,y;
	in >> x >> y;
	out.set(x,y);
	return in;
};