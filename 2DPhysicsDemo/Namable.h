#pragma once

class Namable
{
private:
	char *name;
public:
	Namable() : name(0) {};
	Namable(const char *c) : name((char*)c) {};
	~Namable() {};

	inline void SetName(const char *m) { name = (char*)m; };
	inline const char* GetName() { return name; };
};