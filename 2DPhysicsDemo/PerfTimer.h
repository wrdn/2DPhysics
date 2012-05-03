#pragma once

#include <time.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "ctypes.h"

class PerfTimer
{
private:
#ifdef _WIN32
	LARGE_INTEGER _start,_end,frequency;
	
	LARGE_INTEGER _cur;

#else
	timespec tstart, tend;
#endif
public:
	PerfTimer(void);
	~PerfTimer(void);

	void start();
	void end();
	f64 time() const; // Time between start and end in seconds

	f64 GetDT()
	{
		LARGE_INTEGER n = _cur;
		QueryPerformanceCounter(&_cur);

		return (_cur.QuadPart - n.QuadPart)
		/ (double)frequency.QuadPart;
	};
};