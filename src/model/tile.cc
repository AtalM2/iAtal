#include "model/tile.h"

const Tile Tile::EMPTY;

Tile::Tile()
  : props_()
{
  
}

Tile::~Tile()
{
  
}

Glib::ustring
Tile::getProp(Glib::ustring key)
  const
{
  std::map< Glib::ustring, Glib::ustring >::const_iterator it =
    props_.find(key);
  if(it != props_.end())
    {
      return it->second;
    }
  else
    {
      return "prop non existing"; //TODO exception
    }
}

void
Tile::setProp(Glib::ustring key,
	      Glib::ustring value)
{
  props_[key] = value;
}

void
Tile::setType(Glib::ustring type)
{
  type_ = type;
}

Glib::ustring
Tile::getType()
  const
{
  return type_;
}
