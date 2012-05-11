#pragma once

#include "ctypes.h"

// This file defines the units the application will use. Using these variables, we can maintain consistency
// in object sizes. For example, 3 meters is equal to 3*METER = meters(3)

const f32 METER = 1.0f;
inline f32 meters(f32 in) { return in * METER; };