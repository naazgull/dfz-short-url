
AC_PREREQ(2.59)
AC_INIT(dfz-short-url, 0.0.1-1yakkety1, n@zgul.me)

AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([.])

dnl Check for libraries
AC_HAVE_LIBRARY(dl)
AC_HAVE_LIBRARY(pthread)
AC_HAVE_LIBRARY(magic)
AC_HAVE_LIBRARY(z)
AC_HAVE_LIBRARY(ssl)
AC_HAVE_LIBRARY(crypto)
AC_CHECK_LIB(zapata-base, zpt_base)
AC_CHECK_LIB(zapata-json, zpt_json)
AC_CHECK_LIB(zapata-events, zpt_events)
AC_CHECK_LIB(zapata-zmq, zpt_zmq)
AC_CHECK_LIB(zapata-http, zpt_http)
AC_CHECK_LIB(zapata-lisp, zpt_lisp)
AC_CHECK_LIB(zapata-python, zpt_python)
AC_CHECK_LIB(zapata-rest, zpt_rest)
#AC_CHECK_LIB(zapata-postgresql, zpt_postgresql)
#AC_CHECK_LIB(zapata-mariadb, zpt_mariadb)
#AC_CHECK_LIB(zapata-mongodb, zpt_mongodb)
#AC_CHECK_LIB(zapata-redis, zpt_redis)

AC_CANONICAL_SYSTEM

dnl Create config.h header file
AH_TOP([#include <dfz/short-url/unconfig.h>])
AC_CONFIG_HEADERS([include/dfz/short-url/config.h])

dnl Initialize automake
AM_INIT_AUTOMAKE([subdir-objects tar-pax])

dnl this allows us specify individual liking flags for each target
AC_PROG_CXX
AM_PROG_CC_C_O 

dnl Initialize Libtool
LT_INIT

dnl Check if Libtool is present
dnl Libtool is used for building share libraries 
AC_PROG_LIBTOOL

AC_CONFIG_FILES(Makefile
		debian/Makefile
		etc/Makefile
                include/Makefile
		src/container/Makefile
		src/Makefile)
AC_OUTPUT
