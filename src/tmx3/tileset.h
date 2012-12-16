#ifndef TMX_TILESET_H
#define	TMX_TILESET_H

#include <glibmm/ustring.h>
#include <map>
#include <gdkmm/pixbuf.h>
#include "tile.h"
#include <iostream>

namespace tmx
{
  class Tileset
  {
  public:
    Tileset();
    virtual ~Tileset();

    void setImage(Glib::RefPtr< const Gdk::Pixbuf > image);
    Glib::RefPtr< const Gdk::Pixbuf > getImage() const;

    void setSpacing(unsigned int spacing);
    unsigned int getSpacing() const;

    void setTileHeight(unsigned int tileHeight);
    unsigned int getTileHeight() const;

    void setTileWidth(unsigned int tileWidth);
    unsigned int getTileWidth() const;

    void setName(Glib::ustring name);
    Glib::ustring getName() const;

    void setFirstgid(unsigned int firstgid);
    unsigned int getFirstgid() const;

    void setTile(unsigned int id, tmx::Tile tile);
    tmx::Tile getTile(unsigned int id) const;

    void display(std::ostream & out) const;

  private:
    unsigned int firstgid_;
    Glib::ustring name_;
    unsigned int tileWidth_;
    unsigned int tileHeight_;
    unsigned int spacing_;
    Glib::RefPtr< const Gdk::Pixbuf > image_;
    std::map<unsigned int, tmx::Tile> tiles_;
  };
}

std::ostream & operator<<(std::ostream &out,
			  const tmx::Tileset & tileset);


#endif	/* TMX_TILESET_H */

