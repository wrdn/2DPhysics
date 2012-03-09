#include "Mat44.h"
#include "float4.h"
#include "float3.h"
#include "util.h"
#include <pmmintrin.h>

const f32 IDENTITY_MAT44_DATA[] = 
{
	1, 0, 0, 0,
	0, 1, 0, 0,
	0, 0, 1, 0,
	0, 0, 0, 1
};

const Mat44 Mat44::IDENTITY = Mat44();

Mat44::Mat44(void)
{
	// Alternative to memcpy (in SetMatrix) is to memset(...) all to 0, then set mat indices 0,5,10 and 15 to 1
	SetMatrix(IDENTITY_MAT44_DATA);
}

Mat44::Mat44(const f32* _mat) // use existing FP array to initialise the matrix
{
	SetMatrix(_mat);
};

Mat44::Mat44(
	const f32 m11, const f32 m12, const f32 m13, const f32 m14,
	const f32 m21, const f32 m22, const f32 m23, const f32 m24,
	const f32 m31, const f32 m32, const f32 m33, const f32 m34,
	const f32 m41, const f32 m42, const f32 m43, const f32 m44)
{
	SetMatrix(
		m11, m12, m13, m14,
		m21, m22, m23, m24,
		m31, m32, m33, m34,
		m41, m42, m43, m44);
};

void Mat44::SetMatrix(const f32 m11, const f32 m12, const f32 m13, const f32 m14,
	const f32 m21, const f32 m22, const f32 m23, const f32 m24,
	const f32 m31, const f32 m32, const f32 m33, const f32 m34,
	const f32 m41, const f32 m42, const f32 m43, const f32 m44)
{
	// set each value individually
	mat[0]  = m11;  mat[1]  = m12;  mat[2]  = m13;  mat[3]  = m14;
	mat[4]  = m21;  mat[5]  = m22;  mat[6]  = m23;  mat[7]  = m24;
	mat[8]  = m31;  mat[9]  = m32;  mat[10] = m33;  mat[11] = m34;
	mat[12] = m41;  mat[13] = m42;  mat[14] = m43;  mat[15] = m44;
};

Mat44::~Mat44(void)
{
}

const f32* Mat44::GetMatrix() const
{
	return mat;
};

void Mat44::SetMatrix(const f32* _mat) const
{
	memcpy((f32*)mat, _mat, sizeof(f32) * Mat44::MATRIX_ELEMENT_COUNT);
};

void Mat44::Identity() const
{
	SetMatrix(IDENTITY_MAT44_DATA);
};

Mat44 Mat44::Add(const Mat44 &m) const
{
	__m128 mat1rows[] = { _mm_load_ps(mat), _mm_load_ps(mat+4), _mm_load_ps(mat+8), _mm_load_ps(mat+12) };
	__m128 mat2rows[] = { _mm_load_ps(m.mat), _mm_load_ps(m.mat+4), _mm_load_ps(m.mat+8), _mm_load_ps(m.mat+12) };

	Mat44 res;
	_mm_store_ps(res.mat   , _mm_add_ps(mat1rows[0], mat2rows[0]));
	_mm_store_ps(res.mat+4 , _mm_add_ps(mat1rows[1], mat2rows[1]));
	_mm_store_ps(res.mat+8 , _mm_add_ps(mat1rows[2], mat2rows[2]));
	_mm_store_ps(res.mat+12, _mm_add_ps(mat1rows[3], mat2rows[3]));
	return res;
};

Mat44 Mat44::Add(const f32 v) const
{
	__m128 mat1rows[] = { _mm_load_ps(mat), _mm_load_ps(mat+4), _mm_load_ps(mat+8), _mm_load_ps(mat+12) };
	__m128 splatAdd = _mm_load1_ps(&v);

	Mat44 res;
	_mm_store_ps(res.mat   , _mm_add_ps(mat1rows[0], splatAdd));
	_mm_store_ps(res.mat+4 , _mm_add_ps(mat1rows[1], splatAdd));
	_mm_store_ps(res.mat+8 , _mm_add_ps(mat1rows[2], splatAdd));
	_mm_store_ps(res.mat+12, _mm_add_ps(mat1rows[3], splatAdd));
	return res;
};

Mat44 Mat44::Sub(const Mat44 &m) const
{
	__m128 mat1rows[] = { _mm_load_ps(mat), _mm_load_ps(mat+4), _mm_load_ps(mat+8), _mm_load_ps(mat+12) };
	__m128 mat2rows[] = { _mm_load_ps(m.mat), _mm_load_ps(m.mat+4), _mm_load_ps(m.mat+8), _mm_load_ps(m.mat+12) };

	Mat44 res;
	_mm_store_ps(res.mat   , _mm_sub_ps(mat1rows[0], mat2rows[0]));
	_mm_store_ps(res.mat+4 , _mm_sub_ps(mat1rows[1], mat2rows[1]));
	_mm_store_ps(res.mat+8 , _mm_sub_ps(mat1rows[2], mat2rows[2]));
	_mm_store_ps(res.mat+12, _mm_sub_ps(mat1rows[3], mat2rows[3]));
	return res;
};

Mat44 Mat44::Sub(const f32 v) const
{
	__m128 mat1rows[] = { _mm_load_ps(mat), _mm_load_ps(mat+4), _mm_load_ps(mat+8), _mm_load_ps(mat+12) };
	__m128 splatSub = _mm_load1_ps(&v);

	Mat44 res;
	_mm_store_ps(res.mat   , _mm_sub_ps(mat1rows[0], splatSub));
	_mm_store_ps(res.mat+4 , _mm_sub_ps(mat1rows[1], splatSub));
	_mm_store_ps(res.mat+8 , _mm_sub_ps(mat1rows[2], splatSub));
	_mm_store_ps(res.mat+12, _mm_sub_ps(mat1rows[3], splatSub));
	return res;
};

Mat44 Mat44::Mult(const f32 scale) const
{
	__m128 mat1rows[] = { _mm_load_ps(mat), _mm_load_ps(mat+4), _mm_load_ps(mat+8), _mm_load_ps(mat+12) };
	__m128 splatMult = _mm_load1_ps(&scale);

	Mat44 res;
	_mm_store_ps(res.mat   , _mm_mul_ps(mat1rows[0], splatMult));
	_mm_store_ps(res.mat+4 , _mm_mul_ps(mat1rows[1], splatMult));
	_mm_store_ps(res.mat+8 , _mm_mul_ps(mat1rows[2], splatMult));
	_mm_store_ps(res.mat+12, _mm_mul_ps(mat1rows[3], splatMult));
	return res;
};

Mat44 Mat44::Mult_ComponentWise(const Mat44 &m) const
{
	__m128 mat1rows[] = { _mm_load_ps(mat), _mm_load_ps(mat+4), _mm_load_ps(mat+8), _mm_load_ps(mat+12) };
	__m128 mat2rows[] = { _mm_load_ps(m.mat), _mm_load_ps(m.mat+4), _mm_load_ps(m.mat+8), _mm_load_ps(m.mat+12) };

	Mat44 res;
	_mm_store_ps(res.mat   , _mm_mul_ps(mat1rows[0], mat2rows[0]));
	_mm_store_ps(res.mat+4 , _mm_mul_ps(mat1rows[1], mat2rows[1]));
	_mm_store_ps(res.mat+8 , _mm_mul_ps(mat1rows[2], mat2rows[2]));
	_mm_store_ps(res.mat+12, _mm_mul_ps(mat1rows[3], mat2rows[3]));
	return res;
};

Mat44 Mat44::Mult(const Mat44 &m) const
{
	Mat44 a = Transpose();
	Mat44 b = m.Transpose();
	Mat44 out;

	__m128 a_line, b_line, r_line;
	for(c8 i=0;i<16;i+=4)
	{
		// First column
		a_line = _mm_load_ps(a.mat);
		b_line = _mm_load1_ps(&b.mat[i]);
		r_line = _mm_mul_ps(a_line, b_line);

		// Second column
		a_line = _mm_load_ps(&a.mat[4]);
		b_line = _mm_load1_ps(&b.mat[i+1]);
		r_line = _mm_add_ps(_mm_mul_ps(a_line, b_line), r_line);

		// Third column
		a_line = _mm_load_ps(&a.mat[8]);
		b_line = _mm_load1_ps(&b.mat[i+2]);
		r_line = _mm_add_ps(_mm_mul_ps(a_line, b_line), r_line);

		// Last column
		a_line = _mm_load_ps(&a.mat[12]);
		b_line = _mm_load1_ps(&b.mat[i+3]);
		r_line = _mm_add_ps(_mm_mul_ps(a_line, b_line), r_line);

		_mm_store_ps(&out.mat[i], r_line);
	}

	return out.Transpose();
};

float4 Mat44::Mult(const float4 &m) const
{
	Mat44 tr = Transpose();
	__m128 matcols[] =
	{
		_mm_load_ps(tr.mat),
		_mm_load_ps(tr.mat+4),
		_mm_load_ps(tr.mat+8),
		_mm_load_ps(tr.mat+12)
	};

	__m128 v = _mm_load_ps(m.GetVec());

	// Broadcast vector into SSE registers
	__m128 xb = _mm_shuffle_ps(v,v,0x00);
	__m128 yb = _mm_shuffle_ps(v,v,0x55);
	__m128 zb = _mm_shuffle_ps(v,v,0xAA);
	__m128 wb = _mm_shuffle_ps(v,v,0xFF);

	// Perform multiplication by matrix columns
	xb = _mm_mul_ps(xb, matcols[0]);
	yb = _mm_mul_ps(yb, matcols[1]);
	zb = _mm_mul_ps(zb, matcols[2]);
	wb = _mm_mul_ps(wb, matcols[3]);

	// Add results
	__m128 r = _mm_add_ps(_mm_add_ps(xb, yb),_mm_add_ps(zb, wb));

	float4 returnVec;
	_mm_store_ps(returnVec.GetVec(), r);
	return returnVec;
};

void Mat44::BatchMult(const float4 * const in, float4 *out, u32 len) const
{
	Mat44 tr = Transpose();
	__m128 matcols[] =
	{
		_mm_load_ps(tr.mat),
		_mm_load_ps(tr.mat+4),
		_mm_load_ps(tr.mat+8),
		_mm_load_ps(tr.mat+12)
	};

	while(len--)
	{
		__m128 v = _mm_load_ps(in[len].GetVec());
		_mm_prefetch((const char*)&in[len+1], _MM_HINT_T0);

		// Broadcast vector into SSE registers
		__m128 xb = _mm_shuffle_ps(v,v,0x00);
		__m128 yb = _mm_shuffle_ps(v,v,0x55);
		__m128 zb = _mm_shuffle_ps(v,v,0xAA);
		__m128 wb = _mm_shuffle_ps(v,v,0xFF);

		// Perform multiplication by matrix columns
		xb = _mm_mul_ps(xb, matcols[0]);
		yb = _mm_mul_ps(yb, matcols[1]);
		zb = _mm_mul_ps(zb, matcols[2]);
		wb = _mm_mul_ps(wb, matcols[3]);

		// Add results
		__m128 r = _mm_add_ps(_mm_add_ps(xb, yb),_mm_add_ps(zb, wb));

		_mm_prefetch((const char*)&out[len+1], _MM_HINT_T0);
		_mm_store_ps(out[len].GetVec(), r);
	}
};

void Mat44::Cramers_Inverse(const Mat44 *out, f32 &det) const
{
	f32 tmp[12]; /* temp array for pairs                      */

	f32 *src = Transpose().mat, *dst;
	Mat44 outp;

	if(out)
		dst = (f32*)out->mat;
	else
		dst = outp.mat;

	/* calculate pairs for first 8 elements (cofactors) */
	tmp[0]  = src[10] * src[15];
	tmp[1]  = src[11] * src[14];
	tmp[2]  = src[9]  * src[15];
	tmp[3]  = src[11] * src[13];
	tmp[4]  = src[9]  * src[14];
	tmp[5]  = src[10] * src[13];
	tmp[6]  = src[8]  * src[15];
	tmp[7]  = src[11] * src[12];
	tmp[8]  = src[8]  * src[14];
	tmp[9]  = src[10] * src[12];
	tmp[10] = src[8]  * src[13];
	tmp[11] = src[9]  * src[12];

	/* calculate first 8 elements (cofactors) */
	dst[0]  = tmp[0]*src[5] + tmp[3]*src[6] + tmp[4]*src[7];
	dst[0] -= tmp[1]*src[5] + tmp[2]*src[6] + tmp[5]*src[7];
	dst[1]  = tmp[1]*src[4] + tmp[6]*src[6] + tmp[9]*src[7];
	dst[1] -= tmp[0]*src[4] + tmp[7]*src[6] + tmp[8]*src[7];
	dst[2]  = tmp[2]*src[4] + tmp[7]*src[5] + tmp[10]*src[7];
	dst[2] -= tmp[3]*src[4] + tmp[6]*src[5] + tmp[11]*src[7];
	dst[3]  = tmp[5]*src[4] + tmp[8]*src[5] + tmp[11]*src[6];
	dst[3] -= tmp[4]*src[4] + tmp[9]*src[5] + tmp[10]*src[6];
	dst[4]  = tmp[1]*src[1] + tmp[2]*src[2] + tmp[5]*src[3];
	dst[4] -= tmp[0]*src[1] + tmp[3]*src[2] + tmp[4]*src[3];
	dst[5]  = tmp[0]*src[0] + tmp[7]*src[2] + tmp[8]*src[3];
	dst[5] -= tmp[1]*src[0] + tmp[6]*src[2] + tmp[9]*src[3];
	dst[6]  = tmp[3]*src[0] + tmp[6]*src[1] + tmp[11]*src[3];
	dst[6] -= tmp[2]*src[0] + tmp[7]*src[1] + tmp[10]*src[3];
	dst[7]  = tmp[4]*src[0] + tmp[9]*src[1] + tmp[10]*src[2];
	dst[7] -= tmp[5]*src[0] + tmp[8]*src[1] + tmp[11]*src[2];

	// We don't need the variables below to get the determinant, so calculate and get out here, iff we don't want the inverse matrix
	if(!out)
	{
		det=src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3];
		det = 1/det;
		return;
	}

	/* calculate pairs for second 8 elements (cofactors) */
	tmp[0]  = src[2]*src[7];
	tmp[1]  = src[3]*src[6];
	tmp[2]  = src[1]*src[7];
	tmp[3]  = src[3]*src[5];
	tmp[4]  = src[1]*src[6];
	tmp[5]  = src[2]*src[5];
	tmp[6]  = src[0]*src[7];
	tmp[7]  = src[3]*src[4];
	tmp[8]  = src[0]*src[6];
	tmp[9]  = src[2]*src[4];
	tmp[10] = src[0]*src[5];
	tmp[11] = src[1]*src[4];

	/* calculate second 8 elements (cofactors) */
	dst[8]  = tmp[0]*src[13] + tmp[3]*src[14] + tmp[4]*src[15];
	dst[8] -= tmp[1]*src[13] + tmp[2]*src[14] + tmp[5]*src[15];
	dst[9]  = tmp[1]*src[12] + tmp[6]*src[14] + tmp[9]*src[15];
	dst[9] -= tmp[0]*src[12] + tmp[7]*src[14] + tmp[8]*src[15];
	dst[10] = tmp[2]*src[12] + tmp[7]*src[13] + tmp[10]*src[15];
	dst[10]-= tmp[3]*src[12] + tmp[6]*src[13] + tmp[11]*src[15];
	dst[11] = tmp[5]*src[12] + tmp[8]*src[13] + tmp[11]*src[14];
	dst[11]-= tmp[4]*src[12] + tmp[9]*src[13] + tmp[10]*src[14];
	dst[12] = tmp[2]*src[10] + tmp[5]*src[11] + tmp[1]*src[9];
	dst[12]-= tmp[4]*src[11] + tmp[0]*src[9] + tmp[3]*src[10];
	dst[13] = tmp[8]*src[11] + tmp[0]*src[8] + tmp[7]*src[10];
	dst[13]-= tmp[6]*src[10] + tmp[9]*src[11] + tmp[1]*src[8];
	dst[14] = tmp[6]*src[9] + tmp[11]*src[11] + tmp[3]*src[8];
	dst[14]-= tmp[10]*src[11] + tmp[2]*src[8] + tmp[7]*src[9];
	dst[15] = tmp[10]*src[10] + tmp[4]*src[8] + tmp[9]*src[9];
	dst[15]-= tmp[8]*src[9] + tmp[11]*src[10] + tmp[5]*src[8];

	/* calculate determinant */
	det=src[0]*dst[0]+src[1]*dst[1]+src[2]*dst[2]+src[3]*dst[3];

	/* calculate matrix inverse */
	det = 1/det;
	for (u32 j = 0; j < 16; j++)
		dst[j] *= det;
};

void Mat44::Cramers_Inverse_SSE(const Mat44 *out, f32 &detv) const
{
	f32 *src = (f32*)&mat;

	__m128 minor0=_mm_setzero_ps(), minor1=_mm_setzero_ps(), minor2=_mm_setzero_ps(), minor3=_mm_setzero_ps();
	__m128 row0=_mm_setzero_ps(),   row1=_mm_setzero_ps(),   row2=_mm_setzero_ps(),   row3=_mm_setzero_ps();
	__m128 det=_mm_setzero_ps(),    tmp1=_mm_setzero_ps();

	tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(src)), (__m64*)(src+ 4));
	row1 = _mm_loadh_pi(_mm_loadl_pi(row1, (__m64*)(src+8)), (__m64*)(src+12));
	row0 = _mm_shuffle_ps(tmp1, row1, 0x88);
	row1 = _mm_shuffle_ps(row1, tmp1, 0xDD);
	tmp1 = _mm_loadh_pi(_mm_loadl_pi(tmp1, (__m64*)(src+ 2)), (__m64*)(src+ 6));
	row3 = _mm_loadh_pi(_mm_loadl_pi(row3, (__m64*)(src+10)), (__m64*)(src+14));
	row2 = _mm_shuffle_ps(tmp1, row3, 0x88);
	row3 = _mm_shuffle_ps(row3, tmp1, 0xDD);
	
	tmp1 = _mm_mul_ps(row2, row3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	minor0 = _mm_mul_ps(row1, tmp1);
	minor1 = _mm_mul_ps(row0, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	minor0 = _mm_sub_ps(_mm_mul_ps(row1, tmp1), minor0);
	minor1 = _mm_sub_ps(_mm_mul_ps(row0, tmp1), minor1);
	minor1 = _mm_shuffle_ps(minor1, minor1, 0x4E);
	
	tmp1 = _mm_mul_ps(row1, row2);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	minor0 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor0);
	minor3 = _mm_mul_ps(row0, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	minor0 = _mm_sub_ps(minor0, _mm_mul_ps(row3, tmp1));
	minor3 = _mm_sub_ps(_mm_mul_ps(row0, tmp1), minor3);
	minor3 = _mm_shuffle_ps(minor3, minor3, 0x4E);
	
	tmp1 = _mm_mul_ps(_mm_shuffle_ps(row1, row1, 0x4E), row3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	row2 = _mm_shuffle_ps(row2, row2, 0x4E);
	minor0 = _mm_add_ps(_mm_mul_ps(row2, tmp1), minor0);
	minor2 = _mm_mul_ps(row0, tmp1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	minor0 = _mm_sub_ps(minor0, _mm_mul_ps(row2, tmp1));
	minor2 = _mm_sub_ps(_mm_mul_ps(row0, tmp1), minor2);
	minor2 = _mm_shuffle_ps(minor2, minor2, 0x4E);
	
	tmp1 = _mm_mul_ps(row0, row1);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	minor2 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor2);
	minor3 = _mm_sub_ps(_mm_mul_ps(row2, tmp1), minor3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	minor2 = _mm_sub_ps(_mm_mul_ps(row3, tmp1), minor2);
	minor3 = _mm_sub_ps(minor3, _mm_mul_ps(row2, tmp1));
	
	tmp1 = _mm_mul_ps(row0, row3);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	minor1 = _mm_sub_ps(minor1, _mm_mul_ps(row2, tmp1));
	minor2 = _mm_add_ps(_mm_mul_ps(row1, tmp1), minor2);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	minor1 = _mm_add_ps(_mm_mul_ps(row2, tmp1), minor1);
	minor2 = _mm_sub_ps(minor2, _mm_mul_ps(row1, tmp1));
	
	tmp1 = _mm_mul_ps(row0, row2);
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0xB1);
	minor1 = _mm_add_ps(_mm_mul_ps(row3, tmp1), minor1);
	minor3 = _mm_sub_ps(minor3, _mm_mul_ps(row1, tmp1));
	tmp1 = _mm_shuffle_ps(tmp1, tmp1, 0x4E);
	minor1 = _mm_sub_ps(minor1, _mm_mul_ps(row3, tmp1));
	minor3 = _mm_add_ps(_mm_mul_ps(row1, tmp1), minor3);
	
	det = _mm_mul_ps(row0, minor0);
	det = _mm_add_ps(_mm_shuffle_ps(det, det, 0x4E), det);
	det = _mm_add_ss(_mm_shuffle_ps(det, det, 0xB1), det);
	tmp1 = _mm_rcp_ss(det);
	det = _mm_sub_ss(_mm_add_ss(tmp1, tmp1), _mm_mul_ss(det, _mm_mul_ss(tmp1, tmp1)));
	det = _mm_shuffle_ps(det, det, 0x00);
	
	_mm_store_ss(&detv, det);

	Mat44 t;
	if(out)
	{
		src = (f32*)out->mat;
	}
	else
	{
		src = t.mat;
	}

	minor0 = _mm_mul_ps(det, minor0);
	_mm_storel_pi((__m64*)(src), minor0);
	_mm_storeh_pi((__m64*)(src+2), minor0);
	
	minor1 = _mm_mul_ps(det, minor1);
	_mm_storel_pi((__m64*)(src+4), minor1);
	_mm_storeh_pi((__m64*)(src+6), minor1);
	
	minor2 = _mm_mul_ps(det, minor2);
	_mm_storel_pi((__m64*)(src+ 8), minor2);
	_mm_storeh_pi((__m64*)(src+10), minor2);
	
	minor3 = _mm_mul_ps(det, minor3);
	_mm_storel_pi((__m64*)(src+12), minor3);
	_mm_storeh_pi((__m64*)(src+14), minor3);
};

Mat44 Mat44::Inverse() const
{
	Mat44 ret; f32 det;
	//Cramers_Inverse(&ret,det);
	Cramers_Inverse_SSE(&ret, det);
	return ret;
};

f32 Mat44::Determinant() const
{
	f32 det;
	//Cramers_Inverse(0,det);
	Cramers_Inverse_SSE(0,det);
	return det;
};

Mat44 Mat44::Transpose() const
{
	__m128 mat1rows[] = { _mm_load_ps(mat), _mm_load_ps(mat+4), _mm_load_ps(mat+8), _mm_load_ps(mat+12) };
	_MM_TRANSPOSE4_PS(mat1rows[0], mat1rows[1], mat1rows[2], mat1rows[3]);

	Mat44 res;
	_mm_store_ps(res.mat   , mat1rows[0]);
	_mm_store_ps(res.mat+4 , mat1rows[1]);
	_mm_store_ps(res.mat+8 , mat1rows[2]);
	_mm_store_ps(res.mat+12, mat1rows[3]);
	return res;
};

void Mat44::write(std::ostream &out)
{
	out <<
		mat[0] << "," << mat[1] << "," << mat[2] << "," << mat[3] << "," <<
		mat[4] << "," << mat[5] << "," << mat[6] << "," << mat[7] << "," <<
		mat[8] << "," << mat[9] << "," << mat[10] << "," << mat[11] << "," <<
		mat[12] << "," << mat[13] << "," << mat[14] << "," << mat[15];
};

std::ostream& operator<<(std::ostream &out, Mat44 &m)
{
	m.write(out);
	return out;
};

Mat44 Mat44::BuildRotationMatrix(f32 angle_in_degrees, f32 x, f32 y, f32 z)
{
	float3 fv(x,y,z);
	fv.normalize();
	
	x = fv.x();
	y = fv.y();
	z = fv.z();

	f32 angle = DEGTORAD(angle_in_degrees);

	f32 c = cos(angle);
	f32 s = sin(angle);

	return Mat44
		(
		x*x*(1-c)+c,   // m11
		x*y*(1-c)-z*s, // m12
		x*z*(1-c)+y*s, // m13
		0,			   // m14

		y*x*(1-c)+z*s, // m21
		y*y*(1-c)+c,   // m22
		y*z*(1-c)-x*s, // m23
		0,			   // m24

		x*z*(1-c)-y*s, // m31 
		y*z*(1-c)+x*s, // m32
		z*z*(1-c)+c,   // m33
		0,			   // m34

		0, 0, 0, 1     // m41, m42, m43, m44
		);
};

Mat44 Mat44::BuildScaleMatrix(f32 xscale, f32 yscale, f32 zscale)
{
	return Mat44(
		xscale,  0,       0,       0,
		0,       yscale,  0,       0,
		0,       0,       zscale,  0,
		0,       0,       0,       1);
};

void Mat44::BuildScaleMatrix(f32 xscale, f32 yscale, f32 zscale, Mat44 &out)
{
	out.mat[m11] = xscale;
	out.mat[m22] = yscale;
	out.mat[m33] = zscale;
};

const float3 Mat44::GetTranslationFromMatrix() const
{
	return float3( mat[12], mat[13], mat[14] );
};