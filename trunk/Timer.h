//////////////////////////////////////////////////////////////////////
/* Timer class because everything I've seen about the Timers in AGK suck
/  by Steele Game Studios
*///////////////////////////////////////////////////////////////////

#pragma once
#include "Text.h"
#include <time.h>

class Timer
{
public:
	Timer(void);
	~Timer(void);

	Text getCurrentDate(void);
	Text getCurrent(void);
	unsigned short getDayOfWeek(void);
	int getDaysFromUnix(int unixTimeValue);
	unsigned int getElapsed(void);
	int getHoursFromUnix(int unixTimeValue);
	bool getLeapYear(unsigned int year);
	int getMinutesFromUnix(int unixTimeValue);
	int getMonthFromUnix(int unixTimeValue);
	bool getRinging(void);
	int getSecondsFromUnix(int unixTimeValue);
	int getUnixFromDate(unsigned short year, unsigned short month, unsigned short days, unsigned short hours, unsigned short minutes, unsigned short seconds);
	int getYearFromUnix(int unixTimeValue);

	void reset(void);
	void resetStopWatch(void);
	
	void stopWatch(unsigned int stopValue);
	
	void update(void);

private:
	time_t startTime;
	unsigned int stopTime;
	unsigned int stopAmount;
	bool ringing;
};

