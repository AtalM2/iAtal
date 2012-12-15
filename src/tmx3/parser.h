#ifndef PARSER_H
#define	PARSER_H

#include <string>
#include "map.h"
#include "tinyxml2.h"
#include "bad-parameters-exception.h"
#include "xml-exception.h"
#include "file-not-found-exception.h"

class Parser {
public:
	static Map parseFile(std::string filePath);
private:
	static void loadFile(tinyxml2::XMLDocument & tmxDoc, std::string filePath);
	static std::string getFileDirectory(std::string filePath);
	static std::vector<unsigned int> parseCsv(std::string data);

};

#endif	/* PARSER_H */

