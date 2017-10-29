#include <dfz/short-url/container/collections/urls.h>

auto dfz::short_url::collections::urls::restify(zpt::ev::emitter _emitter) -> void {
_emitter->on("^/1.0/urls$",
{
{ zpt::ev::Get,
[] (zpt::ev::performative _performative, std::string _topic, zpt::json _envelope, zpt::ev::emitter _emitter) -> void {

zpt::json _t_split = zpt::split(_topic, "/");
zpt::json _identity = zpt::rest::authorization::validate("/1.0/urls", _envelope, _emitter);

zpt::json _r_body;
_r_body = dfz::short_url::datums::Urls::query(_topic, _envelope["params"], _emitter, _identity, _envelope);

_emitter->reply(_envelope, { "status", (_r_body->ok() ? 200 : 204), "payload", _r_body });

}
}
,
{ zpt::ev::Post,
[] (zpt::ev::performative _performative, std::string _topic, zpt::json _envelope, zpt::ev::emitter _emitter) -> void {
assertz_mandatory(_envelope["payload"], "method", 412);
assertz_ascii(_envelope["payload"], "method", 412);
assertz_complex(_envelope["payload"], "params", 412);

zpt::json _t_split = zpt::split(_topic, "/");
zpt::json _identity = zpt::rest::authorization::validate("/1.0/urls", _envelope, _emitter);

zpt::json _r_body;
_r_body = dfz::short_url::datums::Urls::insert(_topic, _envelope["payload"], _emitter, _identity, _envelope);

_emitter->reply(_envelope, { "status", 201, "payload", _r_body });

}
}

,
{ zpt::ev::Patch,
[] (zpt::ev::performative _performative, std::string _topic, zpt::json _envelope, zpt::ev::emitter _emitter) -> void {
assertz_ascii(_envelope["payload"], "method", 412);
assertz_complex(_envelope["payload"], "params", 412);

zpt::json _t_split = zpt::split(_topic, "/");
zpt::json _identity = zpt::rest::authorization::validate("/1.0/urls", _envelope, _emitter);

zpt::json _r_body;
_r_body = dfz::short_url::datums::Urls::set(_topic, _envelope["payload"], _envelope["params"], _emitter, _identity, _envelope);

_emitter->reply(_envelope, { "status", 200, "payload", _r_body });

}
}
,
{ zpt::ev::Delete,
[] (zpt::ev::performative _performative, std::string _topic, zpt::json _envelope, zpt::ev::emitter _emitter) -> void {

zpt::json _t_split = zpt::split(_topic, "/");
zpt::json _identity = zpt::rest::authorization::validate("/1.0/urls", _envelope, _emitter);

zpt::json _r_body;
_r_body = dfz::short_url::datums::Urls::remove(_topic, _envelope["params"], _emitter, _identity, _envelope);

_emitter->reply(_envelope, { "status", 200, "payload", _r_body });

}
}
,
{ zpt::ev::Head,
[] (zpt::ev::performative _performative, std::string _topic, zpt::json _envelope, zpt::ev::emitter _emitter) -> void {

zpt::json _t_split = zpt::split(_topic, "/");
zpt::json _identity = zpt::rest::authorization::validate("/1.0/urls", _envelope, _emitter);

zpt::json _r_body;
_r_body = dfz::short_url::datums::Urls::query(_topic, _envelope["params"], _emitter, _identity, _envelope);

_emitter->reply(_envelope, { "status", (_r_body->ok() ? 200 : 204) });

}
}

},
{"0mq", true,"amqp", true,"http", true}
);
}

