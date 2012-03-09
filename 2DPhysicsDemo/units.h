#pragma once

#include "ctypes.h"

// This file defines the units the application will use. Using these variables, we can maintain consistency
// in object sizes. For example, 3 meters is equal to 3*METER = meters(3)

const f64 METER = 0.1;
inline f64 meters(double in) { return in * METER; };