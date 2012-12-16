#ifndef TILE_H
#define	TILE_H

#include <string>
#include <map>
#include <iostream>

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
	friend std::ostream & operator<<(std::ostream & out,
					 const Tile & tile);

private:
	std::map<std::string, std::string> properties_;
};

#endif	/* TILE_H */

