#pragma once

#include "Vector.h"
#include "Matrix.h"
#include <vector>
using namespace std;

struct col
{
public:
	float r,g,b;
	col(float _r, float _g, float _b)
	{
		r = _r;
		g = _g;
		b = _b;
	};
	col() : r(1), g(1), b(1) {};
	~col(){};

	void set(float _r, float _g, float _b)
	{
		r = _r;
		g = _g;
		b = _b;
	}
};
class CBODY
{
public:
	std::vector<Vector> vertices;
	Vector pos;
	float angle;
	Matrix orientationMatrix;

	col bodyColor;

	CBODY(void) {}
	~CBODY(void) {}

	void Render();
};

bool Collide(CBODY &a, CBODY &b, Vector &N, float &t);

bool FindContacts2(
	const Vector* A, int Anum, const Vector& PA, const Vector& VA, const Matrix& OA,
	const Vector* B, int Bnum, const Vector& PB, const Vector& VB, const Matrix& OB,
	const Vector& N, float t,
	Vector* CA, 
	Vector* CB, 
	int& Cnum);