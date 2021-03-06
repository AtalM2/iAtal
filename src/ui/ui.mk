bin_PROGRAMS += \
	iatal \
	$(NULL)

iatal_SOURCES = \
	src/controllers/app-controller.cc \
	src/controllers/map-controller.cc \
	src/controllers/strategy-controller.cc \
	src/model/layer.cc \
	src/model/map.cc \
	src/model/tileset.cc \
	src/tmx/map-loader.cc \
	src/tmx/tinyxml2.cc \
	src/tmx/tmx-tileset.cc \
	src/ui/iatal-about-dialog.cc \
	src/ui/iatal-ui-manager.cc \
	src/ui/main.cc \
	src/ui/map-area.cc \
	src/ui/map-window.cc \
	src/ui/python-chooser-dialog.cc \
	src/ui/status-hbox.cc \
	src/ui/tmx-chooser-dialog.cc \
	src/ui/warning-dialog.cc \
	$(NULL)

iatal_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)
