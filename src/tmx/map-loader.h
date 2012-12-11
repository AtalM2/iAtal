// -*- c-basic-offset: 2; -*-
#ifndef MAP_LOADER_H
#define	MAP_LOADER_H

#include <string>

#include "model/map.h"

#include "tmx/tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class MapLoader {
 public:
  static Map loadTmx(string tmxPath) throw(string);
 private:
  static XMLElement* loadTsx(XMLElement* tsxElement) throw(string);

};

#endif	/* MAP_LOADER_H */
