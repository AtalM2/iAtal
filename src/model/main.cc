#include "model/map.h"

#include <iostream>

int
main()
{
  Map map(10, 20);
  map.getLayer(0).getTile(5, 5);
  return 0;
}
