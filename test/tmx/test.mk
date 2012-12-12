check_PROGRAMS += tmx_tests

tmx_tests_CXXFLAGS =	\
	$(CPPUNIT_CFLAGS)	\
	$(AM_CXXFLAGS)		\
	$(gtk_CFLAGS)		\
	$(NULL)

tmx_tests_LDFLAGS =		\
	$(CPPUNIT_LIBS)		\
	$(gtk_LIBS)			\
	$(NULL)

tmx_tests_SOURCES =				\
	test/tmx/main.cc			\
	test/tmx/utils_test.cc		\
	src/tmx/utils.cc			\
	$(NULL)
