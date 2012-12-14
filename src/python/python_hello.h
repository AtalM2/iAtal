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

#endif /* _PYTHON_HELLO_H_ */
