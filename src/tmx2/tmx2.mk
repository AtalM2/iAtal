bin_PROGRAMS += \
	tmx2 \
	$(NULL)

tmx2_SOURCES = \
	src/model/map.cc \
	src/model/tileset.cc \
	src/model/layer.cc \
	src/tmx2/main.cc \
	src/tmx2/map-parser.cc \
	src/tmx/tinyxml2.cc \
	$(NULL)

tmx2_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)
