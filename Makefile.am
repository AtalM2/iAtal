bin_PROGRAMS = $(NULL)
lib_LTLIBRARIES = $(NULL)

ACLOCAL_AMFLAGS = -I m4

AM_CXXFLAGS = \
	-std=c++0x \
	$(DEBUG_CXXFLAGS) \
	$(NULL)

include src/model/model.mk
include src/ui/ui.mk
include src/python/elements.mk
