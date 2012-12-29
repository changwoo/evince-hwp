dnl Process this file with autoconf to produce a configure script.

AC_INIT(evince_hwp, 0.1.1)

AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CC

LT_INIT([dlopen disable-static])

PKG_CHECK_MODULES(EVINCE_HWP, [ghwp-0.1 evince-document-3.0])

AC_SUBST([backenddir], "/usr/lib/evince/4/backends")

BACKEND_CFLAGS="$BACKEND_CFLAGS -DGDK_MULTIHEAD_SAFE -DGTK_MULTIHEAD_SAFE"
AC_SUBST(BACKEND_CFLAGS)

BACKEND_LIBTOOL_FLAGS="-module -avoid-version -no-undefined -export-symbols \$(top_srcdir)/src/backend.symbols"
AC_SUBST(BACKEND_LIBTOOL_FLAGS)

AC_OUTPUT([
    Makefile
    src/Makefile
])
