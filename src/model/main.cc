// -*- c-basic-offset: 2; -*-
#include "map.h"

#include <iostream>

int
main()
{
  Map map(10, 20, 10, 10);
  map.getLayer(Layer::Underground).getTile(5, 5);
  return 0;
}
