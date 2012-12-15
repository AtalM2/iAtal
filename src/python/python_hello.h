#ifndef _PYTHON_HELLO_H_
#define _PYTHON_HELLO_H_

#include <string>

class World{
public:    
    void set(std::string msg);
    const std::string greet() const;

private:
    std::string msg;
    
};

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

#endif /* _PYTHON_HELLO_H_ */
