#ifndef __CONTENT_EXCEPTION_H
#define __CONTENT_EXCEPTION_H
#include <string>
#include "Exception.h"

class ContentException : public Exception
{

public:
	ContentException() {};
	// Methods:
	// Returns the error message
	std::string what () const override;
};

#endif