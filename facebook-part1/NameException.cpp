#include "NameException.h"

std::string NameException::what() const
{
    return "NameException: Name is not valid. It might be already in system, or it's not in system (in case of deletion)";
}