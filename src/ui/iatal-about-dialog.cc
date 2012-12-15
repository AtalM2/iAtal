// -*- c-basic-offset: 2; -*-
#include "iatal-about-dialog.h"

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
	"Grégoire Jadi"
	  }),
    artists_({
	"Agathe Mollé"
	  })
{
  set_program_name("iAtal");
  set_version("1.0.0");
  set_copyright("Copyright © 2012 Master ATAL");
  set_license_type(Gtk::License::LICENSE_GPL_3_0);
  set_website("http://atal.univ-nantes.fr/");
  set_website_label("ATAL website");
  set_authors(authors_);
  set_documenters(documenters_);
  set_artists(artists_);
}

IAtalAboutDialog::~IAtalAboutDialog()
{
  
}
