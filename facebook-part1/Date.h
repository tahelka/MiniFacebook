#ifndef __DATE_H
#define __DATE_H
#include <iostream>
#include <fstream>
#include "Time.h"
#include "DateException.h"

#pragma warning (disable: 4996)

class Date
{
private:
	int day;
	int month;
	int year;
public:
	Date(int day, int month, int year);
	Date();
	Date(std::istream& in);

	// Setters:
	void setDay(int day)		throw(DateException);
	void setMonth(int month)	throw(DateException);
	void setYear(int year)		throw(DateException);

	// Getters:
	int getDay()		const;
	int getMonth()		const;
	int getYear()		const;

	// Methods:
	void show()			const;

	// Files support methods
	friend std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		os << date.day << " " << date.month << " " << date.year;
		return os;
	}

	friend std::istream& operator>>(std::istream& in, Date& date)
	{
		std::string tmp;
		in >> date.day;
		in >> date.month;
		in >> date.year;
		std::getline(in, tmp); // for enter

		return in;
	}
};

#endif // !__DATE_H
