#ifndef _UTILS_TEST_H_
#define _UTILS_TEST_H_

#include <cppunit/extensions/HelperMacros.h>
#include "exceptions/tmx/utils-exceptions.h"

class UtilsTest : public CppUnit::TestFixture {
    CPPUNIT_TEST_SUITE(UtilsTest);

    CPPUNIT_TEST(stringExplodeTest);
    CPPUNIT_TEST(intToStringTest);
    CPPUNIT_TEST(stringToIntTest);

    CPPUNIT_TEST_EXCEPTION(stringToIntTestException1, ConversionException);
    CPPUNIT_TEST_EXCEPTION(stringToIntTestException2, ConversionException);
    CPPUNIT_TEST_EXCEPTION(stringToIntTestException3, ConversionException);
    CPPUNIT_TEST_EXCEPTION(stringToIntTestException4, ConversionException);
    CPPUNIT_TEST_EXCEPTION(stringToIntTestException5, ConversionException);

    CPPUNIT_TEST_SUITE_END();
    
public:
    void stringExplodeTest();
    void intToStringTest();
    void stringToIntTest();
    void stringToIntTestException1();
    void stringToIntTestException2();
    void stringToIntTestException3();
    void stringToIntTestException4();
    void stringToIntTestException5();
    
};

CPPUNIT_TEST_SUITE_REGISTRATION(UtilsTest);

#endif /* _UTILS_TEST_H_ */

