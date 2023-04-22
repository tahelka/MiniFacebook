#include "DateException.h"

// Methods:

std::string DateException::what() const
{
	return "DateException: Date is not valid";
}