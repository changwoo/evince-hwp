## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = \
	-DPACKAGE_LOCALE_DIR=\""$(localedir)"\" \
	-DPACKAGE_SRC_DIR=\""$(srcdir)"\" \
	-DPACKAGE_DATA_DIR=\""$(pkgdatadir)"\" \
	-DGNOMELOCALEDIR=\"$(datadir)/locale\" \
	$(EVINCE_HWP_CFLAGS)

AM_CFLAGS =\
	$(BACKEND_CFLAGS) \
	-Wall

evince_hwpdir = $(backenddir)
evince_hwp_DATA = hwpdocument.evince-backend

evince_hwp_LTLIBRARIES = libhwpdocument.la


libhwpdocument_la_SOURCES = \
	hwp-document.c \
	hwp-document.h

libhwpdocument_la_LDFLAGS = $(BACKEND_LIBTOOL_FLAGS)

libhwpdocument_la_LIBADD = $(EVINCE_HWP_LIBS)


EXTRA_DIST = \
	$(evince_hwp_DATA)
