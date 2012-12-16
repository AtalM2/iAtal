#ifndef MAP_H
#define	MAP_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "tmx3/layer.h"
#include "tmx3/tileset.h"

namespace tmx
{
  class Map
  {
  public:
    Map();
    virtual ~Map();

    std::vector<tmx::Layer> & getLayers();

    std::vector<tmx::Tileset> & getTilesets();

    std::map<std::string, std::string> getProperties() const;
	
    void setProperty(const std::string & key,
		     const std::string & value);
    std::string getProperty(const std::string & key) const;

    void setTileHeight(unsigned int tileHeight);
    unsigned int getTileHeight() const;

    void setTileWidth(unsigned int tileWidth);
    unsigned int getTileWidth() const;

    void setHeight(unsigned int height);
    unsigned int getHeight() const;

    void setWidth(unsigned int width);
    unsigned int getWidth() const;

    void setOrientation(const std::string & orientation);
    std::string getOrientation() const;

    void display(std::ostream & out) const;

  private:
    std::string orientation_;
    unsigned int width_;
    unsigned int height_;
    unsigned int tileWidth_;
    unsigned int tileHeight_;
    std::map<std::string, std::string> properties_;
    std::vector<tmx::Tileset> tilesets_;
    std::vector<tmx::Layer> layers_;
  };
}

std::ostream & operator<<(std::ostream & out,
			  const tmx::Map & map);

#endif	/* MAP_H */

