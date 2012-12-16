bin_PROGRAMS = $(NULL)
lib_LTLIBRARIES = $(NULL)
check_PROGRAMS = $(NULL)

ACLOCAL_AMFLAGS = -I m4

AM_CXXFLAGS = \
	-I$(srcdir)/src \
	-std=c++0x \
	$(DEBUG_CXXFLAGS) \
	$(gtk_CFLAGS) \
	$(python_CFLAGS)
	$(NULL)

AM_LDFLAGS = \
	$(gtk_LIBS) \
	$(python_LIBS) \
	$(BOOST_PYTHON_LDFLAGS) \
	$(BOOST_PROGRAM_OPTIONS_LDFLAGS) \
	$(PYTHON_LDFLAGS) \
	$(NULL)

LIBS = \
	$(BOOST_PROGRAM_OPTIONS_LIBS) \
	$(NULL)


AM_CPPFLAGS = \
	$(BOOST_CPPFLAGS) \
	$(NULL)

include src/ui/ui.mk
include src/python/elements.mk
include src/tmx3/tmx3.mk

if HAVE_CPPUNIT
include test/python/test.mk
include test/ui/test.mk
endif

include docs/doxygen.mk
