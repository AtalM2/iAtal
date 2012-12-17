#ifndef TMX_TILESET_H
#define	TMX_TILESET_H

#include <glibmm/ustring.h>
#include <map>
#include <gdkmm/pixbuf.h>
#include "tile.h"
#include <iostream>

namespace tmx {

	/*!
	 \brief Tileset is an object representation of a TMX tileset.
	*/
	class Tileset {
	public:
		/*!
		  \brief Empty constructor.
		 */
		Tileset();
		
		/*!
		  \brief Default destructor.
		 */
		virtual ~Tileset();

		/*!
		  \brief Set the tileset sprite with the given image.
		  
		  \param image The sprite.
		 */
		void setImage(Glib::RefPtr< const Gdk::Pixbuf > image);
		
		/*!
		  \brief Get the tileset sprite.
		 */
		Glib::RefPtr< const Gdk::Pixbuf > getImage() const;

		/*!
		  \brief Set the spacing between tiles images in the sprite.
		  
		  \param spacing The spacing size in pixels.
		 */
		void setSpacing(unsigned int spacing);
		
		/*!
		  \brief Get the spacing between tiles in the sprite in pixels.
		 */
		unsigned int getSpacing() const;

		/*!
		  \brief Set the tile height in this tileset.
		 
		  \param tileHeight The tile height.
		 */
		void setTileHeight(unsigned int tileHeight);
		
		/*!
		  \brief Get the tile height in this tileset.
		 */
		unsigned int getTileHeight() const;

		/*!
		  \brief Set the tile width in this tileset.
		 
		  \param tileWidth The tile width.
		 */
		void setTileWidth(unsigned int tileWidth);
		
		/*!
		  \brief Get the tile width in this tileset.
		 */
		unsigned int getTileWidth() const;

		/*!
		  \brief Set the name of the tileset.
		 
		  \param name The tileset name.
		 */
		void setName(Glib::ustring name);
		
		/*!
		  \brief Get the name of the tileset.
		 */
		Glib::ustring getName() const;

		/*!
		  \brief Set the first ID of this tileset when used in the map.
		 
		  \param firstgid The first ID.
		 */
		void setFirstgid(unsigned int firstgid);
		
		/*!
		  \brief Get the first ID of this tileset when used in the map.
		 */
		unsigned int getFirstgid() const;

		/*!
		  \brief Add a Tile in the tileset with the given ID.
		 
		  \param id The tile ID in the tileset.
		  \param tile The Tile.
		 */
		void setTile(unsigned int id, tmx::Tile tile);
		
		/*!
		  \brief Get the Tile with the given ID.
		 
		  \param id The tile ID in the tileset.
		 */
		tmx::Tile getTile(unsigned int id) const;

		/*!
		  \brief Print a string representation of the tileset.
		  
		  \param out The stream where the tileset is printed.
		 */
		void display(std::ostream & out) const;

	private:
		unsigned int firstgid_;						//!< The first id of this tileset when used in the map.
		Glib::ustring name_;						//!< The name of the tileset.
		unsigned int tileWidth_;					//!< The width of tiles in this tileset.
		unsigned int tileHeight_;					//!< The height of tiles in this map.
		unsigned int spacing_;						//!< The spacing between tiles in the tileset sprite.
		Glib::RefPtr< const Gdk::Pixbuf > image_;	//!< The sprite image of the tileset.
		std::map<unsigned int, tmx::Tile> tiles_;	//!< The map of tiles.
	};
}

std::ostream & operator<<(std::ostream &out,
		const tmx::Tileset & tileset);


#endif	/* TMX_TILESET_H */

