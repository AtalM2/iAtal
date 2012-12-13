// -*- c-basic-offset: 2; -*-
#include <map>

#include "tileset.h"

Tileset::Tileset() :
  tilesList_() {
}

Tileset::~Tileset() {
  
}

Glib::RefPtr< Gdk::Pixbuf >
Tileset::getImage(string tile) {
  Glib::RefPtr< Gdk::Pixbuf > p;
  std::map< string,
	    Glib::RefPtr< Gdk::Pixbuf >
	    >::const_iterator it = tilesList_.find(tile);
  if (it != tilesList_.end()) {
    p = it->second;
  } else {
    throw string("prop non existing");
  }
  return p;
}

void
Tileset::setImage(string tile,
		  Glib::RefPtr< Gdk::Pixbuf > image)
{
  tilesList_[tile] = image;
}
