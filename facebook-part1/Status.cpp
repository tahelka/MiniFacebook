#include "Status.h"

using namespace std;

Status::Status(const string& content)
{
	setContent(content);
}

// Setters:

void Status::setContent(const string& content)
{
	this->content = content;
}

void Status::setDate(const Date& date)
{
	this->date = date;
}

void Status::setTime(const Time& time)
{
	this->time = time;
}


// Getters:

const string& Status::getTextStatus()		const
{
	return content;
}

const Date& Status::getDate()				const
{
	return date;
}

const Time& Status::getTime()				const
{
	return time;
}

// Operators overloading

const bool& Status::operator==(const Status& other) const // return true if 2 statuses are identical
{
	if (this->getTextStatus().compare(other.getTextStatus()) == EQUAL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

const bool& Status::operator!=(const Status& other) const // return true if 2 statuses are not identical
{
	if (this->getTextStatus().compare(other.getTextStatus()) != EQUAL)
	{
		return true;
	}
	else
	{
		return false;
	}
}