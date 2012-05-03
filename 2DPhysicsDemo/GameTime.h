#pragma once

#include "PerfTimer.h"
#include "ctypes.h"

class GameTime
{
private:
	PerfTimer pt;
	double dt;

public:
	GameTime();
	~GameTime();

	double GetDeltaTime() { return dt; };
	double Update()
	{
		dt = pt.GetDT();
		return dt;
	};
};