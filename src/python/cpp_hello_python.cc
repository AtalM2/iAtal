#include "Python.h"
#include <boost/python.hpp>

#include <string>

int main()
{

    Py_Initialize();

    try {
        boost::python::object main_module = boost::python::import("__main__");
        boost::python::object main_namespace = main_module.attr("__dict__");
        exec_file("cpp_hello_python.py",
                  main_namespace);
    } catch (boost::python::error_already_set) {
        PyErr_Print();
    }

    Py_Finalize();
    return 0;
}
