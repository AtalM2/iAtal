#ifndef LAYER_H
#define LAYER_H

#include <string>
#include <vector>

#include "tileset.h"

class Layer {
public:
	Layer();
	Layer(unsigned int width, unsigned int height);
	virtual ~Layer();

	std::string getTile(unsigned int x, unsigned int y) const;
	void setTile(unsigned int x, unsigned int y, std::string tile);

	Tileset getTileset() const;

private:
	std::vector< std::vector< std::string > > tiles_;
	Tileset tileset_;

};

#endif // LAYER_H
