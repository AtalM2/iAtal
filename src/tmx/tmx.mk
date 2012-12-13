bin_PROGRAMS += \
	tmx \
	$(NULL)

tmx_SOURCES = \
	src/model/map.cc \
	src/model/tileset.cc \
	src/model/layer.cc \
	src/tmx/main.cc \
	src/tmx/map-loader.cc \
	src/tmx/tmx-tileset.cc \
	src/tmx/tinyxml2.cc \
	$(NULL)

tmx_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)
