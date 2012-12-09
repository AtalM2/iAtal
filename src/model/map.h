#ifndef MAP_H
#define MAP_H

#include <vector>
#include <map>
#include <glibmm/ustring.h>

#include "map-utils.h"
#include "layer.h"

class Map
{
  
 public:
  Map(unsigned int width,
      unsigned int height);
  Layer getLayer(int layer) const;
  
  
  virtual ~Map();

 protected:
  
 private:
  std::vector< Layer > layers_;
};

#endif // MAP_H
