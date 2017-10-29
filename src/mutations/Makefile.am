lib_LTLIBRARIES = libdfz-short-url-mutations.la

libdfz_short_url_mutations_la_LIBADD = -lpthread -lzapata-base -lzapata-json -lzapata-http -lzapata-events -lzapata-zmq -lzapata-rest  -lzapata-couchdb -lzapata-mysql
libdfz_short_url_mutations_la_LDFLAGS = -version-info 0:1:0
libdfz_short_url_mutations_la_CPPFLAGS = -O3 -std=c++14 -I../../include

libdfz_short_url_mutations_la_SOURCES = \
../container/mutations/Urls.cpp \
./api.cpp

