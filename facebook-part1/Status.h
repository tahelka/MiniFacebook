#ifndef __STATUS_H
#define __STATUS_H

#include <iostream>
#include <string>

#include "Date.h"

#pragma warning (disable: 4996)

const int EMPTY = 0;
const int EQUAL = 0; 
const int SKIP = 6; 

class Status
{
	std::string content;
	Time time; 
	Date date;


public:

	Status(const std::string& content);
	Status(std::istream& in) : time(in), date(in)
	{
		in >> *this;
	}
	virtual ~Status() {};

	// Getters:
	const std::string& getTextStatus()	const;
	const Date& getDate()				const;
	const Time& getTime()				const;
	
	// Setters:
	void setContent(const std::string& content);
	void setDate(const Date& date);
	void setTime(const Time& time);

	// Methods
	virtual const std::string getType() { return "Status"; };

	// Operators overloading
	const bool& operator==(const Status& other) const; // return true if 2 statuses are identical
	const bool& operator!=(const Status& other) const; // return true if 2 statuses are not identical

	// Files support methods
	virtual void toOs(std::ostream& os) const {}
	virtual void fromOs(std::istream& in) {}

	friend std::ostream& operator<<(std::ostream& os, const Status& status)
	{
		os << typeid(status).name() + SKIP << std::endl; // status type
		os << status.time << std::endl; // Time of status
		os << status.date << std::endl; // Date of status
		os << status.content << std::endl; // Text of status
		status.toOs(os); // other fields of video / picture
		return os;
	}

	friend std::istream& operator>>(std::istream& in, Status& status)
	{
		std::getline(in, status.content);
		return in;
	}
};

#endif
