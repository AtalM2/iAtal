#ifndef LAYER_H
#define	LAYER_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

class Layer {
public:
	Layer(unsigned int width, unsigned int height);
	virtual ~Layer();

	void setTile(unsigned int x, unsigned int y, unsigned int id);
	unsigned int getTile(unsigned int x, unsigned int y) const;

	std::map<std::string, std::string> getProperties() const;
	void setProperty(std::string key, std::string value);
	std::string getProperty(std::string key) const;

	unsigned int getHeight() const;

	unsigned int getWidth() const;

	void setName(std::string name);
	std::string getName() const;

	void display(std::ostream & out) const;
	friend std::ostream& operator<<(std::ostream &out, const Layer & layer);

private:
	std::string name_;
	unsigned int width_;
	unsigned int height_;
	std::vector<std::vector<unsigned int > > tiles_;
	std::map<std::string, std::string> properties_;
};

#endif	/* LAYER_H */

