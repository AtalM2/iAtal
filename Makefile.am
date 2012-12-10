bin_PROGRAMS = $(NULL)
lib_LTLIBRARIES = $(NULL)
check_PROGRAMS = $(NULL)

ACLOCAL_AMFLAGS = -I m4

AM_CXXFLAGS = \
	-std=c++0x \
	$(DEBUG_CXXFLAGS) \
	$(NULL)

include src/model/model.mk
include src/ui/ui.mk
include src/python/elements.mk
include src/tmx/tmx.mk

include test/model/test.mk
include test/python/test.mk
include test/tmx/test.mk
include test/ui/test.mk

include docs/doxygen.mk
