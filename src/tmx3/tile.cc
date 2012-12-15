#include "tile.h"

Tile::Tile() {
}

Tile::~Tile() {
}

std::map<std::string, std::string> Tile::getProperties() const {
	return properties_;
}

void Tile::setProperty(std::string key, std::string value) {
	properties_[key] = value;
}

std::string Tile::getProperty(std::string key) const {
	if (key == "") {
		return "";
	}
	std::map<std::string, std::string>::const_iterator it = properties_.find(key);
	if (it != properties_.end()) {
		return it->second;
	} else {
		return "";
	}
}

void Tile::display(std::ostream & out) const {
	out << "Tile : " << std::endl
			<< "Properties : " << std::endl;
	std::map<std::string, std::string>::const_iterator it;
	for (it = properties_.begin(); it != properties_.end(); ++it) {
		out << it->first << " - " << it->second << std::endl;
	}
}

std::ostream & operator<<(std::ostream &out, const Tile & tile) {
	tile.display(out);
	return out;
}