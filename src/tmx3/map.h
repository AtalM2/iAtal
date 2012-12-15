#ifndef MAP_H
#define	MAP_H

#include <string>
#include <map>
#include <vector>
#include <iostream>
#include "layer.h"
#include "tileset.h"

class Map {
public:
	Map();
	virtual ~Map();

	std::vector<Layer>* getLayers();

	std::vector<Tileset>* getTilesets();

	std::map<std::string, std::string> getProperties() const;
	void setProperty(std::string key, std::string value);
	std::string getProperty(std::string key) const;

	void setTileHeight(unsigned int tileHeight);
	unsigned int getTileHeight() const;

	void setTileWidth(unsigned int tileWidth);
	unsigned int getTileWidth() const;

	void setHeight(unsigned int height);
	unsigned int getHeight() const;

	void setWidth(unsigned int width);
	unsigned int getWidth() const;

	void setOrientation(std::string orientation);
	std::string getOrientation() const;

	void display(std::ostream & out) const;
	friend std::ostream & operator<<(std::ostream &out, const Map & map);

private:
	std::string orientation_;
	unsigned int width_;
	unsigned int height_;
	unsigned int tileWidth_;
	unsigned int tileHeight_;
	std::map<std::string, std::string> properties_;
	std::vector<Tileset> tilesets_;
	std::vector<Layer> layers_;
};

#endif	/* MAP_H */

