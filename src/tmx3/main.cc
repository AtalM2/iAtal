#include <gtkmm/application.h>
#include <glibmm/refptr.h>

#include <iostream>
#include <string>

#include "parser.h"
#include "exception.h"

using namespace tmx;

int
main(int argc, char **argv)
{
    Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create(argc,
                                 argv,
                                 "org.gtkmm.example");

	Map map;
	try {
		map = Parser::parseFile("src/tmx/resources/map1.tmx");
		std::cout << map << std::endl;
	} catch (Exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
