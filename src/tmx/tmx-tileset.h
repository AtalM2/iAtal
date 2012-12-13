// -*- c-basic-offset: 2; -*-

#ifndef TMX_TILESET_H
#define	TMX_TILESET_H

#include <string>

using namespace std;

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

  void setName(string name);
  string getName() const;

  void setImage(string image);
  string getImage() const;

  void setFirstGid(unsigned int firstGid);
  unsigned int getFirstGid() const;

  void setProperty(unsigned int id, string value);
  string getProperty(unsigned int id) const;
  
  const map< unsigned int, string > & getProperties() const;

private:
  map<unsigned int, string> propertiesList_;
  unsigned int firstGid_,
    tileWidth_,
    tileHeight_,
    width_,
    height_,
    spacing_;
  string image_;

};

#endif	/* TMX_TILESET_H */

