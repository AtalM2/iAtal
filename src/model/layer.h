#ifndef LAYER_H
#define LAYER_H

#include <string>
#include <vector>

#include "tile.h"
#include "tmx/tileset.h"

class Layer {
public:
	Layer();
	Layer(unsigned int width, unsigned int height);
	virtual ~Layer();

	Tile getTile(unsigned int x, unsigned int y) const;
	void setTile(unsigned int x, unsigned int y, Tile tile);

	Tileset getTileset() const;

private:
	std::vector< std::vector< Tile > > tiles_;
	Tileset tileset_;

};

#endif // LAYER_H
