// -*- c-basic-offset: 2; -*-

#ifndef TMX_TILESET_H
#define	TMX_TILESET_H

#include <gtkmm/application.h>

class TmxTileset {
public:
  TmxTileset();
  virtual ~TmxTileset();

  void setSpacing(unsigned int spacing);
  unsigned int getSpacing() const;

  void setTileHeight(unsigned int tileHeight);
  unsigned int getTileHeight() const;

  void setTileWidth(unsigned int tileWidth);
  unsigned int getTileWidth() const;

  void setHeight(unsigned int height);
  unsigned int getHeight() const;

  void setWidth(unsigned int width);
  unsigned int getWidth() const;

  void setName(Glib::ustring name);
  Glib::ustring getName() const;

  void setImage(Glib::ustring image);
  Glib::ustring getImage() const;

  void setFirstGid(unsigned int firstGid);
  unsigned int getFirstGid() const;

  void setProperty(unsigned int id, Glib::ustring value);
  Glib::ustring getProperty(unsigned int id) const;
  
  const std::map< unsigned int, Glib::ustring > & getProperties() const;

private:
  std::map<unsigned int, Glib::ustring> propertiesList_;
  unsigned int firstGid_,
    tileWidth_,
    tileHeight_,
    width_,
    height_,
    spacing_;
  Glib::ustring image_;

};

#endif	/* TMX_TILESET_H */

