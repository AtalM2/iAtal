#include <gtkmm/application.h>
#include <glibmm/refptr.h>

#include "display/mapwindow.h"

int
main(int argc, char** argv)
{
  Glib::RefPtr<Gtk::Application> app =
    Gtk::Application::create(argc,
			     argv,
			     "org.gtkmm.example");

  MapWindow window;
  
  return app->run(window);
}
