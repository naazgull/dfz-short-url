/*
Copyright (c) 2016
*/

#include <dfz/short-url/short-url.h>

extern "C" void restify(zpt::EventEmitterPtr _emitter) {
	// See short-url.lambda.cpp and short-url.oo.cpp for examples on 
	// how to create endpoints with lambda pattern and object-oriented pattern, respectively.
	
	// Setup a Redis connection
	zpt::KBPtr _kb(new zpt::redis::Client(_emitter->options(), "redis.short-url"));
	_emitter->add_kb("redis.short-url", _kb);

	_emitter->on(zpt::rest::url_pattern({ _emitter->version(), "{collection-name}" }),
		{
			{
				zpt::ev::Get,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get Redis connection
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

					return {
						"status", 200,
						"payload", {
							"text", "some response"
						}
					};
				}
			},
			{
				zpt::ev::Post,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get Redis connection
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

					return {
						"status", 200,
						"payload", {
							"text", "some response"
						}
					};
				}
			},
			{
				zpt::ev::Head,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get Redis connection
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

					return {
						"status", 200,
						"headers", {
							"Content-Length", 24
						}
					};
				}
			}
		}
	);

	_emitter->on(zpt::rest::url_pattern({ _emitter->version(), "{collection-name}", "([^/]+)" }),
		{
			{
				zpt::ev::Get,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get Redis connection
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

					return {
						"status", 200,
						"payload", {
							"text", "some response"
						}
					};
				}
			},
			{
				zpt::ev::Put,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get Redis connection
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

					return {
						"status", 200,
						"payload", {
							"text", "some response"
						}
					};
				}
			},
			{
				zpt::ev::Delete,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get Redis connection
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

					return {
						"status", 200,
						"payload", {
							"text", "some response"
						}
					};
				}
			},
			{
				zpt::ev::Head,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get Redis connection
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

					return {
						"status", 200,
						"headers", {
							"Content-Length", 24
						}
					};
				}
			},
			{
				zpt::ev::Patch,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get Redis connection
					zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

					return {
						"status", 200,
						"payload", {
							"text", "some response"
						}
					};
				}
			}
		}
	);
}

