#include "Date.h"
using namespace std;

Date::Date(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}

Date::Date()
{
	time_t now = time(0); // getting initial year (1900).
	tm* ltm = localtime(&now); // changing 'now' to local time and getting a pointer to local time.
	setDay(ltm->tm_mday);
	setMonth(ltm->tm_mon + 1);
	setYear(ltm->tm_year + 1900);
}

Date::Date(std::istream& in)
{
	in >> *this;
}

// Setters:

void Date::setDay(int day)
{
	if (day > 31 || day < 1)
	{
		throw DateException();
	}

	this->day = day;

}

void Date::setMonth(int month)
{
	if (month > 12 || month < 1)
	{
		throw DateException();
	}
	this->month = month;
}

void Date::setYear(int year)
{
	time_t now = time(0); // getting initial year (1900).
	tm* ltm = localtime(&now); // changing 'now' to local time and getting a pointer to local time.
	
	int currYear = ltm->tm_year + 1900;

	if (year > currYear || year < 1900)
	{
		throw DateException();
	}

	this->year = year;
}


// Getters:

int Date::getDay()			const
{
	return day;
}

int Date::getMonth()		const
{
	return month;
}

int Date::getYear()			const
{
	return year;
}

// Methods: 
void Date::show()			const
{
	cout << (day < (int)Digits::TWO ? "0" : "") << day << "/" << (month < (int)Digits::TWO ? "0" : "") << month << "/" << year;
}