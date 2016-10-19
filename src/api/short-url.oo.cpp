/*
Copyright (c) 2016
*/

#include <short-url/short-url.h>

class CollectionListener : public zpt::EventListener {
public:
	inline CollectionListener() : zpt::EventListener(zpt::rest::url_pattern({ "{api-version}", "{collection-name}" })) {
	}
	inline virtual ~CollectionListener() {
	}

	inline virtual zpt::json get(std::string _resource, zpt::json _envelope, zpt::EventEmitterPtr _emitter) {
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

	inline virtual zpt::json post(std::string _resource, zpt::json _envelope, zpt::EventEmitterPtr _emitter) {
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

	inline virtual zpt::json head(std::string _resource, zpt::json _envelope, zpt::EventEmitterPtr _emitter) {
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
};

class DocumentListener : public zpt::EventListener {
public:
	inline DocumentListener() : zpt::EventListener(zpt::rest::url_pattern({ "{api-version}", "{collection-name}", "([^/]+)" })) {
	}
	inline virtual ~DocumentListener() {
	}

	inline virtual zpt::json get(std::string _resource, zpt::json _envelope, zpt::EventEmitterPtr _emitter) {
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

	inline virtual zpt::json put(std::string _resource, zpt::json _envelope, zpt::EventEmitterPtr _emitter) {
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

	inline virtual zpt::json head(std::string _resource, zpt::json _envelope, zpt::EventEmitterPtr _emitter) {
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

	inline virtual zpt::json del(std::string _resource, zpt::json _envelope, zpt::EventEmitterPtr _emitter) {
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
};

class ControllerListener : public zpt::EventListener {
public:
	inline ControllerListener() : zpt::EventListener(zpt::rest::url_pattern({ "{api-version}", "{contoller-name}" }) {
	}
	inline virtual ~ControllerListener() {
	}

	inline virtual zpt::json post(std::string _resource, zpt::json _envelope, zpt::EventEmitterPtr _emitter) {
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
};

extern "C" void restify(zpt::EventEmitterPtr _emitter) {
	// Setup a MongoDB connection
	// zpt::KBPtr _kb(new zpt::mongodb::Client(_emitter->options(), "mongodb.short-url"));
	// _emitter->add_kb("mongodb.short-url", _kb);
	
	// Setup a Redis connection
	// zpt::KBPtr _kb(new zpt::redis::Client(_emitter->options(), "redis.short-url"));
	// _emitter->add_kb("redis.short-url", _kb);
	
	_emitter->on(zpt::ev::listener(new CollectionListener()));
	_emitter->on(zpt::ev::listener(new DocumentListener()));
	_emitter->on(zpt::ev::listener(new ControllerListener()));
}

