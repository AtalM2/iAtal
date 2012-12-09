#ifndef LAYER_H
#define LAYER_H

#include <glibmm/ustring.h>
#include <vector>

#include "tile.h"

class Layer
{
  
 public:
  Layer();
  Layer(unsigned int width, unsigned int height);
  virtual ~Layer();
  
  Tile getTile(unsigned int x, unsigned int y) const;
  void setTile(unsigned int x, unsigned int y, Tile tile);

  
 private:
  std::vector< std::vector< Tile > > tiles_;

};

#endif // LAYER_H
