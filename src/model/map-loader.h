// -*- c-basic-offset: 2; -*-
#ifndef MAP_LOADER_H
#define	MAP_LOADER_H

#include "model/map2.h"

#include <memory>

#include "tmx3/map.h"

class MapLoader
{
 public:
  
  static std::shared_ptr< Map2 > make_shared(tmx::Map & map);
  bool validateGeometry(const tmx::Map & map,
			const tmx::Tileset & tileset);
};

#endif	/* MAP_LOADER_H */
