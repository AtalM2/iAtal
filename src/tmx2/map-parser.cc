#include "map-parser.h"

#include <iostream>

using namespace TinyXPath;

void
MapParser::loadTMXFile()
{
  if (!tmxDoc_.LoadFile())
    {
      ostringstream error;
      error << "The loading of the TMX file failed. ";
      throw TmxException(error.str());
    }
  else
    {
      ok_ = true;
    }
}

MapParser::~MapParser()
{
  
}

MapParser::MapParser(const Glib::ustring & filePath)
  : ok_(false),
    toDisplay_(),
    tmxDoc_(filePath.c_str())
{
  
}

void
MapParser::parse()
{
  if(!ok_)
    {
      std::cerr << "map-parser.cc: Parsing tentative "
		<< "with an uninitialized object. "
		<< "It's mandatory to successfully "
		<< "load a TMX file before calling the "
		<< "parse method."
		<< std::endl;
      return;
    }
  TiXmlElement * root = tmxDoc_.RootElement();

  xpath_processor xpathLayers(root, "//layer");
  xpath_processor xpathTilesets(root, "//tileset");

  expression_result erLayers =
    xpathLayers.er_compute_xpath();
  expression_result erTilesets =
    xpathTilesets.er_compute_xpath();

  node_set * layers =
    erLayers.nsp_get_node_set();
  node_set * tilesets =
    erTilesets.nsp_get_node_set();
  
  handleTilesets(tilesets);
  handleLayers(layers);
}

void
MapParser::handleTilesets(node_set * & tilesets)
{
  unsigned int nb = tilesets->u_get_nb_node_in_set();
  std::cout << nb << std::endl;
  // const TiXmlNode * tileset = tilesets->XNp_get_node_in_set(0);
}

void
MapParser::handleLayers(node_set * & layers)
{
  unsigned int size = layers->u_get_nb_node_in_set();
  for(unsigned int i = 0; i < size; i++)
    {
      const TiXmlNode * layer = layers->XNp_get_node_in_set(i);
      handleLayer(layer);
    }
  std::cout << size << std::endl;
}

void
MapParser::handleLayer(const TiXmlNode * & layerNode)
{
  bool visible = false;
  const TiXmlElement * layer = layerNode->ToElement();
  const char * visibleAtt = layer->Attribute("visible");
  if(visibleAtt)
    {
      visible = (Glib::ustring(visibleAtt) == "1");
    }
  std::cout << visible << std::endl;
}
