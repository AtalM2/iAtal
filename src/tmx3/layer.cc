#include "layer.h"

Layer::Layer(unsigned int height, unsigned int width) :
    width_(width),
    height_(height),
    tiles_(height, std::vector<unsigned int>(width, 0)),
    properties_() {
}

Layer::~Layer() {
}

void
Layer::setTile(unsigned int x, unsigned int y, unsigned int id) {
	if (x < width_ && y < height_) {
		tiles_.at(x).at(y) = id;
	} else {
		throw std::string("La tile est en dehors du layer");
	}
}

unsigned int
Layer::getTile(unsigned int x, unsigned int y) const {
	if (x < width_ && y < height_) {
		return tiles_.at(x).at(y);
	} else {
		throw std::string("La tile est en dehors du layer");
	}
}

std::map<std::string, std::string>
Layer::getProperties() const {
	return properties_;
}

void
Layer::setProperty(std::string key, std::string value) {
	properties_[key] = value;
}

std::string
Layer::getProperty(std::string key) const {
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

unsigned int
Layer::getHeight() const {
	return height_;
}

unsigned int
Layer::getWidth() const {
	return width_;
}

void
Layer::setName(std::string name) {
	name_ = name;
}

std::string
Layer::getName() const {
	return name_;
}

void
Layer::display(std::ostream & out) const {
	out << "Layer : " << std::endl
        << "Name : " << name_
        << " - Height : " << height_
        << " - Width : " << width_ << std::endl
        << "Properties : " << std::endl;
	std::map<std::string, std::string>::const_iterator it;
	for (it = properties_.begin(); it != properties_.end(); ++it) {
		out << it->first << " - " << it->second << std::endl;
	}
	out << "Tiles : " << std::endl;
	for (size_t i = 0; i < tiles_.size(); i++) {
		for (size_t j = 0; j < tiles_.at(i).size(); j++) {
			out << tiles_.at(i).at(j) << " ";
		}
		out << std::endl;
	}
}

std::ostream &
operator<<(std::ostream &out, const Layer & layer) {
	layer.display(out);
	return out;
}

