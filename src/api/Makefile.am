lib_LTLIBRARIES = libdfz-short-url.la

libdfz_short_url_la_LIBADD = -lpthread -lzmq -lossp-uuid++ -lzapata-json -lzapata-http -lzapata-events -lzapata-addons -lzapata-zmq -lzapata-rest -lzapata-redis
libdfz_short_url_la_LDFLAGS = -version-info 1:0:0 
libdfz_short_url_la_CPPFLAGS = -std=c++11 -Wall -I../../include

libdfz_short_url_la_SOURCES = \
short-url.cpp
