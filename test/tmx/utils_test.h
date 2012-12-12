#ifndef _UTILS_TEST_H_
#define _UTILS_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class UtilsTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(UtilsTest);

    CPPUNIT_TEST(stringExplodeTest);

    CPPUNIT_TEST_SUITE_END();
    
public:
    void stringExplodeTest();
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(UtilsTest);

#endif /* _UTILS_TEST_H_ */

