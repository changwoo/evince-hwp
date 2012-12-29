dnl Process this file with autoconf to produce a configure script.

AC_INIT(evince_hwp, 0.1.1)

AC_CONFIG_HEADERS([config.h])

AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([1.11])

AM_SILENT_RULES([yes])

AC_PROG_CC

LT_INIT([dlopen disable-static])

dnl ***************************************************************************
dnl Internationalization
dnl ***************************************************************************
IT_PROG_INTLTOOL([0.35.0])

GETTEXT_PACKAGE=evince-hwp
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE],["$GETTEXT_PACKAGE"],[Gettext package])
AM_GLIB_GNU_GETTEXT

m4_pattern_allow([AM_V_GEN]) dnl Make autoconf not complain about the rule below
EV_INTLTOOL_EVINCE_BACKEND_RULE='%.evince-backend:   %.evince-backend.in   $(INTLTOOL_MERGE) $(wildcard $(top_srcdir)/po/*.po) ; $(AM_V_GEN) LC_ALL=C $(INTLTOOL_MERGE) -d -u -c $(top_builddir)/po/.intltool-merge-cache $(top_srcdir)/po $< [$]@'
AC_SUBST([EV_INTLTOOL_EVINCE_BACKEND_RULE])

PKG_CHECK_MODULES(EVINCE_HWP, [ghwp-0.1 evince-document-3.0])

AC_SUBST([backenddir], "/usr/lib/evince/4/backends")

BACKEND_CFLAGS="$BACKEND_CFLAGS -DGDK_MULTIHEAD_SAFE -DGTK_MULTIHEAD_SAFE"
AC_SUBST(BACKEND_CFLAGS)

BACKEND_LIBTOOL_FLAGS="-module -avoid-version -no-undefined -export-symbols \$(top_srcdir)/src/backend.symbols"
AC_SUBST(BACKEND_LIBTOOL_FLAGS)

AC_OUTPUT([
    Makefile
    src/Makefile
    po/Makefile.in
])
