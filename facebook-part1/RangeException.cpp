#include "RangeException.h"

// Methods:

std::string RangeException::what() const
{
	return "RangeException: Value is not in range";
}
