#include "python_hello.h"
#include <string>

int main()
{

    Py_Initialize();

    try {
        boost::python::object main_module = boost::python::import("__main__");
        boost::python::object main_namespace = main_module.attr("__dict__");
        exec_file("cpp_hello_python.py",
                  main_namespace);

        std::shared_ptr<World> world(new World());
        world->set("This is SPARTA!");

        main_namespace["world"] = boost::python::ptr(world.get());

        exec("print(world.greet())\n"
             "world.set('No this is Patrick!')\n",
             main_namespace);

        std::cout << world->greet() << std::endl;
        
    } catch (boost::python::error_already_set) {
        PyErr_Print();
    }

    Py_Finalize();
    return 0;
}
