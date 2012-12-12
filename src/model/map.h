// -*- c-basic-offset: 2; -*-
#ifndef MAP_H
#define MAP_H

#include <vector>

#include <glibmm/ustring.h>

#include "layer.h"

/*!
  \brief A Map is made of zero or more Layer.

*/
class Map
{
  
public:
  
  /*!
    \brief Initialize an empty Map of the given size.

    \param width the width of the map.
    \param height the height of the map.
  */
  Map(unsigned int width,
      unsigned int height,
      unsigned int tileWidth,
      unsigned int tileHeight);

  const unsigned int height; //!< The height of the map in cells

  const unsigned int width; //!< The width of the map in cells

  const unsigned int tileHeight; //!< The height of the cells

  const unsigned int tileWidth; //!< The width of the cells

  /*!
    \brief Returns the Layer at the given level.

    \param layer An integer which denotes the chosen level.
    \return The selected Layer.
  */
  Layer& getLayer(Layer::Level level);  
  
  /*!
    \brief Default destructor.

  */
  virtual ~Map();

protected:
  
private:
  std::vector< Layer > layers_; //!< The set of Layer
};

#endif // MAP_H
