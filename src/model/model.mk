bin_PROGRAMS += \
	model		\
	$(NULL)

model_SOURCES =			\
	src/model/main.cc	\
	src/model/map.cc	\
	src/model/layer.cc	\
	src/model/tileset.cc \
	src/model/model.cc \
	$(NULL)

model_CXXFLAGS = \
	$(AM_CXXFLAGS) \
	$(NULL)
