#pragma once

#include "Vector.h"
#include "Matrix.h"
#include <vector>
using namespace std;

// Collision body (position, rotation, vertices)
class CBODY
{
public:
	float rotation; // rotation in degrees
	Vector position;
	vector<Vector> vertices;

	float r, g, b;

	CBODY(void);
	~CBODY(void);

	void Draw();
};