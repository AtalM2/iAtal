#include "utils_test.h"
#include "tmx/utils.h"

#include <vector>
#include <algorithm>

void
UtilsTest::stringExplodeTest()
{
    std::vector<string> ret;

    ret = Utils::stringExplode(";;;this;is;a;test;;;", ";");
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "this") != ret.end());
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "is") != ret.end());
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "a") != ret.end());
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "test") != ret.end());
    CPPUNIT_ASSERT(ret.size() == 4);

    ret = Utils::stringExplode(";this;;", ";");
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "this") != ret.end());
    CPPUNIT_ASSERT(ret.size() == 1);

    ret = Utils::stringExplode(";;;", ";");
    CPPUNIT_ASSERT(ret.empty());

    ret = Utils::stringExplode("", ";");
    CPPUNIT_ASSERT(ret.empty());

    ret = Utils::stringExplode("this is a test", ";");
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "this is a test") != ret.end());
    CPPUNIT_ASSERT(ret.size() == 1);

}

void
UtilsTest::intToStringTest()
{
    CPPUNIT_ASSERT(Utils::intToString(0) == "0");
    CPPUNIT_ASSERT(Utils::intToString(10) == "10");
    CPPUNIT_ASSERT(Utils::intToString(-42) == "-42");
}

void
UtilsTest::stringToIntTest()
{
    CPPUNIT_ASSERT(Utils::stringToInt("0") == 0);
    CPPUNIT_ASSERT(Utils::stringToInt("12") == 12);
    CPPUNIT_ASSERT(Utils::stringToInt("-42") == -42);
}

void
UtilsTest::stringToIntTestException1()
{
    Utils::stringToInt("pwet");
}

void
UtilsTest::stringToIntTestException2()
{
    Utils::stringToInt("12.0");
}

void
UtilsTest::stringToIntTestException3()
{
    Utils::stringToInt("--12");
}

void
UtilsTest::stringToIntTestException4()
{
    Utils::stringToInt("-1)");
}

void
UtilsTest::stringToIntTestException5()
{
    Utils::stringToInt("a0");
}









