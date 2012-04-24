#include "Contacts.h"

bool ProjectPointOntoLineSegment(const float2 &V,
	const float2& A, const float2& B, float2& W, float* pt=0)
{
	float2 AV = V - A;
	float2 AB = B - A;
	float t = (AV.dot(AB)) / (AB.dot(AB));

	if (t < 0.0f) t = 0.0f; else if (t > 1.0f) t = 1.0f;

	if (pt)	*pt = t;

	W = A + AB.mul(t);

	return true;
};

float2 TransformVector(const float2 &vertex, const float2 &P,
	const Mat22 &xOrient)
{
	float2 T = P + (vertex * xOrient);
	return T;
};

int FindSupportPoints(const float2& N, float t, const float2* A, int Anum,
	const float2& PA, const float2& VA, const Mat22& OA, float2* S)
{
	float2 Norm = N * OA.Transpose();

	float d[32];
	float dmin;
	dmin = d[0] = A[0].dot(Norm);
	
	for(int i = 1; i < Anum; i ++)
	{
		d[i] = A[i].dot(Norm);

		if (d[i] < dmin)
		{
			dmin = d[i];
		}
	}

	int Snum = 0;
	const float threshold = 1.0E-3f;
	float s[2];
	float sign = false;

	float2 Perp(-Norm.y, Norm.x);

	for(int i = 0; i < Anum; i ++)
	{
		if (d[i] < dmin + threshold)
		{
			float2 Contact = TransformVector(A[i], PA, OA);

			float c = Contact.dot(Perp);

			if (Snum < 2)
			{
				s[Snum] = c;
				S[Snum] = Contact;
				Snum++;

				if (Snum > 1)
				{
					sign = (s[1] > s[0]);
				}
			}
			else
			{
				float&  min = (sign)? s[0] : s[1];
				float&  max = (sign)? s[1] : s[0];
				float2& Min = (sign)? S[0] : S[1];
				float2& Max = (sign)? S[1] : S[0];

				if (c < min)
				{
					min = c;
					Min = Contact;
				}
				else if (c > max)
				{
					max = c;
					Max = Contact;
				}
			}
		}
	}
	return Snum;
};

bool ConvertSupportPointsToContacts(const float2 &N,
	float2* S0, int S0num, float2* S1, int S1num,
	float2* C0, float2* C1, int& Cnum)
{
	Cnum = 0;
	if (S0num == 0 || S1num == 0)
		return false;

	// single point
	if (S0num == 1 && S1num == 1)
	{
		C0[Cnum] = S0[0];
		C1[Cnum] = S1[0];
		Cnum++;
		return true;
	}

	float2 xPerp(-N.y, N.x);

	float min0 = S0[0].dot(xPerp);
	float max0 = min0;
	float min1 =  S1[0].dot(xPerp);
	float max1 = min1;

	if (S0num == 2)
	{
		max0 = S0[1].dot(xPerp);

		if (max0 < min0) 
		{ 
			swap(min0, max0);

			float2 T = S0[0];
			S0[0] = S0[1];
			S0[1] = T;
		}
	}

	if (S1num == 2)
	{
		max1 = S1[1].dot(xPerp);

		if (max1 < min1) 
		{ 
			swap(min1, max1);

			float2 T = S1[0];
			S1[0] = S1[1];
			S1[1] = T;
		}
	}

	if (min0 > max1 || min1 > max0)
		return false;

	if (min0 > min1)
	{
		float2 Pseg;
		if (ProjectPointOntoLineSegment(S0[0], S1[0], S1[1], Pseg))
		{
			C0[Cnum] = S0[0];
			C1[Cnum] = Pseg;
			Cnum++;
		}
	}
	else
	{
		float2 Pseg;
		if (ProjectPointOntoLineSegment(S1[0], S0[0], S0[1], Pseg))
		{
			C0[Cnum] = Pseg;
			C1[Cnum] = S1[0];
			Cnum++;
		}
	}

	if (max0 != min0 && max1 != min1)
	{
		if (max0 < max1)
		{
			float2 Pseg;
			if (ProjectPointOntoLineSegment(S0[1], S1[0], S1[1], Pseg))
			{
				C0[Cnum] = S0[1];
				C1[Cnum] = Pseg;
				Cnum++;
			}
		}
		else
		{
			float2 Pseg;
			if (ProjectPointOntoLineSegment(S1[1], S0[0], S0[1], Pseg))
			{
				C0[Cnum] = Pseg;
				C1[Cnum] = S1[1];
				Cnum++;
			}
		}
	}
	return true;
};

bool FindContacts(SimBody &a, SimBody &b,
	const float2 &N, f32 t, float2 *CA, float2 *CB, i32 &Cnum)
{
	float2 S0[4], S1[4];

	const float2 *A = &a.vertices[0];
	const float2 *B = &b.vertices[0];
	const int Anum = a.vertices.size();
	const int Bnum = b.vertices.size();

	a._cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(a.rotation));
	b._cached_rotation_matrix = Mat22::RotationMatrix(DEGTORAD(b.rotation));

	int S0num = FindSupportPoints(N, 0, A, Anum, a.position, a.velocity, a._cached_rotation_matrix, S0);
	int S1num = FindSupportPoints(-N, 0, B, Bnum, b.position, b.velocity, b._cached_rotation_matrix, S1);

	return ConvertSupportPointsToContacts(N, S0, S0num, S1, S1num, CA, CB, Cnum);
};