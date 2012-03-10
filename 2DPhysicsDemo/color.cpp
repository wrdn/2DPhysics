#include "color.h"

Color::Color() { };

const color Color::BLACK  = color();
const color Color::WHITE  = color(1.0f);
const color Color::GREY   = color(0.5f);
const color Color::RED    = color(1.0f,0,0,1);
const color Color::GREEN  = color(0,1.0f,0,1);
const color Color::BLUE   = color(0,0,1.0f,1);
const color Color::YELLOW = color(1.0f,1.0f,0,1);
const color Color::PINK   = color(1.0f,0.75f,0.79f,1);

color Color::FromInt(const u32 i)
{
	return color
		(
		(f32)(((u32)i >> 24) & 255),
		(f32)(((u32)i >> 16) & 255),
		(f32)(((u32)i >> 8) & 255),
		(f32)(((u32)i & 255))
		);
};

u32 Color::ToInt(f32 _r, const f32 _g, const f32 _b, const f32 _a)
{
	return ((u32)_r << 24 | (u32)_g << 16 | (u32)_b << 8 | (u32)_a);
};

u32 Color::ToInt(const color &c)
{
	return ToInt(c.r(), c.g(), c.b(), c.a());
};

ColorU32::ColorU32() : color(0) { };

void ColorU32::SetColor(const u32 i) { color = i; };

void ColorU32::SetColor(const f32 r, const f32 g, const f32 b, const f32 a)
{
	color = Color::ToInt(r,g,b,a);
};

const u32 ColorU32::GetColor() const
{
	return color;
};

color Color::Normalize(const color &c)
{
	f32 CUT = 1.00001f;
	if(c.r() <= CUT && c.g() <= CUT && c.b() <= CUT && c.a() <= CUT)
		return c;

	const f32 mul = 1.0f / 255.0f;
	return c*mul;
};