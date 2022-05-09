#include "databasemanager.h"
#include "electrikpokemon.h"
#include "firepokemon.h"
#include "plantpokemon.h"
#include "waterpokemon.h"
#include <iostream>
#include <QSqlQuery>

const QSqlDatabase &DatabaseManager::getItsDatabase() const
{
    return itsDatabase;
}

DatabaseManager::DatabaseManager()
{
    itsElectrikTypePokemons = new std::vector<Pokemon*>();
    itsWaterTypePokemons = new std::vector<Pokemon*>();
    itsFireTypePokemons = new std::vector<Pokemon*>();
    itsPlantTypePokemons = new std::vector<Pokemon*>();
}

bool DatabaseManager::connect()
{
    itsDatabase = QSqlDatabase::addDatabase("QSQLITE");
    itsDatabase.setDatabaseName("database.db");

    return itsDatabase.open();
}

void DatabaseManager::saveTrainer(QString name, std::vector<Pokemon *> *pokemons)
{
    QSqlQuery query;

    query.prepare("INSERT INTO trainers (name) VALUES (:name)");
    query.bindValue(":name", name);

    if (query.exec())
    {
        int id = query.lastInsertId().toInt();

        query.prepare("INSERT INTO trainers_pokemons (id_trainer, pokemon_name, pokemon_type) VALUES (:id_trainer, :pokemon_name, :pokemon_type)");

        for (Pokemon* pokemon : *pokemons)
        {
            query.bindValue(":id_trainer", id);
            query.bindValue(":pokemon_name", pokemon->getItsName());
            query.bindValue(":pokemon_type", pokemon->getItsType());
            query.exec();
        }
    }
}

void DatabaseManager::startQueries()
{
    QSqlQuery query;

    query.exec("SELECT * FROM fire_pokemons");
    while (query.next())
    {
        Pokemon* pokemon = new FirePokemon(
            query.value("name").toString(),
            query.value("size").toFloat(),
            query.value("weight").toFloat(),
            query.value("hp").toInt(),
            query.value("cp").toInt(),
            query.value("paws").toInt()
        );
        itsFireTypePokemons->push_back(pokemon);
    }

    query.exec("SELECT * FROM electrik_pokemons");
    while (query.next())
    {
        Pokemon* pokemon = new ElectrikPokemon(
            query.value("name").toString(),
            query.value("size").toFloat(),
            query.value("weight").toFloat(),
            query.value("hp").toInt(),
            query.value("cp").toInt(),
            query.value("paws").toInt(),
            query.value("intensity").toInt(),
            query.value("wings").toInt()
        );
        itsElectrikTypePokemons->push_back(pokemon);
    }

    query.exec("SELECT * FROM water_pokemons");
    while (query.next())
    {
        Pokemon* pokemon = new WaterPokemon(
            query.value("name").toString(),
            query.value("size").toFloat(),
            query.value("weight").toFloat(),
            query.value("hp").toInt(),
            query.value("cp").toInt(),
            query.value("fins").toInt()
        );
        itsWaterTypePokemons->push_back(pokemon);
    }

    query.exec("SELECT * FROM plant_pokemons");
    while (query.next())
    {
        Pokemon* pokemon = new PlantPokemon(
            query.value("name").toString(),
            query.value("size").toFloat(),
            query.value("weight").toFloat(),
            query.value("hp").toInt(),
            query.value("cp").toInt()
        );
        itsPlantTypePokemons->push_back(pokemon);
    }
}

std::vector<Pokemon *>* DatabaseManager::getPokemons() const
{
    std::vector<Pokemon *>* pokemons = new std::vector<Pokemon *>;

    pokemons->insert(pokemons->end(), itsFireTypePokemons->begin(), itsFireTypePokemons->end());
    pokemons->insert(pokemons->end(), itsPlantTypePokemons->begin(), itsPlantTypePokemons->end());
    pokemons->insert(pokemons->end(), itsElectrikTypePokemons->begin(), itsElectrikTypePokemons->end());
    pokemons->insert(pokemons->end(), itsWaterTypePokemons->begin(), itsWaterTypePokemons->end());

    return pokemons;
}

std::vector<Pokemon *> *DatabaseManager::getFireTypePokemons() const
{
    return itsFireTypePokemons;
}

std::vector<Pokemon *> *DatabaseManager::getElectrikTypePokemons() const
{
    return itsElectrikTypePokemons;
}

std::vector<Pokemon *> *DatabaseManager::getWaterTypePokemons() const
{
    return itsWaterTypePokemons;
}

std::vector<Pokemon *> *DatabaseManager::getPlantTypePokemons() const
{
    return itsPlantTypePokemons;
}
