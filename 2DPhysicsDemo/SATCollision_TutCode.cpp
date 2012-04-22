#pragma once

#include "SATCollision.h"

void GetInterval(const Vector *axVertices, int iNumVertices, const Vector& xAxis, float& min, float& max)
{
	min = max = (axVertices[0] * xAxis);

	for(int i = 1; i < iNumVertices; i ++)
	{
		float d = (axVertices[i] * xAxis);
		if (d < min) min = d; else if (d > max) max = d;
	}
}

bool IntervalIntersect(const Vector* A, int Anum,
					   const Vector* B, int Bnum,
					   const Vector& xAxis, 
					   const Vector& xOffset, const Matrix& xOrient,
					   float& taxis, float tmax)
{
	float min0, max0;
	float min1, max1;
	GetInterval(A, Anum, xAxis ^ xOrient, min0, max0);
	GetInterval(B, Bnum, xAxis, min1, max1);

	float h = xOffset * xAxis;
	min0 += h;
	max0 += h;

	float d0 = min0 - max1; // if overlapped, do < 0
	float d1 = min1 - max0; // if overlapped, d1 > 0

	// separated, test dynamic intervals
	if (d0 > 0.0f || d1 > 0.0f) 
	{
		return false;
	}
	else
	{
		// overlap. get the interval, as a the smallest of |d0| and |d1|
		// return negative number to mark it as an overlap
		taxis = (d0 > d1)? d0 : d1;
		return true;
	}
}

bool FindMTD(Vector* xAxis, float* taxis, int iNumAxes, Vector& N, float& t)
{
	int mini = -1;
	for(int i = 0; i < iNumAxes; i ++)
	{
		float n = xAxis[i].Normalise();
		taxis[i] /= n;

		if (taxis[i] > t || mini == -1)
		{
			mini = i;
			t = taxis[i];
			N = xAxis[i];
		}
	}

	return (mini != -1);
};

bool Intersect_TutCode(CBODY &a, CBODY &b)
{
	const Matrix OA = Matrix(DegreesToRadians(a.rotation));
	const Matrix OB = Matrix(DegreesToRadians(b.rotation));

	Matrix xOrient = OA ^ OB;
	Vector xOffset = (b.position - a.position) ^ OB;

	Vector xAxis[64];
	float  taxis[64];
	int    iNumAxes=0;

	int Anum = a.vertices.size();
	int Bnum = b.vertices.size();
	Vector *A = &a.vertices[0];
	Vector *B = &b.vertices[0];
	float t = -100000000;

	for(int j = Anum-1, i = 0; i < Anum; j = i, i ++)
	{
		Vector E0 = A[j];
		Vector E1 = A[i];
		Vector E  = E1 - E0;
		xAxis[iNumAxes] = Vector(-E.y, E.x) * xOrient;

		if (!IntervalIntersect(	A, Anum, 
								B, Bnum, 
								xAxis[iNumAxes], 
								xOffset, xOrient,
								taxis[iNumAxes], t))
		{
			return false;
		}

		iNumAxes++;
	}

	for(int j = Bnum-1, i = 0; i < Bnum; j = i, i ++)
	{
		Vector E0 = B[j];
		Vector E1 = B[i];
		Vector E  = E1 - E0;
		xAxis[iNumAxes] = Vector(-E.y, E.x);

		if (!IntervalIntersect(	A, Anum, 
								B, Bnum, 
								xAxis[iNumAxes], 
								xOffset, xOrient,
								taxis[iNumAxes], t))
		{
			return false;
		}

		iNumAxes++;
	}

	Vector N;
	t = -100000000;
	if (!FindMTD(xAxis, taxis, iNumAxes, N, t))
		return false;

	return true;
};