// -*- c-basic-offset: 2; -*-
#ifndef MAP_LOADER_H
#define	MAP_LOADER_H

#include <memory>
#include <string>

#include "exceptions/model/bad-parameters-exception.h"
#include "exceptions/tmx/file-not-found-exception.h"
#include "exceptions/tmx/tmx-exception.h"

#include "model/tileset.h"
#include "model/map.h"

#include "tmx/tinyxml2.h"
#include "tmx/tmx-tileset.h"

using namespace tinyxml2;

class MapLoader {
public:

  /*!
    \brief Permet de créer et de renvoyer une Map générée à partir d'un
    fichier TMX

    \param tmxPath Le chemin du fichier TMX.
    \return La Map générée.
  */
  static std::shared_ptr< Map > loadTmx(string tmxPath);

private:
  static void loadTMXFile(XMLDocument & tmxDoc,
			  const Glib::ustring & filepath);
  static void handleTileset(Tileset & ts,
			    const TmxTileset & tmxTs);
  static XMLElement* loadTsx(XMLElement* tsxElement);

};

#endif	/* MAP_LOADER_H */
