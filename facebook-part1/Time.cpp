#include "Time.h"

using namespace std;


Time::Time(int hour, int minutes)
{
	setHour(hour);
	setMinutes(minutes);
}

Time::Time()
{
	time_t now = time(0); 
    tm* ltm = localtime(&now); // changing 'now' to local time and getting a pointer to local time.
	this->hour = ltm->tm_hour;
	this->minutes = ltm->tm_min;
}


// getters:
int Time::getHour()		const
{
	return hour;
}

int Time::getMinutes()	const
{
	return minutes;
}

// setters:

void Time::setHour(int hour)
{
	this->hour = hour;
}
void Time::setMinutes(int minutes)
{
	this->minutes = minutes;
}

// methods:

void Time::show()		const
{
	cout << (hour < (int)Digits::TWO ? "0" : "") << hour << ":" << (minutes < (int)Digits::TWO ? "0" : "") << minutes;
}