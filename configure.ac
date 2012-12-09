#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])

AC_INIT([iAtal],
        [0.1],
        [m1infoatal+bugreport@sympa.etu.univ-nantes.prive])
AC_CONFIG_SRCDIR([src/ui/main.cc])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE
m4_ifdef([AM_SILENT_RULES], [AM_SILENT_RULES([yes])])
LT_INIT
AC_CONFIG_MACRO_DIR([m4])

AC_LANG([C++])

# Checks for programs.
AC_PROG_CXX
AC_PROG_AWK
AC_PROG_CC
AC_PROG_CPP
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL

# Checks for libraries.
PKG_CHECK_MODULES([gtk], [gtkmm-3.0 >= 3.0.0])
PKG_CHECK_MODULES([python], [python-3.2 >= 3.2])

# Checks for header files.
AC_CHECK_HEADERS([limits.h stddef.h stdlib.h string.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_HEADER_STDBOOL
AC_C_INLINE
AC_TYPE_SIZE_T
AC_CHECK_TYPES([ptrdiff_t])

# Checks for library functions.
AC_CHECK_FUNCS([memset strchr])

# Turn on debugging flags by default
AC_MSG_CHECKING([whether to deactivate debug])
AC_ARG_ENABLE([nodebug],
              AS_HELP_STRING([--disable-debug],
                             [Deactivate debug]),
              [nodebug=$enableval
              AC_MSG_RESULT([$enableval])],
              [nodebug=no
              AC_MSG_RESULT([no])])
if test "x$nodebug" = "xno"; then
   DEBUG_CXXFLAGS="-g -Wall -Wextra -Wstrict-null-sentinel -Wno-non-template-friend -Wno-pmf-conversions -Wsign-promo -Werror"
   AC_SUBST(DEBUG_CXXFLAGS)
fi

# Boost configuration
BOOST_REQUIRE
BOOST_PYTHON

# CPPUNIT configuration
AM_PATH_CPPUNIT

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
AM_PROG_LIBTOOL

