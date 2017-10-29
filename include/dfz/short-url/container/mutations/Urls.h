#pragma once

#include <string>
#include <zapata/rest.h>
#include <dfz/short-url/container/mutations/Urls.h>


using namespace std;
#if !defined __APPLE__
using namespace __gnu_cxx;
#endif

namespace dfz {
namespace short_url {
namespace mutations {
namespace Urls {

auto mutify(zpt::ev::emitter _emitter) -> void;
}
}
}
}


