#pragma once

#include "Mesh.h"

MeshHandle Create2DBox(f32 width, f32 height, const c8 *resourceName="2DBoxMesh");
MeshHandle CreateEquilateralTriangle(f32 length, const c8 *resourceName="EquilateralTriangleMesh");
MeshHandle CreateLine(float2 start, float2 end, const c8 *resourceName="LineMesh");

void DrawCircle(float2 &pos, f32 radius);
void DrawPoint(float2 pos, float r, float g, float b);

void DrawLine(const float2 &start, const float2 &end,
	const float r, const float g, const float b, const float lineWidth=1.0f);