// -*- c-basic-offset: 2; -*-
#ifndef TILESET_H
#define	TILESET_H

#include <string>
#include <map>

using namespace std;

class Tileset {
 public:
  Tileset();
  virtual ~Tileset();
  string getImage(string tile) const throw (string);
  void setImage(string tile, string image);
  
 private:
  map<string, string> tilesList_;
};

#endif	/* TILESET_H */
