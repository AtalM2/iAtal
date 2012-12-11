#include "tmx/map-loader.h"
#include <iostream>

int
main() {
  try {
  MapLoader::loadTmx("src/tmx/resources/map.tmx");
  } catch(std::string s) {
    std::cout << s << std::endl;
  }
  return 0;
}
