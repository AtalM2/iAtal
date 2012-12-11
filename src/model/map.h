#ifndef MAP_H
#define MAP_H

#include <vector>
#include <map>
#include <glibmm/ustring.h>

#include "model/map-utils.h"
#include "model/layer.h"

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
