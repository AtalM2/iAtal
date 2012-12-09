#ifndef TILE_H
#define TILE_H

#include <glibmm/ustring.h>
#include <map>

class Tile
{
  
 public:
  
  const static Tile EMPTY;
  
  Tile();
  
  Glib::ustring getProp(Glib::ustring key) const;
  void setProp(Glib::ustring key,
	       Glib::ustring value);
  
  void setType(Glib::ustring);
  Glib::ustring getType() const;
  
  virtual ~Tile();
  
 protected:
  
 private:
  std::map< Glib::ustring, Glib::ustring > props_;
  Glib::ustring type_;
};


#endif // TILE_H
