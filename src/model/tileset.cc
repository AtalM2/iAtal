// -*- c-basic-offset: 2; -*-
#include "tileset.h"

#include "exceptions/model/bad-parameters-exception.h"

Tileset::Tileset() :
  tilesList_() {
}

Tileset::~Tileset() {
  
}

Glib::RefPtr< const Gdk::Pixbuf >
Tileset::getImage(Glib::ustring tile)
const
{
  Glib::RefPtr< const Gdk::Pixbuf > p;
  std::map< Glib::ustring,
	    Glib::RefPtr< const Gdk::Pixbuf >
	    >::const_iterator it = tilesList_.find(tile);
  if (it != tilesList_.end())
    {
    p = it->second;
    }
  else
    {
      throw BadParametersException(
	"Trying to access to a non existing property in a tileset.");
    }
  return p;
}

void
Tileset::setImage(Glib::ustring tile,
		  Glib::RefPtr< const Gdk::Pixbuf > image)
{
  tilesList_[tile] = image;
}
