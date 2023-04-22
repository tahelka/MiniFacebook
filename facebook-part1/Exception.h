#ifndef __EXCEPTION_H
#define __EXCEPTION_H
#include <iostream>

// Base Exception class, all other exception will derive from it
class Exception
{
public:
    virtual ~Exception() = default;
    // Virtual Methods:
    // Returns the exception message
    virtual std::string what() const = 0;
};

#endif