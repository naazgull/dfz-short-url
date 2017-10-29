create table Urls (
	id varchar(512) not null,
	created timestamp not null,
	updated timestamp not null,
	href varchar(1024) not null,
	method varchar(128) not null,
	params json ,
	primary key(id)
);



