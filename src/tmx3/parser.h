#ifndef TMX_PARSER_H
#define	TMX_PARSER_H

#include <string>
#include "map.h"
#include "tinyxml2.h"
#include "bad-parameters-exception.h"
#include "xml-exception.h"
#include "file-not-found-exception.h"

namespace tmx {

	/*!
	  \brief A TMX parser that retrieves information from XML using Tinyxml2 library.
	*/
	class Parser {
	public:
		/*!
		  \brief Main function. Parse the given TMX XML file into a TMX object representation.
		  
		  \param filePath The path of the XML file.
		 */
		static tmx::Map parseFile(std::string filePath);
	private:
		
		/*!
		  \brief Load the XML file into a XML document.
		  
		  \param tmxDoc The XMLDocument where the XML must be loaded.
		  \param filePath The path of the XML file.
		 */
		static void loadFile(tinyxml2::XMLDocument & tmxDoc,
				std::string filePath);
		
		/*!
		  \brief A tool function that retrieve the full directory path of a given file.
		  
		  \param filePath The file path.
		 */
		static std::string getFileDirectory(std::string filePath);

		/*!
		  \brief Extracts numbers from the given CSV.

		  \param data The string that contains the CSV.
		  \return A vector of numbers found in data.
		 */
		static std::vector<unsigned int> parseCsv(std::string data);

	};
}

#endif	/* TMX_PARSER_H */

