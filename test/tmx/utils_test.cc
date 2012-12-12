#include "utils_test.h"
#include "tmx/utils.h"

#include <vector>
#include <algorithm>

void
UtilsTest::stringExplodeTest()
{
    std::vector<string> ret;

    ret = Utils::stringExplode("this;is;a;test", ";");
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "this") != ret.end());
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "is") != ret.end());
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "a") != ret.end());
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "test") != ret.end());

    ret = Utils::stringExplode(";this;;", ";");
    CPPUNIT_ASSERT(std::find(ret.begin(), ret.end(), "this") != ret.end());

}
