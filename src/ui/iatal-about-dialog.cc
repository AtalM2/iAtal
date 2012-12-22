// -*- c-basic-offset: 2; -*-
#include "iatal-about-dialog.h"

#include "config.h"

IAtalAboutDialog::IAtalAboutDialog()
  : authors_({
      "Rémi Bois",
	"Grégoire Jadi",
	"Agathe Mollé",
	"Joseph Lark",
	"Noémi Salaün",
	"Loïc Jankowiak",
	"Hugo Mougard"
	}),
    documenters_({
      "Rémi Bois",
	"Grégoire Jadi",
	"Agathe Mollé",
	"Joseph Lark",
	"Noémi Salaün",
	"Loïc Jankowiak",
	"Hugo Mougard"
	  }),
    artists_({
	"Agathe Mollé"
	  })
{
  set_program_name(PACKAGE_NAME);
  set_version(PACKAGE_VERSION);
  set_copyright("Copyright © 2012 Master ATAL");
  set_license_type(Gtk::License::LICENSE_GPL_3_0);
  set_website(PACKAGE_URL);
  set_website_label("iAtal homepage");
  set_authors(authors_);
  set_documenters(documenters_);
  set_artists(artists_);
  
  run();
}

IAtalAboutDialog::~IAtalAboutDialog()
{
  
}
