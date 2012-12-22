// -*- c-basic-offset: 2; -*-

//  Copyright (C) 2012

// This file is part of iAtal.

// iAtal is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// iAtal is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with iAtal.  If not, see <http://www.gnu.org/licenses/>.

#ifndef MAP_LOADER_H
#define	MAP_LOADER_H

#include "model/map.h"
#include <memory>
#include <string>

#include "exceptions/model/bad-parameters-exception.h"
#include "exceptions/tmx/file-not-found-exception.h"
#include "exceptions/tmx/tmx-exception.h"

#include "model/tileset.h"

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
  static std::shared_ptr< iatal::Map > loadTmx(std::string tmxPath);

private:
  static void loadTMXFile(XMLDocument & tmxDoc,
			  const Glib::ustring & filepath);
  static void handleTileset(iatal::Tileset & ts,
			    const TmxTileset & tmxTs);
  static XMLElement* loadTsx(XMLElement* tsxElement);

};

#endif	/* MAP_LOADER_H */
