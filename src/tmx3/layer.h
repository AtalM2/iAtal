#ifndef TMX_LAYER_H
#define	TMX_LAYER_H

#include <map>
#include <string>
#include <vector>
#include <iostream>

namespace tmx {

	/*!
		  \brief A Layer is an object representation of layers elements in TMX.
	 */
	class Layer {
	public:
		/*!
		  \brief Initialise an empty layer of the given size.
		 
		  \param width The width of the layer.
		  \param height The height of the layer.
		 */
		Layer(unsigned int width, unsigned int height);
		
		/*!
		  \brief Default desctructor.
		 */
		virtual ~Layer();

		/*!
		  \brief Set the given tile with a tileset properties id.
		 
		  \param x Abscissa of the tile.
		  \param y Ordinate of the tile.
		  \param id The id of tileset properties.
		 */
		void setTile(unsigned int x,
				unsigned int y,
				unsigned int id);
		
		/*!
		  \brief Get the tileset properties id of the given tile.
		 
		  \param x Abscissa of the tile.
		  \param y Ordinate of the tile.
		 */
		unsigned int getTile(unsigned int x,
				unsigned int y) const;

		/*!
		  \brief Get the properties of the layer.
		 */
		const std::map<std::string, std::string> &
		getProperties() const;
		
		/*!
		  \brief Set the given property with the given value.
		 
		  \param key The key of the property.
		  \param value The value of the property.
		 */
		void setProperty(const std::string & key,
				const std::string & value);
		const std::string &
		
		/*!
		  \brief Get the property of the given key.
		 
		  \param key The key of the wanted property.
		 */
		getProperty(const std::string & key) const;

		/*!
		  \brief Get the height of the layer.
		 */
		unsigned int getHeight() const;

		/*!
		  \brief Get the width of the layer.
		 */
		unsigned int getWidth() const;

		/*!
		  \brief Set the name of the layer.
		 
		  \param name The name of the layer.
		 */
		void setName(const std::string & name);
		
		/*!
		  \brief Get the name of the layer.
		 */
		const std::string & getName() const;

		/*!
		  \brief Print a string representation of the layer.
		  
		  \param out The stream where the layer is printed.
		 */
		void display(std::ostream & out) const;

	private:
		std::string name_;									//!< The layer name.
		unsigned int width_;								//!< The layer width.
		unsigned int height_;								//!< The layer height.
		std::vector<std::vector<unsigned int > > tiles_;	//!< The matrix of tiles.
		std::map<std::string, std::string> properties_;		//!< The map of properties.
	};
}

std::ostream& operator<<(std::ostream &out,
		const tmx::Layer & layer);

#endif	/* TMX_LAYER_H */

