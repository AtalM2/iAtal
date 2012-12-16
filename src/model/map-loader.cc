#include "model/map-loader.h"

std::shared_ptr< Map2 >
MapLoader::make_shared(tmx::Map & tmxMap)
{
  // unsigned int nLayers = tmxMap.getLayers().size(),
  //   nTilesets = tmxMap.getTilesets().size();
  
  auto map = std::make_shared< Map2 >(tmxMap.getWidth(),
				      tmxMap.getHeight(),
				      tmxMap.getTileWidth(),
				      tmxMap.getTileHeight());
  
  return map;
}

bool
MapLoader::validateGeometry(const tmx::Map & map,
			    const tmx::Tileset & tileset)
{
  unsigned int tTileWidth = tileset.getTileWidth(),
    tTileHeight = tileset.getTileHeight(),
    tHeight = tileset.getHeight(),
    tWidth = tileset.getWidth(),
    tSpacing = tileset.getSpacing(),
    mTileWidth = map.getTileWidth(),
    mTileHeight = map.getTileHeight();

  if(tTileHeight != mTileHeight
     || tTileWidth != mTileWidth)
    return false;
  return true;
  unsigned int cellWidth =
    tWidth == tTileWidth ? 1 : (tWidth + tSpacing) / tTileWidth;
  unsigned int cellHeight =
    tHeight == tTileHeight ? 1 : (tHeight + tSpacing) / tTileHeight;
  if(tileset.getSize() < cellWidth * cellHeight)
    return false;
}
