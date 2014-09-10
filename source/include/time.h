#ifndef TIME
#define TIME 

#include <time.h>
#include <sys/time.h>

namespace Time
{

	static const long NANOSECONDS_PER_SECOND = 1000000000L;

	static double GetTime()
	{
		timespec ts;
		clock_gettime(CLOCK_REALTIME, &ts);
		return (double)(((long) ts.tv_sec * NANOSECONDS_PER_SECOND) + ts.tv_nsec)/((double)(NANOSECONDS_PER_SECOND));
	}
};

#endif

