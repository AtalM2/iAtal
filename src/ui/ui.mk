bin_PROGRAMS += \
	ui \
	$(NULL)

ui_SOURCES = \
	src/controllers/strategy-controller.cc \
	src/model/layer.cc \
	src/model/map.cc \
	src/model/tileset.cc \
	src/tmx/map-loader.cc \
	src/tmx/tinyxml2.cc \
	src/tmx/tmx-tileset.cc \
	src/ui/main.cc \
	src/ui/maparea.cc \
	src/ui/mapwindow.cc \
	$(NULL)

ui_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)
