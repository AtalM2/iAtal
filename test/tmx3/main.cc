#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

#include "tmx3/parser.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>

int main(void)
{
    CppUnit::TextUi::TestRunner runner;
    CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();
  
    runner.addTest(registry.makeTest());
  
    bool wasSuccessful = runner.run("", false);
    for(std::vector<unsigned int>::const_iterator it = ret.begin();
        it != ret.end();
        it++) {
        std::cerr << *it << std::endl;
    }
    std::cerr << ret.size() << std::endl;

    return wasSuccessful;
}
