#include "tile.h"

#include "bad-parameters-exception.h"

Tile::Tile() {
}

Tile::~Tile() {
}

const std::map<std::string, std::string> &
Tile::getProperties() const {
	return properties_;
}

void
Tile::setProperty(const std::string & key,
		  const std::string & value) {
	properties_[key] = value;
}

const std::string &
Tile::getProperty(const std::string & key) const {
	if (key == "") {
	  throw BadParametersException(
	    "Empty key given as ID to the tile getProperty method.");
	}
	auto it = properties_.find(key);
	if (it != properties_.end()) {
		return it->second;
	} else {
	  throw BadParametersException(
	    "ID given to the tile getProperty method wasn't found.");
	}
}

void
Tile::display(std::ostream & out) const {
	out << "Tile : " << std::endl
        << "Properties : " << std::endl;
	std::map<std::string, std::string>::const_iterator it;
	for (it = properties_.begin(); it != properties_.end(); ++it) {
		out << it->first << " - " << it->second << std::endl;
	}
}

std::ostream &
operator<<(std::ostream & out, const Tile & tile) {
	tile.display(out);
	return out;
}
