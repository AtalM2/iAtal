// -*- c-basic-offset: 2; -*-
#ifndef MAP_PARSER_H
#define	MAP_PARSER_H

#include <vector>


#include <glibmm/ustring.h>

#include "exceptions/model/bad-parameters-exception.h"
#include "exceptions/tmx/file-not-found-exception.h"
#include "exceptions/tmx/tmx-exception.h"

#include "lib/tinyxpath/xpath_processor.h"

#include "model/map.h"

#include "tmx/tinyxml2.h"

using namespace tinyxml2;

class MapParser {
public:

  /*!
    \brief Permet de créer et de renvoyer une Map générée à partir d'un
    fichier TMX

    \param tmxPath Le chemin du fichier TMX.
    \return La Map générée.
  */
  MapParser(const Glib::ustring & tmxPath);
  virtual ~MapParser();

  void loadTMXFile();
  void parse();

private:
  bool ok_;
  std::vector< Glib::ustring > toDisplay_;
  TiXmlDocument tmxDoc_;
  
  void handleTilesets(TinyXPath::node_set * & tilesets);
  void handleLayers(TinyXPath::node_set * & layers);
  void handleLayer(const TiXmlNode * & layerNode);
};

#endif	/* MAP_PARSER_H */
