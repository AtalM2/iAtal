/* 
 * File:   MapLoader.h
 * Author: Noemi
 *
 * Created on 9 décembre 2012, 23:07
 */

#ifndef MAPLOADER_H
#define	MAPLOADER_H

#include <string>
#include "src/model/map.h"

using namespace std;

class MapLoader {
public:
	static Map getMap(string tmxPath);

};

#endif	/* MAPLOADER_H */

