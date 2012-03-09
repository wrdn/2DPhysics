#include "float3.h"
#include "float4.h"
#include "util.h"

const float3 float3::ZERO = float3();
const float3 float3::ONE = float3();

float3::float3(void)
{
	zero();
}

float3::~float3(void)
{
}

float3::float3(const f32 v)
{
	setall(v);
};

float3::float3(const f32 _x, f32 _y, f32 _z)
{
	vec[0] = _x;
	vec[1] = _y;
	vec[2] = _z;
};

float3::float3(const f32 * v)
{
	vec[0] = v[0];
	vec[1] = v[1];
	vec[2] = v[2];
};

float4 float3::ToFloat4() const
{
	return float4(x(), y(), z(), 0);
};

void float3::setall(const f32 v)
{
	vec[0] = vec[1] = vec[2] = v;
};

void float3::zero() // zero's the current vector
{
	setall(0);
};

float3 float3::add(const float3 &v) const
{
	return float3(vec[0]+v.vec[0], vec[1]+v.vec[1], vec[2]+v.vec[2]);
};

float3 float3::sub(const float3 &v) const
{
	return float3(vec[0]-v.vec[0], vec[1]-v.vec[1], vec[2]-v.vec[2]);
};

float3 float3::mul(const float3 &v) const
{
	return float3(vec[0]*v.vec[0], vec[1]*v.vec[1], vec[2]*v.vec[2]);
};

float3 float3::div(const float3 &v) const
{
	return float3(vec[0]/v.vec[0], vec[1]/v.vec[1], vec[2]/v.vec[2]);
};

float3 float3::add(const f32 t) const
{
	return float3(vec[0]+t, vec[1]+t, vec[2]+t);
};

float3 float3::sub(const f32 t) const
{
	return float3(vec[0]-t, vec[1]-t, vec[2]-t);
};

float3 float3::mul(const f32 t) const
{
	return float3(vec[0]*t, vec[1]*t, vec[2]*t);
};

float3 float3::div(const f32 t) const
{
	return float3(vec[0]/t, vec[1]/t, vec[2]/t);
};

f32 float3::dot(const float3 &v) const
{
	return (vec[0] * v.vec[0]) + (vec[1] * v.vec[1]) + (vec[2] * v.vec[2]);
};

float3 float3::cross(const float3 &v) const
{
	return float3(
		(vec[1] * v.vec[2]) - (vec[2] * v.vec[1]),
		(vec[2] * v.vec[0]) - (vec[0] * v.vec[2]),
		(vec[0] * v.vec[1]) - (vec[1] * v.vec[0]));
};

void float3::cross(const float3 &v, f32 * const output3d) const
{
	output3d[0] = (vec[1] * v.vec[2]) - (vec[2] * v.vec[1]);
	output3d[1] = (vec[2] * v.vec[0]) - (vec[0] * v.vec[2]);
	output3d[2] = (vec[0] * v.vec[1]) - (vec[1] * v.vec[0]);
};

float3 float3::normalize() const
{
	f32 lsqr = LengthSquared();
	if(NearZero(lsqr)) { return ZERO; };
	f32 recip = InvSqrt(lsqr);
	
	return float3(vec[0]*recip, vec[1]*recip, vec[2]*recip);
};

void float3::normalize()
{
	f32 lsqr = LengthSquared();
	if(NearZero(lsqr)) { *this = ZERO; };
	f32 recip = InvSqrt(lsqr);
	vec[0] *= recip;
	vec[1] *= recip;
	vec[2] *= recip;
};

f32 float3::magnitude() const
{
	return sqrtf( LengthSquared() );
};

f32 float3::LengthSquared() const
{
	return (vec[0]*vec[0]) + (vec[1]*vec[1]) + (vec[2]*vec[2]);
};

f32 float3::distance(const float3 &v) const
{
	return this->sub(v).magnitude();
};

f32 float3::DistanceSquared(const float3 &v) const
{
	return this->sub(v).LengthSquared();
};

float3 float3::negate() const
{
	return float3(-vec[0], -vec[1], -vec[2]);
};

float3 float3::absolute() const
{
	return float3(fabs(vec[0]), fabs(vec[1]), fabs(vec[2]));
};

float3 float3::vec_lerp(const float3 &target, f32 lerpFactor)
{
	return float3(
		lerp(x(), target.x(), lerpFactor),
		lerp(y(), target.y(), lerpFactor),
		lerp(z(), target.z(), lerpFactor));
};

std::ostream& operator<<(std::ostream &out, const float3 &m)
{
	f32 * vec = m.GetVec();
	std::cout << "{" << vec[0] << "," << vec[1] << "," << vec[2] << "}";
	return out;
};

std::istream& operator>>(std::istream &in, float3& out)
{
	f32 x=0, y=0, z=0;
	in >> x >> y >> z;
	out.set(x, y, z);
	return in;
};