#ifndef TILESET_H
#define	TILESET_H

#include <string>
#include <map>
#include "image.h"
#include "tile.h"
#include <iostream>

using namespace std;

class Tileset {
public:
	Tileset();
	virtual ~Tileset();

	void setImage(Image image);
	Image getImage() const;

	void setSpacing(unsigned int spacing);
	unsigned int getSpacing() const;

	void setTileHeight(unsigned int tileHeight);
	unsigned int getTileHeight() const;

	void setTileWidth(unsigned int tileWidth);
	unsigned int getTileWidth() const;

	void setName(std::string name);
	std::string getName() const;

	void setFirstgid(unsigned int firstgid);
	unsigned int getFirstgid() const;

	void setTile(unsigned int id, Tile tile);
	Tile getTile(unsigned int id) const;

	void display(std::ostream & out) const;
	friend std::ostream & operator<<(std::ostream &out, const Tileset & tileset);

private:
	unsigned int firstgid_;
	std::string name_;
	unsigned int tileWidth_;
	unsigned int tileHeight_;
	unsigned int spacing_;
	Image image_;
	std::map<unsigned int, Tile> tiles_;
};

#endif	/* TILESET_H */

