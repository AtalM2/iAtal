// -*- c-basic-offset: 2; -*-

#include <iostream>

#include <glibmm/ustring.h>

#include "map-parser.h"

int
main() {
  MapParser mp("src/tmx/resources/map.tmx");
  mp.loadTMXFile();
  mp.parse();
  return 0;
}
