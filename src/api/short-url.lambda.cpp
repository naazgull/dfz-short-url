/*
Copyright (c) 2016
*/

#include <short-url/short-url.h>

extern "C" void restify(zpt::EventEmitterPtr _emitter) {
	// Setup a MongoDB connection
	// zpt::KBPtr _kb(new zpt::mongodb::Client(_emitter->options(), "mongodb.short-url"));
	// _emitter->add_kb("mongodb.short-url", _kb);
	
	// Setup a Redis connection
	// zpt::KBPtr _kb(new zpt::redis::Client(_emitter->options(), "redis.short-url"));
	// _emitter->add_kb("redis.short-url", _kb);
	

	_emitter->on(zpt::rest::url_pattern({ "{api-version}", "{collection-name}" }),
		{
			{
				zpt::ev::Get,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get MongoDB connection
					// zpt::mongodb::Client* _db = (zpt::mongodb::Client*) _emitter->get_kb("mongodb.short-url").get();

					// Get Redis connection
					// zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

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
					// Get MongoDB connection
					// zpt::mongodb::Client* _db = (zpt::mongodb::Client*) _emitter->get_kb("mongodb.short-url").get();

					// Get Redis connection
					// zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

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
					// Get MongoDB connection
					// zpt::mongodb::Client* _db = (zpt::mongodb::Client*) _emitter->get_kb("mongodb.short-url").get();

					// Get Redis connection
					// zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

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

	_emitter->on(zpt::rest::url_pattern({ "{api-version}", "{collection-name}", "([^/]+)" }),
		{
			{
				zpt::ev::Get,
				[] (zpt::ev::performative _performative, std::string _resource, zpt::json _envelope, zpt::ev::emitter _emitter) -> zpt::json {
					// Get MongoDB connection
					// zpt::mongodb::Client* _db = (zpt::mongodb::Client*) _emitter->get_kb("mongodb.short-url").get();

					// Get Redis connection
					// zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

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
					// Get MongoDB connection
					// zpt::mongodb::Client* _db = (zpt::mongodb::Client*) _emitter->get_kb("mongodb.short-url").get();

					// Get Redis connection
					// zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

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
					// Get MongoDB connection
					// zpt::mongodb::Client* _db = (zpt::mongodb::Client*) _emitter->get_kb("mongodb.short-url").get();

					// Get Redis connection
					// zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

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
					// Get MongoDB connection
					// zpt::mongodb::Client* _db = (zpt::mongodb::Client*) _emitter->get_kb("mongodb.short-url").get();

					// Get Redis connection
					// zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

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
					// Get MongoDB connection
					// zpt::mongodb::Client* _db = (zpt::mongodb::Client*) _emitter->get_kb("mongodb.short-url").get();

					// Get Redis connection
					// zpt::redis::Client* _db = (zpt::redis::Client*) _emitter->get_kb("redis.short-url").get();

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

