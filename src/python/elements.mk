lib_LTLIBRARIES += \
	elements.la \
	$(NULL)

elements_la_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)

elements_la_LDFLAGS = \
	$(python_LIBS) \
	-module \
	-shared \
	-avoid-version \
	$(BOOST_PYTHON_LDFLAGS) \
	$(NULL)

elements_la_SOURCES = \
	src/model/model.cc
	$(NULL)

# bin_PROGRAMS += \
# 	test_python \
# 	$(NULL)

# test_python_SOURCES = \
# 	src/python/main.cc \
# 	src/python/matrice.cc \
# 	src/model/map.cc \
# 	src/model/layer.cc \
# 	src/model/tileset.cc \
# 	$(NULL)

# test_python_CXXFLAGS = \
# 	$(AM_CXXFLAGS) \
# 	$(NULL)

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
