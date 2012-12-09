lib_LTLIBRARIES += \
	elements.la \
	$(NULL)

elements_la_CPPFLAGS = \
	$(python_CFLAGS) \
	$(NULL)

elements_la_LDFLAGS = \
	$(python_LIBS) \
	-module \
	-shared \
	-avoid-version \
	-lboost_python-py32 \
	$(NULL)

elements_la_SOURCES = \
	src/python/matrice.cpp \
	$(NULL)
