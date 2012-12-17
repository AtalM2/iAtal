#ifndef TMX_TILE_H
#define	TMX_TILE_H

#include <string>
#include <map>
#include <iostream>

namespace tmx {

	/*!
	  \brief Tile is an object representation of a TMX tile.
	 */
	class Tile {
	public:

		/*!
		  \brief Empty constructor.
		 */
		Tile();
		
		/*!
		  \brief Default destructor.
		 */
		virtual ~Tile();

		/*!
		  \brief Get properties of the tile
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
		
		/*!
		  \brief Get the property of the given key.
		 
		  \param key The key of the wanted property.
		 */
		const std::string & getProperty(const std::string & key) const;

		/*!
		  \brief Print a string representation of the tile.
		  
		  \param out The stream where the tile is printed.
		 */
		void display(std::ostream & out) const;

	private:
		std::map<std::string, std::string> properties_;	//!< The map of properties.
	};
}

std::ostream & operator<<(std::ostream & out,
		const tmx::Tile & tile);

#endif	/* TMX_TILE_H */

