// -*- c-basic-offset: 2; -*-

#include "utils.h"
#include <sstream>

namespace Utils {
  vector<string> stringExplode(string str, string separator) {
    size_t found;
    vector<string> results;
    found = str.find_first_of(separator);
    while (found < str.length() && found < string::npos) {
      if (found > 0) {
        results.push_back(str.substr(0, found));
      }
      str = str.substr(found + 1);
      found = str.find_first_of(separator);
    }
    if (str.length() > 0) {
      results.push_back(str);
    }
    return results;
  }

  string intToString(int i) {
    ostringstream oss;
    oss << i;
    return oss.str();
  }

  int stringToInt(string s) {
    std::istringstream iss(s);
    int number;
    iss >> number;
    return number;
  }
}
