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
	src/python/matrice.cc		\
	$(NULL)

bin_PROGRAMS +=	\
	test_python	\
	$(NULL)

test_python_SOURCES =			\
	src/python/main.cc			\
	src/python/matrice.cc		\
	$(NULL)

test_python_CPPFLAGS =	\
	$(python_CFLAGS)	\
	$(BOOST_CPPFLAGS)	\
	$(NULL)

test_python_LDFLAGS =			\
	$(python_LIBS)				\
	$(BOOST_PYTHON_LDFLAGS)		\
	-lboost_python-py32			\
	$(NULL)
