check_PROGRAMS += tmx3_tests

tmx3_tests_CXXFLAGS =	\
	$(CPPUNIT_CFLAGS)	\
	$(AM_CXXFLAGS)		\
	$(NULL)

tmx3_tests_LDFLAGS =	\
	$(CPPUNIT_LIBS)		\
	$(AM_LDFLAGS)		\
	$(NULL)

tmx3_test_CPPFLAGS =	\
	$(AM_CPPFLAGS)		\
	$(NULL)

tmx3_tests_SOURCES =			\
	test/tmx3/main.cc			\
	test/tmx3/parserTest.cc		\
	src/tmx3/layer.cc			\
	src/tmx3/map.cc				\
	src/tmx3/parser.cc			\
	src/tmx3/tile.cc			\
	src/tmx3/tileset.cc			\
	src/tmx3/tinyxml2.cc		\
	$(NULL)
