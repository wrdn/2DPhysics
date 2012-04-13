#pragma once

#include "Mesh.h"

MeshHandle Create2DBox(f32 width, f32 height, const c8 *resourceName="2DBoxMesh");

MeshHandle CreateEquilateralTriangle(f32 length, const c8 *resourceName="EquilateralTriangleMesh");