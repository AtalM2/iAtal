check_PROGRAMS += tmx_tests

tmx_tests_CXXFLAGS =	\
	$(CPPUNIT_CFLAGS)	\
	$(NULL)

tmx_tests_LDFLAGS =		\
	$(CPPUNIT_LIBS)		\
	$(NULL)

tmx_tests_SOURCES =		\
	test/tmx/main.cpp	\
	$(NULL)
