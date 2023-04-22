#ifndef __RANGE_EXCEPTION_H
#define __RANGE_EXCEPTION_H
#include <string>
#include "Exception.h"

class RangeException : public Exception
{
	int min;
	int max;

public:
	RangeException(int min, int max): min(min), max(max) {}

	// Methods:
	// This function returns the error message
    std::string what() const override;

};

#endif
