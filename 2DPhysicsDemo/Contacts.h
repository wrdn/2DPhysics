#pragma once

#include "SimBody.h"
#include "SATCollision.h"

bool FindContacts(SimBody &a, SimBody &b,
	const float2 &N, f32 t, float2 *CA, float2 *CB, i32 &Cnum);