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

bin_PROGRAMS += \
	test_python \
	$(NULL)

test_python_SOURCES = \
	src/python/main.cc \
	src/python/matrice.cc \
	src/model/map.cc \
	src/model/layer.cc \
	src/model/tileset.cc \
	$(NULL)

test_python_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)
