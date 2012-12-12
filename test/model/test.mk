check_PROGRAMS += model_tests

model_tests_CXXFLAGS =	\
	$(CPPUNIT_CFLAGS)	\
	$(NULL)

model_tests_LDFLAGS =	\
	$(CPPUNIT_LIBS)		\
	$(NULL)

model_tests_SOURCES =	\
	test/model/main.cc	\
	$(NULL)
