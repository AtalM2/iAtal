#include "image.h"

Image::Image() {
}

Image::~Image() {
}

void Image::setWidth(unsigned int width) {
	width_ = width;
}

unsigned int Image::getWidth() const {
	return width_;
}

void Image::setHeight(unsigned int height) {
	height_ = height;
}

unsigned int Image::getHeight() const {
	return height_;
}

void Image::setTransparency(std::string transparency) {
	transparency_ = transparency;
}

std::string Image::getTransparency() const {
	return transparency_;
}

void Image::setPath(std::string path) {
	path_ = path;
}

std::string Image::getPath() const {
	return path_;
}

void Image::display(std::ostream & out) const {
	out << "Image : " << std::endl
			<< "Path : " << path_ << std::endl
			<< "Height : " << height_
			<< " - Width : " << width_
			<< " - Transparency : " << transparency_;
}

std::ostream & operator<<(std::ostream &out, const Image & image) {
	image.display(out);
	return out;
}

