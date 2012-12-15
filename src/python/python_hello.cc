#include "Python.h"
#include <boost/python.hpp>

#include "python_hello.h"

void
World::set(std::string msg)
{
    this->msg = msg;
}

const std::string
World::greet() const
{
    return this->msg;
}
