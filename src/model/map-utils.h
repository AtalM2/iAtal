// -*- c-basic-offset: 2; -*-
#ifndef MAP_UTILS_H
#define MAP_UTILS_H

namespace iatal
{
  namespace map
  {

    /*!
      \brief An an enumeration used to select a Layer in a Map.

      */
    typedef enum
    {
      UNDERGROUND,
      GROUND,
      AIR,
      OBJECTS
    } Layers;
  }
}

#endif // MAP_UTILS_H
