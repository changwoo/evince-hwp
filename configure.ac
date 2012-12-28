dnl Process this file with autoconf to produce a configure script.

AC_INIT(evince_hwp, 0.1)

AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CC

AC_DISABLE_STATIC
LT_INIT


PKG_CHECK_MODULES(EVINCE_HWP, [ghwp-0.1 evince-document-3.0])

GETTEXT_PACKAGE=evince
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE],["$GETTEXT_PACKAGE"],[Gettext package])


AC_SUBST([backenddir],"/usr/lib/evince/4/backends")

BACKEND_CFLAGS="$BACKEND_CFLAGS -DGDK_MULTIHEAD_SAFE -DGTK_MULTIHEAD_SAFE"
AC_SUBST(BACKEND_CFLAGS)

BACKEND_LIBTOOL_FLAGS="-module -avoid-version -no-undefined -export-symbols \$(top_srcdir)/src/backend.symbols"
AC_SUBST(BACKEND_LIBTOOL_FLAGS)



AC_OUTPUT([
    Makefile
    src/Makefile
])