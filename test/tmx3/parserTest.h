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

#ifndef _PARSERTEST_H_
#define _PARSERTEST_H_

#include <cppunit/extensions/HelperMacros.h>
#include "exceptions/tmx/utils-exceptions.h"

class ParserTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(ParserTest);

    CPPUNIT_TEST(parseCsvTest);
    
    CPPUNIT_TEST_SUITE_END();

public:

    void parseCsvTest();
};

#endif /* _PARSERTEST_H_ */
