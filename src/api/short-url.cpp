/*
Copyright (c) 2016
*/

#include <dfz/short-url/short-url.h>

extern "C" void restify(zpt::EventEmitterPtr _emitter) {	
	// Setup a Redis connection
	zpt::KBPtr _kb(new zpt::redis::Client(_emitter->options(), "redis.short-url"));
	_emitter->add_kb("redis.short-url", _kb);

	_emitter->on(zpt::rest::url_pattern({ _emitter->version(), "short-urls" }),
		{
			{
				zpt::ev::Get,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					zpt::json _list;

					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();
					_list = _db->query("short-urls", (!_envelope["payload"]->ok() || _envelope["payload"]->obj()->size() == 0 ? std::string("*") : std::string("*") + ((std::string) _envelope["payload"]->obj()->begin()->second) + std::string("*")));
					
					if (!_list->ok() || _list["size"] == 0) {
					 	return { "status", 204 };
					}
					return {
						"status", 200,
						"payload", _list
					};
				}
			},
			{
				zpt::ev::Post,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					assertz(
						_envelope["payload"]->ok() &&
						_envelope["payload"]["target"]->ok(),
						"required fields: 'target'", 412, 0);
					assertz(
						_envelope["payload"]["target"]->type() == zpt::JSString,
						"invalid field type: 'target' must be a string", 400, 0);

					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();
					std::string _id;
					std::string _href;
					std::string _url;
					
					do {
						zpt::generate_key(_id, 8);
						_href.assign(_resource + (_resource.back() != '/' ? std::string("/") : std::string("")) + _id);
						_url.assign(_emitter->options()["prefix"]->str() + (_emitter->options()["prefix"]->str().back() != '/' ? std::string("/") : std::string("")) + _id);
					}
					while(_db->get("short-urls", _href)->ok());
					
					_envelope["payload"] << "id" << _id << "url" << _url;
					_id = _db->insert("short-urls", _resource, _envelope["payload"]);
					
					return {
						"status", 200,
						"payload", {
							"id", _id,
							"url", _url,
							"href", _href
						}
					};
				}
			},
			{
				zpt::ev::Head,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					zpt::json _list;
					
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();
					_list = _db->query("short-urls", (!_envelope["payload"]->ok() || _envelope["payload"]->obj()->size() == 0 ? std::string("*") : std::string("*") + ((std::string) _envelope["payload"]->obj()->begin()->second) + std::string("*")));
					
					if (!_list->ok()) {
					 	return { "status", 204 };
					}
					return {
						"status", 200,
						"headers", {
							"Content-Length", ((std::string) _list).length()
						}
					};
				}
			}
		}
	);

	_emitter->on(zpt::rest::url_pattern({ _emitter->version(), "short-urls", "([^/]+)" }),
		{
			{
				zpt::ev::Get,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					zpt::json _document;

					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();
					_document = _db->get("short-urls", _resource);
					if (!_document->ok()) {
						return { "status", 404 };
					}
					
					return {
						"status", 200,
						"payload", _document
					};
				}
			},
			{
				zpt::ev::Put,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					assertz(
						_envelope["payload"]->ok() &&
						_envelope["payload"]["a"]->ok() &&
						_envelope["payload"]["b"]->ok() &&
						_envelope["payload"]["b"]->ok(),
						"required fields: 'a', 'b' and 'c'", 412, 0);
					assertz(
						_envelope["payload"]["c"]->type() == zpt::JSArray,
						"invalid field type: 'c' must be a list of strings", 400, 0);

					size_t _size = 0;
					
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();
					_size = _db->save("short-urls", _resource, _envelope["payload"]);
					
					return {
						"status", 200,
						"payload", {
							"updated", _size
						}
					};
				}
			},
			{
				zpt::ev::Delete,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					size_t _size = 0;

					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();
					_size = _db->remove("short-urls", _resource);

					return {
						"status", 200,
						"payload", {
							"removed", _size
						}
					};
				}
			},
			{
				zpt::ev::Head,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					zpt::json _document;

					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();
					_document = _db->get("short-urls", _resource);
					if (!_document->ok()) {
						return { "status", 404 };
					}
					
					return {
						"status", 200,
						"headers", {
							"Content-Length", ((std::string) _document).length()
						}
					};
				}
			},
			{
				zpt::ev::Patch,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					size_t _size = 0;

					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();
					_size = _db->set("short-urls", _resource, _envelope["payload"]);

					return {
						"status", 200,
						"payload", {
							"updated", _size
						}
					};
				}
			}
		}
	);

	_emitter->on(zpt::rest::url_pattern({ _emitter->version(), "short-urls", "get", "([^/]+)" }),
		{
			{
				zpt::ev::Get,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();
					zpt::replace(_resource, "/get", "");
					zpt::json _url;
					if ((_url = _db->get("short-urls", _resource))->ok()) {
						return {
							"status", 301,
							"headers", {
								"Location", _url["target"]
							}
						};
					}
					
					return {
						"status", 404
					};
				}
			}
		}
	);

}

