#ifndef TILESET_H
#define	TILESET_H

#include "model/tile.h"
#include <string>

using namespace std;

class Tileset {
public:
	Tileset();
	virtual ~Tileset();
	void setSpacing(unsigned int spacing);
	unsigned int getSpacing() const;
	void setTileHeight(unsigned int tileHeight);
	unsigned int getTileHeight() const;
	void setTileWidth(unsigned int tileWidth);
	unsigned int getTileWidth() const;
	void setName(string name);
	string getName() const;
	void setImage(string image);
	string getImage() const;
	

private:
	string name_;
	unsigned int tileWidth_;
	unsigned int tileHeight_;
	unsigned int spacing_;
	string image_;

};

#endif	/* TILESET_H */

