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

// BOOST_PYTHON_MODULE(MODULE_NAME)
// 
// MODULE_NAME must be the same has the library generated.
// e.g. python_hello.so
BOOST_PYTHON_MODULE(python_hello)
{
    using namespace boost::python;
    class_<World>("World")
        .def("greet", &World::greet)
        .def("set", &World::set);
};

