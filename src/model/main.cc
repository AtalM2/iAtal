// -*- c-basic-offset: 2; -*-
#include "model.h"

#include <iostream>

int
main()
{
  Model m(0,0,std::pair<int,int>(0,1),10,20,10,10);
  m.goOn();
  std::cout << "case : " << m.getItem(Layer::Level(1),1) << std::endl;
  m.tempDisplay();
  
  //  Map map(10, 20, 10, 10);
  //map.getLayer(Layer::Underground).getTile(5, 5);
  return 0;
}
