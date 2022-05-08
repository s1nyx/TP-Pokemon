#include "databasemanager.h"
#include "electrikpokemon.h"
#include "firepokemon.h"
#include "plantpokemon.h"
#include "waterpokemon.h"
#include <iostream>
#include <QSqlQuery>

DatabaseManager* DatabaseManager::itsInstance = nullptr;

const QSqlDatabase &DatabaseManager::getItsDatabase() const
{
    return itsDatabase;
}

DatabaseManager::DatabaseManager()
{
}

DatabaseManager *DatabaseManager::getItsInstance() const
{
    if (itsInstance == nullptr)
    {
        itsInstance = new DatabaseManager();
    }

    return itsInstance;
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

// TODO: clean pour que les queries soient faites 1 fois
std::vector<Pokemon *>* DatabaseManager::getPokemons() const
{
    std::vector<Pokemon *>* pokemons = new std::vector<Pokemon *>;

    std::vector<Pokemon *>* firePokemons = getFireTypePokemons();
    pokemons->insert(pokemons->end(), firePokemons->begin(), firePokemons->end());

    std::vector<Pokemon *>* plantPokemons = getPlantTypePokemons();
    pokemons->insert(pokemons->end(), plantPokemons->begin(), plantPokemons->end());

    std::vector<Pokemon *>* electrikPokemons = getElectrikTypePokemons();
    pokemons->insert(pokemons->end(), electrikPokemons->begin(), electrikPokemons->end());

    std::vector<Pokemon *>* waterPokemons = getWaterTypePokemons();
    pokemons->insert(pokemons->end(), waterPokemons->begin(), waterPokemons->end());

    return pokemons;
}

std::vector<Pokemon *> *DatabaseManager::getFireTypePokemons() const
{
    std::vector<Pokemon *>* pokemons = new std::vector<Pokemon *>;

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
        //pokemon->calculateSpeed();
        pokemons->push_back(pokemon);
    }

    return pokemons;
}

std::vector<Pokemon *> *DatabaseManager::getElectrikTypePokemons() const
{
    std::vector<Pokemon *>* pokemons = new std::vector<Pokemon *>;

    QSqlQuery query;
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
        //pokemon->calculateSpeed();
        pokemons->push_back(pokemon);
    }

    return pokemons;
}

std::vector<Pokemon *> *DatabaseManager::getWaterTypePokemons() const
{
    std::vector<Pokemon *>* pokemons = new std::vector<Pokemon *>;

    QSqlQuery query;
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
        //pokemon->calculateSpeed();
        pokemons->push_back(pokemon);
    }

    return pokemons;
}

std::vector<Pokemon *> *DatabaseManager::getPlantTypePokemons() const
{
    std::vector<Pokemon *>* pokemons = new std::vector<Pokemon *>;

    QSqlQuery query;
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
        //pokemon->calculateSpeed();
        pokemons->push_back(pokemon);
    }

    return pokemons;
}
