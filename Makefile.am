bin_PROGRAMS = $(NULL)
lib_LTLIBRARIES = $(NULL)
check_PROGRAMS = $(NULL)

ACLOCAL_AMFLAGS = -I m4

AM_CXXFLAGS =			\
	-std=c++0x			\
	$(DEBUG_CXXFLAGS)	\
	$(NULL)

include src/model/model.mk
include src/ui/ui.mk
include src/python/elements.mk
include src/test/model/test.mk
include src/test/python/test.mk
include src/test/tmx/test.mk
include src/test/ui/test.mk
