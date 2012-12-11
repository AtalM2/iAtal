/* 
 * File:   MapLoader.h
 * Author: Noemi
 *
 * Created on 9 décembre 2012, 23:07
 */

#ifndef MAPLOADER_H
#define	MAPLOADER_H

#include <string>
#include "tinyxml2.h"
#include "map.h"

using namespace std;
using namespace tinyxml2;

class MapLoader {
public:
	static Map loadTmx(string tmxPath) throw(string);
private:
	static XMLElement* loadTsx(XMLElement* tsxElement) throw(string);

};

#endif	/* MAPLOADER_H */

