/*
 * Python.h must be included before any standard headers.
 * http://docs.python.org/2/c-api/intro.html#includes
 */
#include <Python.h>

#include <boost/python.hpp>

int main()
{

    Py_Initialize();

    try {
        boost::python::object main_module = boost::python::import("__main__");
        boost::python::object main_namespace = main_module.attr("__dict__");

        boost::python::object ignored =
            exec_file("cpp_hello.py", main_namespace, main_namespace);
    } catch (boost::python::error_already_set) {
        PyErr_Print();
    }

    Py_Finalize();
    return 0;
}
