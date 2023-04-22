#ifndef __DATE_EXCEPTION_H
#define __DATE_EXCEPTION_H
#include <string>
#include "Exception.h"

class DateException : public Exception
{
public:
	DateException() = default;
	// Methods:
	// This function returns the error message.
	std::string what() const override;
};

#endif