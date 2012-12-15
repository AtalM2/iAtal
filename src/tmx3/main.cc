#include <gtkmm/application.h>
#include <glibmm/refptr.h>

#include <iostream>
#include <string>

#include "parser.h"
#include "exception.h"

int
main(int argc, char **argv)
{
    Glib::RefPtr<Gtk::Application> app =
        Gtk::Application::create(argc,
                                 argv,
                                 "org.gtkmm.example");

	Map map;
	try {
		map = Parser::parseFile("resources/map.tmx");
		std::cout << map << std::endl;
	} catch (Exception e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
