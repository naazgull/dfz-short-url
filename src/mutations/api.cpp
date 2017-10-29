#include <zapata/rest.h>
#include <string>
#include <dfz/short-url/container/mutations/Urls.h>
#include <zapata/couchdb.h>
#include <zapata/mysql.h>


using namespace std;
#if !defined __APPLE__
using namespace __gnu_cxx;
#endif

extern "C" void _zpt_load_() {
zpt::ev::emitter _emitter = zpt::emitter< zpt::rest::emitter >();


_emitter->connector({ { "dbms.couchdb.dfz.short_url", zpt::connector(new zpt::couchdb::Client(_emitter->options(), "couchdb.dfz.short_url")) }, { "dbms.mysql.dfz.short_url", zpt::connector(new zpt::mysql::Client(_emitter->options(), "mysql.dfz.short_url")) }, });
dfz::short_url::mutations::Urls::mutify(_emitter);

}

