#include "float2.h"
#include "util.h"
#include <iostream>

const float2 float2::ZERO = float2();
const float2 float2::ONE = float2(1.0f);

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