check_PROGRAMS += python_tests

python_tests_CXXFLAGS =	\
	$(CPPUNIT_CFLAGS)	\
	$(NULL)

python_tests_LDFLAGS =	\
	$(CPPUNIT_LIBS)		\
	$(NULL)

python_tests_SOURCES =			\
	test/python/main.cpp		\
	$(NULL)
