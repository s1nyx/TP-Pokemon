CREATE TABLE fire_pokemons
(
	name TEXT NOT NULL,
	size REAL NOT NULL,
	weight REAL NOT NULL,
	hp INTEGER NOT NULL,
	cp INTEGER NOT NULL,
	paws INTEGER NOT NULL
);

INSERT INTO fire_pokemons
	(name, size, weight, hp, cp, paws)
VALUES
	('Salamèche', 0.6, 8.5, 39, 52, 4),
	('Reptincel', 1.1, 19.0, 58, 64, 2),
	('Dracaufeu', 1.7, 90.5, 78, 84, 2)
;

CREATE TABLE electrik_pokemons
(
	name TEXT NOT NULL,
	size REAL NOT NULL,
	weight REAL NOT NULL,
	hp INTEGER NOT NULL,
	cp INTEGER NOT NULL,
	paws INTEGER NOT NULL,
	intensity INTEGER NOT NULL,
	wings INTEGER NOT NULL
);

INSERT INTO electrik_pokemons
	(name, size, weight, hp, cp, paws, intensity, wings)
VALUES
	('Statitik', 0.1, 0.6, 50, 47, 4, 2, 0),
	('Mygavolt', 0.8, 14.3, 70, 77, 6, 6, 0),
	('Lucanon', 1.5, 45.0, 70, 70, 4, 6, 2)
;

CREATE TABLE plant_pokemons
(
	name TEXT NOT NULL,
	size REAL NOT NULL,
	weight REAL NOT NULL,
	hp INTEGER NOT NULL,
	cp INTEGER NOT NULL
);
INSERT INTO plant_pokemons
	(name, size, weight, hp, cp)
VALUES
	('Paras', 0.3, 5.4, 35, 70),
	('Cheniselle', 0.5, 6.5, 60, 59),
	('Manternel', 0.5, 6.5, 75, 103)
;

CREATE TABLE water_pokemons
(
	name TEXT NOT NULL,
	size REAL NOT NULL,
	weight REAL NOT NULL,
	hp INTEGER NOT NULL,
	cp INTEGER NOT NULL,
	fins INTEGER NOT NULL
);

INSERT INTO water_pokemons
	(name, size, weight, hp, cp, fins)
VALUES
	('Wailord', 14.5, 398.0, 170, 90, 4),
	('Milobellus', 6.2, 162.0, 95, 60, 1),
	('Kyogre', 4.5, 352.0, 100, 100, 2)
;