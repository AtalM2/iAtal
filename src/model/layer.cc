// -*- c-basic-offset: 2; -*-
#include "layer.h"

using namespace iatal;

Layer::Level Layer::identity_(Layer::Level x)
{
  return x;
}

BOOST_PYTHON_MODULE(enums)
{
  boost::python::enum_<Layer::Level>("Level")
    .value("Underground", Layer::Level::Underground)
    .value("Ground", Layer::Level::Ground)
    .value("Air", Layer::Level::Air)
    .value("Object", Layer::Level::Object)
    .export_values();

  boost::python::def("identity", &Layer::identity_);

}

Layer::Layer(unsigned int width,
             unsigned int height)
  : tiles_(height, std::vector< Glib::ustring >(width)),
    tileset_()
{

}

Layer::~Layer()
{

}

Glib::ustring
Layer::getTile(unsigned int x,
               unsigned int y)
  const
{
  return tiles_.at(x).at(y);
}

void
Layer::setTile(unsigned int x,
               unsigned int y,
               Glib::ustring tile)
{
  tiles_.at(x).at(y) = tile;
}

Tileset &
Layer::getTileset()
{
  return tileset_;
}
