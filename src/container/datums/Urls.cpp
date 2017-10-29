#include <dfz/short-url/container/datums/Urls.h>

auto dfz::short_url::datums::Urls::get(std::string _topic, zpt::ev::emitter _emitter, zpt::json _identity, zpt::json _envelope) -> zpt::json {
	zpt::json _r_data;
	zpt::connector _c = _emitter->connector("dbms.couchdb.dfz.short_url");
_r_data = _c->get("Urls", _topic, { "href", _topic });

	return _r_data;
}

auto dfz::short_url::datums::Urls::query(std::string _topic, zpt::json _filter, zpt::ev::emitter _emitter, zpt::json _identity, zpt::json _envelope) -> zpt::json {
	zpt::json _r_data;
	zpt::connector _c = _emitter->connector("dbms.couchdb.dfz.short_url");
_r_data = _c->query("Urls", zpt::json(zpt::json::object() + _filter), _filter + zpt::json({ "href", _topic }));

	return _r_data;
}

auto dfz::short_url::datums::Urls::insert(std::string _topic, zpt::json _document, zpt::ev::emitter _emitter, zpt::json _identity, zpt::json _envelope) -> zpt::json {
	zpt::json _r_data;
	std::string _r_id = std::string(_document["id"]);
if (_r_id.length() == 0) {
_r_id.assign(zpt::generate::r_uuid());
_document << "id" << _r_id;
}
size_t _c_idx = 0;
zpt::json _c_names = { zpt::array, "dbms.mysql.dfz.short_url", "dbms.couchdb.dfz.short_url" };

_document <<
"created" << zpt::json::date() <<
"updated" << zpt::json::date();
assertz_mandatory(_document, "method", 412);
assertz_ascii(_document, "method", 412);
assertz_complex(_document, "params", 412);

for (auto _c_name : _c_names->arr()) {
zpt::connector _c = _emitter->connector(_c_name);
if (zpt::is_sql(std::string(_c_name))) {
_c->insert("Urls", _topic, _document, { "href", _topic, "fields", { zpt::array, "id", "href", "created", "updated", "method", "params" }, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });
}
else {

_c->insert("Urls", _topic, _document, { "href", _topic, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });
}
_c_idx++;
}
_r_data = { "id", _r_id, "href", (_topic + std::string("/") + _r_id) };

	return _r_data;
}

auto dfz::short_url::datums::Urls::save(std::string _topic, zpt::json _document, zpt::ev::emitter _emitter, zpt::json _identity, zpt::json _envelope) -> zpt::json {
	zpt::json _r_data;
	size_t _n_updated = 0;
size_t _c_idx = 0;
zpt::json _c_names = { zpt::array, "dbms.mysql.dfz.short_url", "dbms.couchdb.dfz.short_url" };

_document <<
"updated" << zpt::json::date();

for (auto _c_name : _c_names->arr()) {
zpt::connector _c = _emitter->connector(_c_name);
if (zpt::is_sql(std::string(_c_name))) {
_n_updated = _c->save("Urls", _topic, _document, { "href", _topic, "fields", { zpt::array, "id", "href", "created", "updated", "method", "params" }, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });
}
else {
_n_updated = _c->save("Urls", _topic, _document, { "href", _topic, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });
}
_c_idx++;
}

_r_data = { "href", _topic, "n_updated", _n_updated };

	return _r_data;
}

auto dfz::short_url::datums::Urls::set(std::string _topic, zpt::json _document, zpt::ev::emitter _emitter, zpt::json _identity, zpt::json _envelope) -> zpt::json {
	zpt::json _r_data;
	size_t _n_updated = 0;
size_t _c_idx = 0;
zpt::json _c_names = { zpt::array, "dbms.mysql.dfz.short_url", "dbms.couchdb.dfz.short_url" };

_document <<
"updated" << zpt::json::date();

for (auto _c_name : _c_names->arr()) {
zpt::connector _c = _emitter->connector(_c_name);
if (zpt::is_sql(std::string(_c_name))) {
_n_updated = _c->set("Urls", _topic, _document, { "href", _topic, "fields", { zpt::array, "id", "href", "created", "updated", "method", "params" }, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });
}
else {
_n_updated = _c->set("Urls", _topic, _document, { "href", _topic, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });
}
_c_idx++;
}

_r_data = { "href", _topic, "n_updated", _n_updated };

	return _r_data;
}

auto dfz::short_url::datums::Urls::set(std::string _topic, zpt::json _document, zpt::json _filter, zpt::ev::emitter _emitter, zpt::json _identity, zpt::json _envelope) -> zpt::json {
	zpt::json _r_data;
	size_t _n_updated = 0;
size_t _c_idx = 0;
zpt::json _c_names = { zpt::array, "dbms.mysql.dfz.short_url", "dbms.couchdb.dfz.short_url" };

_document <<
"updated" << zpt::json::date();

for (auto _c_name : _c_names->arr()) {
zpt::connector _c = _emitter->connector(_c_name);
if (zpt::is_sql(std::string(_c_name))) {
_n_updated = _c->set("Urls", zpt::json(zpt::json::object() + _filter), _document, { "href", _topic, "fields", { zpt::array, "id", "href", "created", "updated", "method", "params" }, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });}
else {
_n_updated = _c->set("Urls", zpt::json(zpt::json::object() + _filter), _document, { "href", _topic, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });}
_c_idx++;
}

_r_data = { "href", _topic, "n_updated", _n_updated };

	return _r_data;
}

auto dfz::short_url::datums::Urls::remove(std::string _topic, zpt::ev::emitter _emitter, zpt::json _identity, zpt::json _envelope) -> zpt::json {
	zpt::json _r_data;
	size_t _n_deleted = 0;
size_t _c_idx = 0;
zpt::json _c_names = { zpt::array, "dbms.mysql.dfz.short_url", "dbms.couchdb.dfz.short_url" };


for (auto _c_name : _c_names->arr()) {
zpt::connector _c = _emitter->connector(_c_name);
_n_deleted = _c->remove("Urls", _topic, { "href", _topic, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });_c_idx++;
}

_r_data = { "href", _topic, "n_deleted", _n_deleted };

	return _r_data;
}

auto dfz::short_url::datums::Urls::remove(std::string _topic, zpt::json _filter, zpt::ev::emitter _emitter, zpt::json _identity, zpt::json _envelope) -> zpt::json {
	zpt::json _r_data;
	size_t _n_deleted = 0;
size_t _c_idx = 0;
zpt::json _c_names = { zpt::array, "dbms.mysql.dfz.short_url", "dbms.couchdb.dfz.short_url" };


for (auto _c_name : _c_names->arr()) {
zpt::connector _c = _emitter->connector(_c_name);
_n_deleted = _c->remove("Urls", zpt::json(zpt::json::object() + _filter), { "href", _topic, "mutated-event", (_c_idx != _c_names->arr()->size() - 1) });_c_idx++;
}

_r_data = { "href", _topic, "n_deleted", _n_deleted };

	return _r_data;
}

