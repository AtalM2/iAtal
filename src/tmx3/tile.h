#ifndef TILE_H
#define	TILE_H

#include <string>
#include <map>
#include <iostream>

namespace tmx
{
  class Tile {
  public:
    Tile();
    virtual ~Tile();

    const std::map<std::string, std::string> &
      getProperties() const;
    void setProperty(const std::string & key,
		     const std::string & value);
    const std::string & getProperty(const std::string & key) const;

    void display(std::ostream & out) const;

  private:
    std::map<std::string, std::string> properties_;
  };
}

std::ostream & operator<<(std::ostream & out,
			  const tmx::Tile & tile);

#endif	/* TILE_H */

