bin_PROGRAMS += \
	model		\
	$(NULL)

model_SOURCES =			\
	src/model/main.cc	\
	src/model/map.cc	\
	src/model/layer.cc	\
	src/model/tileset.cc \
	$(NULL)

model_CPPFLAGS =		\
	$(gtk_CFLAGS)		\
	$(NULL)

model_LDFLAGS = \
	$(gtk_LIBS) \
	$(NULL)
