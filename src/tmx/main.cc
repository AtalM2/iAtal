// -*- c-basic-offset: 2; -*-

#include <iostream>

#include "map-loader.h"

int
main() {
  try
    {
      MapLoader::loadTmx("src/tmx/resources/map.tmx");
    }
  catch(std::string s)
    {
      std::cout << s << std::endl;
    }
  return 0;
}
