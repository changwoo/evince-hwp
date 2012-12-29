## Process this file with automake to produce Makefile.in

SUBDIRS = src 

evince_hwpdocdir = ${prefix}/share/doc/evince-hwp
evince_hwpdoc_DATA = \
    README    \
    COPYING   \
    AUTHORS   \
    ChangeLog \
    INSTALL   \
    NEWS


EXTRA_DIST = $(evince_hwpdoc_DATA)


# Remove doc directory on uninstall
uninstall-local:
	-rm -r $(evince_hwpdocdir)
