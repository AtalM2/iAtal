check_PROGRAMS += ui_tests

ui_tests_CXXFLAGS =		\
	$(CPPUNIT_CFLAGS)	\
	$(NULL)

ui_tests_LDFLAGS =		\
	$(CPPUNIT_LIBS)		\
	$(NULL)

ui_tests_SOURCES =		\
	test/ui/main.cc		\
	$(NULL)
