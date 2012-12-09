lib_LTLIBRARIES +=		\
	elements.la			\
	$(NULL)

elements_la_CPPFLAGS =	\
	$(python_CFLAGS)	\
    $(BOOST_CPPFLAGS)	\
	$(NULL)

elements_la_LDFLAGS =			\
	$(python_LIBS)				\
	-module						\
	-shared						\
	-avoid-version				\
	$(BOOST_PYTHON_LDFLAGS)		\
	$(NULL)

elements_la_SOURCES =			\
	src/python/matrice.cpp		\
	$(NULL)
