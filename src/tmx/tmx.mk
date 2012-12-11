bin_PROGRAMS += \
	tmx			\
	$(NULL)

tmx_SOURCES =					\
	src/model/map.cc			\
	src/model/layer.cc			\
	src/model/tile.cc			\
	src/tmx/main.cc				\
	src/tmx/map-loader.cc		\
	src/tmx/tileset.cc			\
	src/tmx/tinyxml2.cc			\
	src/tmx/utils.cc			\
	$(NULL)

tmx_CPPFLAGS =			\
	$(gtk_CFLAGS)		\
	$(NULL)

tmx_LDFLAGS =	\
	$(gtk_LIBS) \
	$(NULL)
