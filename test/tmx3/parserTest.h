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
