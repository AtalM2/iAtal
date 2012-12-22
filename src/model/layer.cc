// -*- c-basic-offset: 2; -*-

//  Copyright (C) 2012

// This file is part of iAtal.

// iAtal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// iAtal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with iAtal.  If not, see <http://www.gnu.org/licenses/>.

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
