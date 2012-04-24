#include "CBODY.h"
#include <GXBase.h>

void CBODY::Render()
{
	glPushMatrix();
	
	glTranslatef(pos.x, pos.y, 0);
	glRotatef(RadiansToDegrees(angle),0,0,-1);

	glColor3f(bodyColor.r, bodyColor.g, bodyColor.b);

	glBegin(GL_LINE_LOOP);
	for(int i=0;i<vertices.size();++i)
	{
		glVertex2f(vertices[i].x, vertices[i].y);
	}
	glEnd();

	glColor3f(1,1,1);
	glPopMatrix();
};

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
	taxis = (d0 > d1)? d0 : d1;
	return true;
};

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

bool Collide(CBODY &a, CBODY &b, Vector &N, float &t)
{
	Matrix &OA = a.orientationMatrix;
	Matrix &OB = b.orientationMatrix;

	Vector *A = &a.vertices[0];
	Vector *B = &b.vertices[0];
	int Anum = a.vertices.size();
	int Bnum = b.vertices.size();

	Matrix xOrient = OA ^ OB;
	Vector xOffset = (a.pos - b.pos) ^ OB;

	Vector xAxis[64]; // note : a maximum of 32 vertices per poly is supported
	float  taxis[64];
	int    iNumAxes=0;

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

	if (!FindMTD(xAxis, taxis, iNumAxes, N, t))
	{
		return false;
	}

	// make sure the polygons gets pushed away from each other.
	if (N * xOffset < 0.0000001f)
		N = -N;

	N *= OB;

	return true;
};

bool ProjectPointOnSegment(const Vector& V, const Vector& A, const Vector& B, Vector& W, float* pt=NULL)
{
	Vector AV = V - A;
	Vector AB = B - A;
	float t = (AV * AB) / (AB * AB);

	if (t < 0.0f) t = 0.0f; else if (t > 1.0f) t = 1.0f;

	if (pt)	*pt = t;

	W = A + t * AB;

	return true;
}

Vector Transform(const Vector& Vertex, const Vector& P, const Vector& V, const Matrix& xOrient, float t)
{
	Vector T = P + (Vertex * xOrient);

	/*if(t > 0.0f)
	{
		T += V * t;
	}*/

	return T;
}

int FindSupportPoints(const Vector& N, float t, const Vector* A, int Anum, const Vector& PA, const Vector& VA, const Matrix& OA, Vector* S)
{
	Vector Norm = N ^ OA;

	float d[32];
	float dmin;
	dmin = d[0] = A[0] * Norm;
	
	for(int i = 1; i < Anum; i ++)
	{
		d[i] = A[i] * Norm;

		if (d[i] < dmin)
		{
			dmin = d[i];
		}
	}

	int Snum = 0;
	const float threshold = 1.0E-3f;
	float s[2];
	float sign = false;

	Vector Perp(-Norm.y, Norm.x);

	for(int i = 0; i < Anum; i ++)
	{
		if (d[i] < dmin + threshold)
		{
			Vector Contact = Transform(A[i], PA, VA, OA, t);

			float c = Contact * Perp;

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
				Vector& Min = (sign)? S[0] : S[1];
				Vector& Max = (sign)? S[1] : S[0];

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

bool ConvertSupportPointsToContacts(const Vector& N,
									Vector* S0, int S0num, 
									Vector* S1, int S1num,
									Vector* C0,
									Vector* C1,
									int& Cnum)
{
	Cnum = 0;

	if (S0num == 0 || S1num == 0)
		return false;

	if (S0num == 1 && S1num == 1)
	{
		C0[Cnum] = S0[0];
		C1[Cnum] = S1[0];
		Cnum++;
		return true;
	}

	Vector xPerp(-N.y, N.x);

	float min0 = S0[0] * xPerp;
	float max0 = min0;
	float min1 =  S1[0] * xPerp;
	float max1 = min1;

	if (S0num == 2)
	{
		max0 = S0[1] * xPerp;

		if (max0 < min0) 
		{ 
			swapf(min0, max0);

			Vector T = S0[0];
			S0[0] = S0[1];
			S0[1] = T;
		}
	}

	if (S1num == 2)
	{
		max1 = S1[1] * xPerp;

		if (max1 < min1) 
		{ 
			swapf(min1, max1);

			Vector T = S1[0];
			S1[0] = S1[1];
			S1[1] = T;
		}
	}

	if (min0 > max1 || min1 > max0)
		return false;

	if (min0 > min1)
	{
		Vector Pseg;
		if (ProjectPointOnSegment(S0[0], S1[0], S1[1], Pseg))
		{
			C0[Cnum] = S0[0];
			C1[Cnum] = Pseg;
			Cnum++;
		}
	}
	else
	{
		Vector Pseg;
		if (ProjectPointOnSegment(S1[0], S0[0], S0[1], Pseg))
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
			Vector Pseg;
			if (ProjectPointOnSegment(S0[1], S1[0], S1[1], Pseg))
			{
				C0[Cnum] = S0[1];
				C1[Cnum] = Pseg;
				Cnum++;
			}
		}
		else
		{
			Vector Pseg;
			if (ProjectPointOnSegment(S1[1], S0[0], S0[1], Pseg))
			{
				C0[Cnum] = Pseg;
				C1[Cnum] = S1[1];
				Cnum++;
			}
		}
	}
	return true;
}; // end function

bool FindContacts2(
	const Vector* A, int Anum, const Vector& PA, const Vector& VA, const Matrix& OA,
	const Vector* B, int Bnum, const Vector& PB, const Vector& VB, const Matrix& OB,
	const Vector& N, float t,
	Vector* CA, 
	Vector* CB, 
	int& Cnum)
{
	Vector S0[4];
	Vector S1[4];
	int S0num = FindSupportPoints( N, t, A, Anum, PA, VA, OA, S0);
	int S1num = FindSupportPoints(-N, t, B, Bnum, PB, VB, OB, S1);

	if (!ConvertSupportPointsToContacts(N, S0, S0num, S1, S1num, CA, CB, Cnum))
		return false;

	return true;
}