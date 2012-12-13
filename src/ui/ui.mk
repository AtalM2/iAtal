bin_PROGRAMS += \
	ui \
	$(NULL)

ui_SOURCES = \
	src/ui/main.cc \
	src/ui/maparea.cc \
	src/ui/mapwindow.cc \
	$(NULL)

ui_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)
