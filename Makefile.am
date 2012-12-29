## Process this file with automake to produce Makefile.in

SUBDIRS = src po

evince_hwpdocdir = ${prefix}/share/doc/evince-hwp
evince_hwpdoc_DATA = \
	README    \
	COPYING   \
	AUTHORS   \
	ChangeLog \
	INSTALL   \
	NEWS

INTLTOOL_FILES = intltool-extract.in \
	intltool-merge.in \
	intltool-update.in

EXTRA_DIST = $(evince_hwpdoc_DATA) \
	$(INTLTOOL_FILES)

DISTCLEANFILES = intltool-extract \
	intltool-merge \
	intltool-update \
	po/.intltool-merge-cache

# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(evince_hwpdocdir)
