lib_LTLIBRARIES +=		\
	elements.la			\
	enums.la			\
	$(NULL)

enums_la_LDFLAGS =		\
	$(AM_LDFLAGS)		\
	-avoid-version		\
	-module				\
	$(NULL)

enums_la_SOURCES =	\
	src/model/layer.cc	\
	src/model/tileset.cc \
	$(NULL)

elements_la_LDFLAGS =	\
	$(AM_LDFLAGS)		\
	-avoid-version		\
	-module				\
	$(NULL)

elements_la_SOURCES =			\
	src/model/map.cc			\
	src/model/layer.cc			\
	src/model/tileset.cc		\
	$(NULL)


