bin_PROGRAMS += \
	ui \
	$(NULL)

ui_SOURCES = \
	src/controllers/map-controller.cc \
	src/controllers/strategy-controller.cc \
	src/model/layer.cc \
	src/model/map.cc \
	src/model/tileset.cc \
	src/tmx/map-loader.cc \
	src/tmx/tinyxml2.cc \
	src/tmx/tmx-tileset.cc \
	src/ui/main.cc \
	src/ui/map-area.cc \
	src/ui/map-window.cc \
	src/ui/python-chooser-dialog.cc \
	src/ui/tmx-chooser-dialog.cc \
	src/ui/iatal-ui-manager.cc \
	$(NULL)

ui_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)
