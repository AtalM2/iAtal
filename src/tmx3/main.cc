#include <iostream>
#include <string>

#include "parser.h"
#include "exception.h"

int main() {
	Map map;
	try {
		map = Parser::parseFile("resources/map.tmx");
		std::cout << map << std::endl;
	} catch (Exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
