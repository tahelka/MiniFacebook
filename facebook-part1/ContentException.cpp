#include "ContentException.h"

std::string ContentException::what()	const
{
	return "ConentException: Content is not valid";
}