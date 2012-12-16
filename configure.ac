#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])

AC_INIT([iAtal],
        [0.1],
        [m1infoatal+bugreport@sympa.etu.univ-nantes.prive])
AC_CONFIG_SRCDIR([src/ui/main.cc])
AC_CONFIG_HEADERS([config.h])
AM_INIT_AUTOMAKE([subdir-objects])
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
   DEBUG_CXXFLAGS="-ggdb -Wall -Wextra -Wstrict-null-sentinel -Wno-non-template-friend -Wno-pmf-conversions -Wsign-promo -Werror"
   AC_SUBST(DEBUG_CXXFLAGS)
fi

# CPPUNIT configuration
m4_pattern_allow([AM_PATH_CPPUNIT])
PKG_CHECK_MODULES([cppunit], [cppunit >= 1.12.1],
                  [HAVE_CPPUNIT=yes
                  AM_PATH_CPPUNIT],
                  [HAVE_CPPUNIT=no
                  AC_MSG_WARN([CPPUNIT not found. You won't be able to run the tests suites.])])
AM_CONDITIONAL([HAVE_CPPUNIT], [test "x$HAVE_CPPUNIT" = "xyes"])

# Python configuration
AC_ARG_WITH([python-3.2], AS_HELP_STRING([--with-python-3.2], [Use python-3.2 instead of python-2.7 if both are present]),
            [force_py32=yes], [force_py32=no])

m4_pattern_allow([AM_PATH_PYTHON])
if test "x$force_py32" = "xyes"; then
  PKG_CHECK_MODULES([python], [python-3.2 >= 3.2],
    [PYTHON_VERSION="3.2"],
    [AC_MSG_WARN([You've ask to use Python-3.2 but it can not be found.])])
fi

AS_IF([test "x$PYTHON_VERSION" != "x3.2"],
  [PKG_CHECK_MODULES([python], [python2 >= 2.7],
    [PYTHON_VERSION="2.7"],
    [PKG_CHECK_MODULES([python], [python-3.2 >= 3.2],
      [PYTHON_VERSION="3.2"],
      [AC_MSG_ERROR([Neither Python-2.7 or Python-3.2 have been found.])])])])
      
AC_MSG_RESULT([using Python-$PYTHON_VERSION])
if test "x$PYTHON_VERSION" = "x3.2"; then
  PYTHON_LDFLAGS=-lboost_python-py32
else
  PYTHON_LDFLAGS=-lboost_python
fi
AC_SUBST(PYTHON_LDFLAGS)

# Boost configuration
# https://github.com/tsuna/boost.m4/
BOOST_REQUIRE
BOOST_PYTHON
BOOST_STRING_ALGO
BOOST_CONVERSION
BOOST_PROGRAM_OPTIONS

# Doxygen configuration
DX_INIT_DOXYGEN([iatal], docs/doxygen.cfg)

AC_CONFIG_FILES([Makefile])
AC_OUTPUT
AM_PROG_LIBTOOL
