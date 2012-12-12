bin_PROGRAMS += \
	ui \
	$(NULL)

ui_SOURCES = \
	src/ui/main.cc \
	src/ui/maparea.cc \
	src/ui/mapwindow.cc \
	src/tmx/utils.cc \
	$(NULL)

ui_CPPFLAGS = \
	$(gtk_CFLAGS) \
	$(NULL)

ui_LDFLAGS = \
	$(gtk_LIBS) \
	$(NULL)
