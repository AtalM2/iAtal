// -*- c-basic-offset: 2; -*-

#include "utils.h"
#include "exceptions/tmx/utils-exceptions.h"
#include <iostream>

namespace Utils {

  string intToString(int i) {
    ostringstream oss;
    oss << i;
    return oss.str();
  }

}
