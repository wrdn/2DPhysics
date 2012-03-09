#include "Quaternion.h"
#include "util.h"
#include <cmath>

Quaternion::Quaternion() { identity(); };

Quaternion::Quaternion(const f32 x, const f32 y, const f32 z, const f32 w) { set(x,y,z,w); };

Quaternion::Quaternion(const float3 &v) { set(v,0.0f); };

Quaternion::Quaternion(const float3& axis, const f32 angle_in_radians) { *this = Quaternion::FromAxisAngle(axis,angle_in_radians); }

void Quaternion::identity() { set(0,0,0,1); } // identity quaternion (no rotation)

Quaternion Quaternion::add(const Quaternion &q) const
{
	return Quaternion(x()+q.x(), y()+q.y(), z()+q.z(), w()+q.w());
};

Quaternion Quaternion::sub(const Quaternion &q) const
{
	return Quaternion(x()-q.x(), y()-q.y(), z()-q.z(), w()-q.w());
};

// component wise multiplication
Quaternion Quaternion::mult(const f32 scale) const
{
	return Quaternion(scale*x(), scale*y(), scale*z(), scale*w());
};

Quaternion Quaternion::mult(const Quaternion &q) const
{
	// Quaternion Multiplication:
	// Given v1=q1.tovec3() and v2=q2.tovec3()
	// w   = q1.w*q2.w - dot(v1,v2)
	// xyz = q1.w*v2 + q2.w*v1 + cross(v2,v1)
	// Final Quaternion = (x,y,z,w)
	return Quaternion(
		w()*q.x() + x()*q.w() + y()*q.z()-z()*q.y(),
		w()*q.y() + y()*q.w() + z()*q.x()-x()*q.z(),
		w()*q.z() + z()*q.w() + x()*q.y()-y()*q.x(),
		w()*q.w() - x()*q.x() - y()*q.y() - z()*q.z()
		);
};

f32 Quaternion::magnitude() const
{
	return sqrt(length_sq());
};

Quaternion Quaternion::normalize() const
{
	return mult(reciprocal_sqrt(length_sq()));
};

// same as inverse for unit length quaternion
Quaternion Quaternion::conjugate() const
{
	CHECK_NORMALISED(magnitude());

	return Quaternion(-x(), -y(), -z(), w());
};

f32 Quaternion::dot(const Quaternion &q) const
{
	return (x()*q.x() + y()*q.y() + z()*q.z() + w()*q.w());
};

// w=cos(angle/2), xyz=axis.xyz*sin(angle)
Quaternion Quaternion::FromAxisAngle(const float3 &axis, const f32 angle_in_radians)
{
	CHECK_NORMALISED(axis.magnitude());

	f32 t = angle_in_radians*0.5f;
	f32 sinAngle = sin(t);
	return Quaternion(axis.x()*sinAngle, axis.y()*sinAngle, axis.z()*sinAngle, cos(t));
};

Quaternion Quaternion::FromEulerAngles(const f32 yaw, const f32 pitch, const f32 roll)
{
	const f32 PIOVER180OVER2 = PIOVER180 / 2.0f;
	f32 y = yaw * PIOVER180OVER2;
	f32 p = pitch * PIOVER180OVER2;
	f32 r = roll * PIOVER180OVER2;

	f32 siny = sin(y), sinp = sin(p), sinr = sin(r);
	f32 cosy = cos(y), cosp = cos(p), cosr = cos(r);

	return Quaternion(
		sinr * cosp * cosy - cosr * sinp * siny,
		cosr * sinp * cosy + sinr * cosp * siny,
		cosr * cosp * siny - sinr * sinp * cosy,
		cosr * cosp * cosy + sinr * sinp * siny);
};

Mat44 Quaternion::ToMat44() const
{
	CHECK_NORMALISED(magnitude());

	// SSE version (define 2 matrices and multiply)
	Mat44 ma(
		w()  , -z() , y()  , x(),
		z()  , w()  , -x() , y(),
		-y() , x()  , w()  , z(),
		-x() , -y() , -z() , w());
	Mat44 mb(
		w()  , -z() , y()  , -x(),
		z()  , w()  , -x() , -y(),
		-y() , x()  , w()  , -z(),
		x()  , y()  , z()  , w());
	return ma.Mult(mb);

	/*
	// Scalar version
	float x2 = x() * x();
	float y2 = y() * y();
	float z2 = z() * z();
	float xy = x() * y();
	float xz = x() * z();
	float yz = y() * z();
	float wx = w() * x();
	float wy = w() * y();
	float wz = w() * z();
	
	return Mat44(
		1.0f - 2.0f * (y2 + z2), 2.0f * (xy - wz), 2.0f * (xz + wy), 0.0f,
		2.0f * (xy + wz), 1.0f - 2.0f * (x2 + z2), 2.0f * (yz - wx), 0.0f,
		2.0f * (xz - wy), 2.0f * (yz + wx), 1.0f - 2.0f * (x2 + y2), 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f);
	*/
};

void Quaternion::ExtractAxisAngle(float3 &out_axis, f32 &out_angle) const
{
	f32 scale = reciprocal_sqrt(length_sq());
	out_axis.set( x()*scale, y()*scale, z()*scale );
	out_angle = acos(w()) * 2.0f;
};

float3 Quaternion::rotate(const float3& v) const
{
	CHECK_NORMALISED(v.magnitude());

	//             q *  Quaternion(vec)   *     q^-1
	//return this->mult( Quaternion(v).mult( this->conjugate() ) ).tofloat3();
	return (*this * Quaternion(v) * this->conjugate()).tofloat3();
};

// lerp from 'this' to q using t
Quaternion Quaternion::lerp(const Quaternion &q, const f32 t) const
{
	return this->mult(1.0f-t).add(q.mult(t));
};
Quaternion Quaternion::lerp(const Quaternion &q1, const Quaternion &q2, const f32 t)
{
	return q1.lerp(q2, t);
};

Quaternion Quaternion::slerp(const Quaternion &q2, const f32 t) const
{
	f32 angle = this->dot(q2);
	Quaternion q1 = *this;
	if(angle < 0.0f)
	{
		q1 = q1.mult(-1.0f);
		angle *= -1.0f;
	}
	if(angle <= 0.95f)
	{
		const f32 theta = acos(angle);
		const f32 invsintheta = 1.0f / sin(theta);
		const f32 scale = sin(theta * (1.0f-t)) * invsintheta;
		const f32 invscale = sin(theta*t) * invsintheta;
		return q1.mult(scale).add(q2.mult(invscale));
	}
	else
	{
		return q1.lerp(q2,t);
	}
};
Quaternion Quaternion::slerp(const Quaternion &q1, const Quaternion &q2, const f32 t)
{
	return q1.slerp(q2, t);
};
