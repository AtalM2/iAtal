noinst_LTLIBRARIES += \
	elements.la

elements_la_CXXFLAGS = \
	-I/usr/include/python3.2mu/

elements_la_LDFLAGS = \
	-module \
	-shared \
	-avoid-version \
	-lboost_python-py32 \
	-lpython3.2mu \
	-fpic \
	-rpath /home/mog/

elements_la_SOURCES = \
	src/python/matrice.cpp

