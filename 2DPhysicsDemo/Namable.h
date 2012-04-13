#pragma once

class Namable
{
private:
	c8 *name;
public:
	Namable() : name(0) {};
	Namable(const c8 *c) : name((c8*)c) {};
	~Namable() {};

	inline void SetName(const c8 *m) { name = (c8*)m; };
	inline const c8* GetName() { return name; };
};