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
	-lboost_python-py32 \
	$(NULL)

AM_CPPFLAGS = \
	$(BOOST_CPPFLAGS) \
	$(NULL)

include src/model/model.mk
include src/ui/ui.mk
include src/python/elements.mk
include src/tmx/tmx.mk
include src/tmx2/tmx2.mk

include src/lib/tinyxpath/tinyxpath.mk

include test/model/test.mk
include test/python/test.mk
include test/tmx/test.mk
include test/ui/test.mk

include docs/doxygen.mk
