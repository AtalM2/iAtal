#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])

AC_INIT([iAtal],
        [0.1],
        [m1infoatal+bugreport@sympa.etu.univ-nantes.prive])
AC_CONFIG_SRCDIR([src/main.cc])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE

AC_LANG([C++])

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC

# Checks for libraries.
PKG_CHECK_MODULES([iAtal], [gtkmm-3.0 >= 3.0.0])

# Checks for header files.
AC_HEADER_STDBOOL

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

# Turn on debugging flags by default
AC_MSG_CHECKING([whether to deactivate debug])
AC_ARG_ENABLE([nodebug],
              AS_HELP_STRING([--enable-nodebug],
                             [Deactivate debug]),
              [nodebug=$enableval
              AC_MSG_RESULT([$enableval])],
              [nodebug=no
              AC_MSG_RESULT([no])])
if test "x$nodebug" = "xno"; then
   DEBUG_CXXFLAGS="-g -Wall -Wextra -Wstrict-null-sentinel -Wno-non-template-friend -Wno-pmf-conversions -Wsign-promo -Werror"
   AC_SUBST(DEBUG_CXXFLAGS)
fi


AC_CONFIG_FILES([Makefile])
AC_OUTPUT
