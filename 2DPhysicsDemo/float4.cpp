#include "float4.h"
#include "float3.h"

#include "util.h"
#include <math.h>

//const float4 float4::ZERO = float4((f32)0.0f);
//const float4 float4::ONE  = float4((f32)1.0f);

float3 float4::ToFloat3() const
{
	return float3(vec);
};

float4::float4()
{
	zero();
};

float4::float4(const f32 v)
{
	setall(v);
};

float4::float4(const f32 _x, f32 _y, f32 _z, f32 _w)
{
	vec[0] = _x;
	vec[1] = _y;
	vec[2] = _z;
	vec[3] = _w;
};

float4::float4(const f32 _x, f32 _y, f32 _z)
{
	vec[0] = _x;
	vec[1] = _y;
	vec[2] = _z;
	vec[3] = 0;
};

float4::float4(const f32 * v)
{
	vec[0] = v[0];
	vec[1] = v[1];
	vec[2] = v[2];
	vec[3] = v[3];
};

float4 float4::FromXYZ(const f32 * v)
{
	return float4(v[0], v[1], v[2]);
};

void float4::setall(const f32 v)
{
	vec[0] = vec[1] = vec[2] = vec[3] = v;
};

void float4::zero() { setall(0); };

float4 float4::add(const float4 &v) const
{
	return float4(
		vec[0] + v.vec[0],
		vec[1] + v.vec[1],
		vec[2] + v.vec[2],
		vec[3] + v.vec[3]);
};

float4 float4::sub(const float4 &v) const
{
	return float4(
		vec[0] - v.vec[0],
		vec[1] - v.vec[1],
		vec[2] - v.vec[2],
		vec[3] - v.vec[3]);
};

float4 float4::mul(const float4 &v) const
{
	return float4(
		vec[0] * v.vec[0],
		vec[1] * v.vec[1],
		vec[2] * v.vec[2],
		vec[3] * v.vec[3]);
};

float4 float4::mul(const f32 t) const
{
	return float4(
		vec[0] * t,
		vec[1] * t,
		vec[2] * t,
		vec[3] * t);
};

float4 float4::div(const float4 &v) const
{
	return float4(
		vec[0] / v.vec[0],
		vec[1] / v.vec[1],
		vec[2] / v.vec[2],
		vec[3] / v.vec[3]);
};

float4 float4::div(const f32 t) const
{
	return float4(
		vec[0] / t,
		vec[1] / t,
		vec[2] / t,
		vec[3] / t);
};

float4 float4::add(const f32 t) const
{
	return float4(
		vec[0] + t,
		vec[1] + t,
		vec[2] + t,
		vec[3] + t);
};

float4 float4::sub(const f32 t) const
{
	return float4(
		vec[0] - t,
		vec[1] - t,
		vec[2] - t,
		vec[3] - t);
};

f32 float4::dot(const float4 &v) const
{
	return (vec[0] * v.vec[0]) + (vec[1] * v.vec[1]) + (vec[2] * v.vec[2]) + (vec[3] * v.vec[3]);
};

float4 float4::cross(const float4 &v) const
{
	return float4(
		(vec[1] * v.vec[2]) - (vec[2] * v.vec[1]),
		(vec[2] * v.vec[0]) - (vec[0] * v.vec[2]),
		(vec[0] * v.vec[1]) - (vec[1] * v.vec[0]),
		0);
};

void float4::cross(const float4 &v, f32 * const output3d) const
{
	output3d[0] = (vec[1] * v.vec[2]) - (vec[2] * v.vec[1]);
	output3d[1] = (vec[2] * v.vec[0]) - (vec[0] * v.vec[2]);
	output3d[2] = (vec[0] * v.vec[1]) - (vec[1] * v.vec[0]);
};

f32 float4::magnitude() const
{
	return sqrtf( LengthSquared() );
};
f32 float4::LengthSquared() const
{
	return (vec[0]*vec[0]) + (vec[1]*vec[1]) + (vec[2]*vec[2]) + (vec[3]*vec[3]);
};

f32 float4::distance(const float4 &v) const
{
	return this->sub(v).magnitude();
};

f32 float4::DistanceSquared(const float4 &v) const
{
	return this->sub(v).LengthSquared();
};

float4 float4::normalize() const
{
	f32 lsqr = LengthSquared();
	if(NearZero(lsqr)) { return float4(0.0f); };
	f32 recip = InvSqrt(lsqr);
	
	return float4(vec[0]*recip, vec[1]*recip, vec[2]*recip, vec[3]*recip);
};

void float4::normalize()
{
	f32 lsqr = LengthSquared();
	if(NearZero(lsqr)) { this->setall(0); return; };
	f32 recip = InvSqrt(lsqr);
	vec[0] *= recip;
	vec[1] *= recip;
	vec[2] *= recip;
	vec[3] *= recip;
};

float4 float4::negate() const
{
	return float4(
		-vec[0],
		-vec[1],
		-vec[2],
		-vec[3]);
};

float4 float4::absolute() const
{
	return float4(fabs(vec[0]), fabs(vec[1]), fabs(vec[2]), fabs(vec[3]));
};

float4 float4::vec_lerp(const float4 &target, f32 lerpFactor)
{
	return float4(
		lerp(x(), target.x(), lerpFactor),
		lerp(y(), target.y(), lerpFactor),
		lerp(z(), target.z(), lerpFactor),
		lerp(w(), target.w(), lerpFactor));
};

std::ostream& operator<<(std::ostream &out, const float4 &m)
{
	f32 * vec = m.GetVec();
	std::cout << "{" << vec[0] << "," << vec[1] << "," << vec[2] << "," << vec[3] << "}";
	return out;
};

std::istream& operator>>(std::istream &in, float4& out)
{
	f32 x=0, y=0, z=0, w=0;
	in >> x >> y >> z >> w;
	out.set(x, y, z, w);
	return in;
};