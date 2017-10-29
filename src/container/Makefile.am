lib_LTLIBRARIES = libdfz-short-url.la

libdfz_short_url_la_LIBADD = -lpthread -lzapata-base -lzapata-json -lzapata-http -lzapata-events -lzapata-zmq -lzapata-rest  -lzapata-mysql -lzapata-couchdb
libdfz_short_url_la_LDFLAGS = -version-info 0:1:0
libdfz_short_url_la_CPPFLAGS = -O3 -std=c++14 -I../../include

libdfz_short_url_la_SOURCES = \
./datums/Urls.cpp \
./collections/urls.cpp \
./api.cpp

