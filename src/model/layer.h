// -*- c-basic-offset: 2; -*-
#ifndef LAYER_H
#define LAYER_H

#include <algorithm>
#include <string>
#include <vector>

#include <glibmm/ustring.h>

#include "tileset.h"

class Layer {
public:
  Layer();
  Layer(unsigned int width, unsigned int height);
  virtual ~Layer();

  Glib::ustring getTile(unsigned int x, unsigned int y) const;
  void setTile(unsigned int x, unsigned int y, std::string tile);

  Tileset & getTileset() const;

private:
  std::vector< std::vector< std::string > > tiles_;
  Tileset tileset_;

};

#endif // LAYER_H
