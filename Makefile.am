bin_PROGRAMS = $(NULL)
lib_LTLIBRARIES = $(NULL)
check_PROGRAMS = $(NULL)

ACLOCAL_AMFLAGS = -I m4

AM_CXXFLAGS =			\
	-std=c++0x			\
	$(DEBUG_CXXFLAGS)	\
	$(NULL)

# The Automake documentation is wrong, INCLUDES isn't equivalent to
# AM_CPPFLAGS. Don't use it and don't ask me why.
INCLUDES =				\
	-I$(srcdir)/src		\
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
