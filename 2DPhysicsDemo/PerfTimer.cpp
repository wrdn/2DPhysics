#include "PerfTimer.h"

PerfTimer::PerfTimer(void)
{
#ifdef _WIN32
	QueryPerformanceFrequency(&frequency);
	_start.HighPart=0; _start.LowPart=0; _start.QuadPart=0; _start.u.HighPart=0; _start.u.LowPart=0;
	_end.HighPart=0; _end.LowPart=0; _end.QuadPart=0; _end.u.HighPart=0; _end.u.LowPart=0;
#endif
}

PerfTimer::~PerfTimer(void) { }

void PerfTimer::start()
{
#ifdef _WIN32
	QueryPerformanceCounter(&_start);
#else
	clock_gettime(CLOCK_REALTIME,&tstart);
#endif
}

void PerfTimer::end()
{
#ifdef _WIN32
	QueryPerformanceCounter(&_end);
#else
	clock_gettime(CLOCK_REALTIME,&tend);
#endif
}

double PerfTimer::time() const
{
#ifdef _WIN32
	return (_end.QuadPart - _start.QuadPart)
		/ (double)frequency.QuadPart;
#else
	timespec temp;
	if((tend.tv_nsec-tstart.tv_nsec)<0)
	{
		temp.tv_nsec = 1000000000+tend.tv_nsec-tstart.tv_nsec;
	}
	else
	{
		temp.tv_nsec = tend.tv_nsec-tstart.tv_nsec;
	}
	return (double)NANOSEC_TO_SEC(temp.tv_nsec);
#endif
}
