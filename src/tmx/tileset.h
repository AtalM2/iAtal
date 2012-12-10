/* 
 * File:   tileset.h
 * Author: Noemi
 *
 * Created on 10 décembre 2012, 00:35
 */

#ifndef TILESET_H
#define	TILESET_H

#include "src/model/tile.h"
#include <string>
#include "tinyxml2.h"

using namespace std;
using namespace tinyxml2;

class Tileset {
public:
	Tileset(XMLElement* xmlElement);
	virtual ~Tileset();

	void SetSpacing(unsigned int spacing);
	unsigned int GetSpacing() const;
	void SetTileHeight(unsigned int tileHeight);
	unsigned int GetTileHeight() const;
	void SetTileWidth(unsigned int tileWidth);
	unsigned int GetTileWidth() const;
	void SetName(string name);
	string GetName() const;

private:
	string name_;
	unsigned int tileWidth_;
	unsigned int tileHeight_;
	unsigned int spacing_;

};

#endif	/* TILESET_H */

