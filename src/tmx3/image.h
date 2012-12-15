#ifndef IMAGE_H
#define	IMAGE_H

#include <string>
#include <iostream>

class Image {
public:
	Image();
	virtual ~Image();

	void setWidth(unsigned int width);
	unsigned int getWidth() const;

	void setHeight(unsigned int height);
	unsigned int getHeight() const;

	void setTransparency(std::string transparency);
	std::string getTransparency() const;

	void setPath(std::string path);
	std::string getPath() const;

	void display(std::ostream & out) const;
	friend std::ostream & operator<<(std::ostream & out, const Image & image);

private:
	std::string path_;
	std::string transparency_;
	unsigned int height_;
	unsigned int width_;
};

#endif	/* IMAGE_H */

