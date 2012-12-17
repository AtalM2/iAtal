#ifndef TMX_MAP_H
#define	TMX_MAP_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "tmx3/layer.h"
#include "tmx3/tileset.h"

namespace tmx {

	/*!
	  \brief A Map is an object representation of a TMX map.
	 */
	class Map {
	public:
		/*!
		  \brief empty constructor.
		 */
		Map();
		
		/*!
		  \brief Default destructor.
		 */
		virtual ~Map();

		/*!
		  \brief Return the list of layers.
		 */
		std::vector<tmx::Layer> & getLayers();

		/*!
		  \brief Return the list of tilesets.
		 */
		std::vector<tmx::Tileset> & getTilesets();

		/*!
		  \brief Return the list of properties.
		 */
		std::map<std::string, std::string> getProperties() const;

		/*!
		  \brief Set the given property with the given value.
		 
		  \param key The key of the property.
		  \param value The value of the property.
		 */
		void setProperty(const std::string & key,
				const std::string & value);
		
		/*!
		  \brief Get the property of the given key.
		 
		  \param key The key of the wanted property.
		 */
		std::string getProperty(const std::string & key) const;

		/*!
		  \brief Set the tile height in this map.
		 
		  \param tileHeight The tile height.
		 */
		void setTileHeight(unsigned int tileHeight);
		
		/*!
		  \brief Get the tile height in this map.
		 */
		unsigned int getTileHeight() const;

		/*!
		  \brief Set the tile width in this map.
		 
		  \param tileWidth The tile width.
		 */
		void setTileWidth(unsigned int tileWidth);
		
		/*!
		  \brief Get the tile width in this map.
		 */
		unsigned int getTileWidth() const;

		/*!
		  \brief Set the height of the map.
		 
		  \param height The map height.
		 */
		void setHeight(unsigned int height);
		
		/*!
		  \brief Get the height of the map.
		 */
		unsigned int getHeight() const;

		/*!
		  \brief Set the width of the map.
		 
		  \param width The map width.
		 */
		void setWidth(unsigned int width);
		
		/*!
		  \brief Get the width of the map.
		 */
		unsigned int getWidth() const;

		/*!
		  \brief Set the orientation of the map.
		 
		  \param width The map orientation.
		 */
		void setOrientation(const std::string & orientation);
		
		/*!
		  \brief Get the orientation of the map.
		 */
		std::string getOrientation() const;

		/*!
		  \brief Print a string representation of the map.
		  
		  \param out The stream where the map is printed.
		 */
		void display(std::ostream & out) const;

	private:
		std::string orientation_;						//!< The map orientation.
		unsigned int width_;							//!< The map width.
		unsigned int height_;							//!< The map height.
		unsigned int tileWidth_;						//!< The width of tiles in this map.
		unsigned int tileHeight_;						//!< The height of tiles in this map.
		std::map<std::string, std::string> properties_; //!< The map of properties.
		std::vector<tmx::Tileset> tilesets_;			//!< The array of tilesets.
		std::vector<tmx::Layer> layers_;				//!< The array of layers.
	};
}

std::ostream & operator<<(std::ostream & out,
		const tmx::Map & map);

#endif	/* TMX_MAP_H */

