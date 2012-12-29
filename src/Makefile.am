## Process this file with automake to produce Makefile.in

backend_LTLIBRARIES = libhwpdocument.la

libhwpdocument_la_SOURCES = \
	hwp-document.c          \
	hwp-document.h

libhwpdocument_la_CPPFLAGS =               \
	-DGETTEXT_PACKAGE=\"evince\"           \
	-DGNOMELOCALEDIR=\"$(datadir)/locale\" \
	$(AM_CPPFLAGS)

libhwpdocument_la_CFLAGS = \
	-Wall                  \
	$(EVINCE_HWP_CFLAGS)   \
	$(AM_CFLAGS)

libhwpdocument_la_LDFLAGS = $(BACKEND_LIBTOOL_FLAGS)
libhwpdocument_la_LIBADD = $(EVINCE_HWP_LIBS)

backend_DATA = hwpdocument.evince-backend

EXTRA_DIST =        \
	backend.symbols \
	hwpdocument.evince-backend
