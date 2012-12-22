// -*- c-basic-offset: 2; -*-

//  Copyright (C) 2012

// This file is part of iAtal.

// iAtal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// iAtal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with iAtal.  If not, see <http://www.gnu.org/licenses/>.

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
