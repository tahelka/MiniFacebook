#ifndef __TIME_H
#define __TIME_H

#include <iostream>
#include <string>
#include <ctime>

#pragma warning (disable: 4996)

enum class Digits { TWO = 10 };

class Time
{
	int hour;
	int minutes;

public:
	Time(int hour, int minutes);
	Time();
	Time(std::istream& in)
	{
		in >> *this;
	}

	// Setters:
	void setHour(int hour);
	void setMinutes(int minutes);

	// Getters:
	int getHour()			const;
	int getMinutes()		const;

	// Methods:

	void show()				const;

	// Files support methods
	friend std::ostream& operator<<(std::ostream& os, const Time& time)
	{
		os << time.hour << " " << time.minutes;
		return os;
	}

	friend std::istream& operator>>(std::istream& in, Time& time)
	{
		std::string tmp;
		in >> time.hour;
		in >> time.minutes;
		std::getline(in, tmp); // for enter
		return in;
	}
};



#endif