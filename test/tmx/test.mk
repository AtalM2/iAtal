check_PROGRAMS += tmx_tests

tmx_tests_CXXFLAGS =	\
	$(CPPUNIT_CFLAGS)	\
	$(AM_CXXFLAGS)		\
	$(NULL)

tmx_tests_LDFLAGS =		\
	$(CPPUNIT_LIBS)		\
	$(AM_LDFLAGS)		\
	$(NULL)

tmx_test_CPPFLAGS =		\
	$(AM_CPPFLAGS)		\
	$(NULL)

tmx_tests_SOURCES =				\
	test/tmx/main.cc			\
	$(NULL)
