#ifndef LAYER_H
#define	LAYER_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

namespace tmx
{
  class Layer
  {
  public:
    Layer(unsigned int width, unsigned int height);
    virtual ~Layer();

    void setTile(unsigned int x,
		 unsigned int y,
		 unsigned int id);
    unsigned int getTile(unsigned int x,
			 unsigned int y) const;

    const std::map<std::string, std::string> &
      getProperties() const;
    void setProperty(const std::string & key,
		     const std::string & value);
    const std::string &
      getProperty(const std::string & key) const;

    unsigned int getHeight() const;

    unsigned int getWidth() const;

    void setName(const std::string & name);
    const std::string & getName() const;

    void display(std::ostream & out) const;

  private:
    std::string name_;
    unsigned int width_;
    unsigned int height_;
    std::vector<std::vector<unsigned int > > tiles_;
    std::map<std::string, std::string> properties_;
  };
}

std::ostream& operator<<(std::ostream &out,
			 const tmx::Layer & layer);

#endif	/* LAYER_H */

