// -*- c-basic-offset: 2; -*-
#include "map.h"

#include <iostream>

int
main()
{
  Map m(0, 0, std::pair<int,int>(0,0), 10 ,20 ,10 ,10);
  //std::cout << "case : " << m.getItem(Layer::Level(1),1) << std::endl;
  //m.tempDisplay();

  //  Map map(10, 20, 10, 10);
  //map.getLayer(Layer::Underground).getTile(5, 5);
  return 0;
}
