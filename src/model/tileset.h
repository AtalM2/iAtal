// -*- c-basic-offset: 2; -*-
#ifndef TILESET_H
#define	TILESET_H

#include <string>
#include <map>

#include <gdkmm/pixbuf.h>

using namespace std;

/*!
  \brief A Tileset stores the properties of each tiles in a dedicated
  Layer.

  Currently, the only property owned by a tile is its image.

*/
class Tileset {
public:

  /*!
    \brief Create an empty Tileset.

  */
  Tileset();
  
  /*!
    \brief Default destructor.

  */
  virtual ~Tileset();
  
  /*!
    \brief Returns the image of the given tile.

    \param tile The reference of a tile in the Tileset.
    \return The image of the tile referenced.
  */
Glib::RefPtr< Gdk::Pixbuf > getImage(string tile);

  
  /*!
    \brief Set the image of the given tile.

    \param tile The reference of a tile in the Tileset.
    \param image The new image of the selected tile.
  */
void setImage(string tile,
	      Glib::RefPtr< Gdk::Pixbuf > image);
  
private:

map<string, Glib::RefPtr< Gdk::Pixbuf > > tilesList_; //!< map<reference, image>
};

#endif	/* TILESET_H */
