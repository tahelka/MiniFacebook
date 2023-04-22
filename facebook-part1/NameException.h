#ifndef __NAME_EXCEPTION_H
#define __NAME_EXCEPTION_H
#include <string>
#include "Exception.h"

class NameException : public Exception
{
public:
	NameException() {};

	// Methods:
	// This function returns the error message.
	std::string what() const override;
	
};

#endif