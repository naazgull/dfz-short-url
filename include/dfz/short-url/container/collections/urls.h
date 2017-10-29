#pragma once

#include <string>
#include <zapata/rest.h>
#include <dfz/short-url/container/datums/Urls.h>


using namespace std;
#if !defined __APPLE__
using namespace __gnu_cxx;
#endif

namespace dfz {
namespace short_url {
namespace collections {
namespace urls {

auto restify(zpt::ev::emitter _emitter) -> void;
}
}
}
}


