bin_PROGRAMS += \
	ui \
	$(NULL)

ui_SOURCES = \
	src/ui/main.cc \
	src/ui/maparea.cc \
	src/ui/mapwindow.cc \
	src/model/map.cc \
	src/model/tileset.cc \
	src/model/layer.cc \
	src/tmx/map-loader.cc \
	src/tmx/tinyxml2.cc \
	src/tmx/tmx-tileset.cc \
	$(NULL)

ui_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)
