#ifndef TIME
#define TIME 

#include <sys/time.h>

class Time
{
public:
	static const unsigned int SECOND = 1000000000;

	static inline long getTime()
	{
		timespec td;
		clock_gettime(CLOCK_REALTIME, &td);
		return td.tv_nsec;
	}



private:
	static timespec* time;
};


#endif

