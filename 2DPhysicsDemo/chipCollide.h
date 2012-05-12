#pragma once

#include "SimBody.h"
#include "Mat22.h"
#include "Arbiter.h"

class Collide
{
private:
	Collide(){};
public:
	static Arbiter CollidePoly2Poly(SimBody *poly1, SimBody *poly2);
};