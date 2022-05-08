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
	('Salameche', 0.6, 8.5, 39, 52, 4),
	('Reptincel', 1.1, 19.0, 58, 64, 2),
	('Dracaufeu', 1.7, 90.5, 78, 84, 2),
	('Mega-Dracaufeu', 1.7, 100.5, 78, 104, 2),
	('Goupix', 0.6, 9.9, 38, 41, 4),
	('Feunard', 1.1, 19.9, 73, 76, 2),
	('Arcanin', 1.9, 155.0, 90, 110, 4),
	('Caninos', 0.7, 19.0, 55, 70, 4),
	('Ponyta', 1.0, 30.0, 50, 85, 4),
	('Galopa', 1.7, 95.0, 65, 100, 4)
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
	('Lucanon', 1.5, 45.0, 70, 70, 4, 6, 2),
	('Posipi', 0.4, 4.2, 60, 50, 2, 4, 0),
	('Luxray', 1.4, 42.0, 80, 120, 4, 10, 0),
	('Elekable', 1.8, 138.6, 75, 123, 2, 15, 0),
	('Arceus', 3.2, 320.0, 120, 120, 4, 30, 0),
	('Zebibron', 0.8, 29.8, 45, 60, 4, 5, 0),
	('Silvallie', 2.3, 100.5, 95, 95, 2, 6, 1),
	('Zeraora', 1.5, 44.5, 88, 112, 2, 8, 0)
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
	('Manternel', 0.5, 6.5, 75, 103),
	('Saquedeneu', 1.0, 35.0, 65, 55),
	('Fragilady', 1.1, 16.3, 70, 60),
	('Maracachi', 1.0, 28.0, 75, 86),
	('Marisson', 0.4, 9.0, 56, 51),
	('Boguerisse', 0.7, 29.0, 61, 78),
	('Cabriolaine', 0.9, 31.0, 66, 65),
	('Chevroum', 1.7, 91.0, 123, 100)
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
	('Kyogre', 4.5, 352.0, 100, 100, 2),
	('Flagadoss', 1.6, 78.5, 95, 75, 1),
	('Otaria', 1.1, 90.0, 65, 45, 2),
	('Lamantine', 1.7, 120.0, 90, 70, 2),
	('Kokiyas', 0.3, 4.0, 30, 65, 1),
	('Crustabri', 1.5, 132.5, 50, 95, 2),
	('Krabboss', 1.3, 60.0, 55, 130, 1),
	('Poissoroy', 1.3, 39.0, 80, 92, 2)
;

CREATE TABLE trainers 
(
	id INTEGER PRIMARY KEY AUTOINCREMENT,
	name TEXT NOT NULL
);

CREATE TABLE trainers_pokemons
(
	id_trainer INTEGER NOT NULL,
	pokemon_name TEXT NOT NULL,
	pokemon_type TEXT NOT NULL
);