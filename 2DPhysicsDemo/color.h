#pragma once

#include "ctypes.h"
#include "float4.h"

typedef float4 color;

// Static class to hold some colors (in Color4f r,g,b,a form)
class Color
{
private:
	Color();
public:
	static const color BLACK;
	static const color WHITE;
	static const color GREY;
	static const color RED;
	static const color GREEN;
	static const color BLUE;
	static const color YELLOW;
	static const color PINK;

	static color FromInt(const u32 i);
	static u32 ToInt(f32 _r, const f32 _g, const f32 _b, const f32 _a);
	static u32 ToInt(const color &c);

	// Maps each value in Color4f c into the range 0 to 1 (for GLSL)
	static color Normalize(const color &c);
};

class ColorU32 // color represented as int
{
private:
	u32 color;
public:
	ColorU32();

	void SetColor(const u32 i);
	void SetColor(const f32 r, const f32 g, const f32 b, const f32 a);

	const u32 GetColor() const;
};