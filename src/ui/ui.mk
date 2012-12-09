bin_PROGRAMS += \
	ui

ui_SOURCES = \
	src/ui/main.cc \
	src/ui/maparea.cc \
	src/ui/mapwindow.cc

AM_CPPFLAGS = \
	$(ui_CFLAGS)

ui_CXXFLAGS = \
	-std=c++0x $(DEBUG_CXXFLAGS)

ui_LDADD = \
	$(ui_LIBS)
