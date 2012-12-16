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

lib_LTLIBRARIES += \
	python_hello.la \
	$(NULL)

python_hello_la_SOURCES =		\
	src/python/python_hello.cc	\
	$(NULL)

python_hello_la_LDFLAGS =		\
	$(AM_LDFLAGS)				\
	-avoid-version				\
	-module						\
	$(NULL)

bin_PROGRAMS += cpp_hello
cpp_hello_SOURCES =	src/python/cpp_hello.cc

bin_PROGRAMS += cpp_hello_python

cpp_hello_python_SOURCES = \
	src/python/cpp_hello_python.cc \
	$(NULL)

cpp_hello_python_LDFLAGS = \
	$(AM_LDFLAGS) \
	python_hello.la \
	$(NULL)
