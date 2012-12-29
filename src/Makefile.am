## Process this file with automake to produce Makefile.in

backend_LTLIBRARIES = libhwpdocument.la

libhwpdocument_la_SOURCES = \
	hwp-document.c          \
	hwp-document.h

libhwpdocument_la_CPPFLAGS =               \
	-DGNOMELOCALEDIR=\"$(datadir)/locale\" \
	$(AM_CPPFLAGS)

libhwpdocument_la_CFLAGS = \
	-Wall                  \
	$(EVINCE_HWP_CFLAGS)   \
	$(AM_CFLAGS)

libhwpdocument_la_LDFLAGS = $(BACKEND_LIBTOOL_FLAGS)
libhwpdocument_la_LIBADD = $(EVINCE_HWP_LIBS)

backend_in_files = hwpdocument.evince-backend.in
backend_DATA = $(backend_in_files:.evince-backend.in=.evince-backend)

EXTRA_DIST =        \
	backend.symbols \
	$(backend_in_files)

CLEANFILES = $(backend_DATA)

@EV_INTLTOOL_EVINCE_BACKEND_RULE@