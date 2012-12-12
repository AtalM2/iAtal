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
