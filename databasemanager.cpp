#include "databasemanager.h"
#include "electrikpokemon.h"
#include "firepokemon.h"
#include "plantpokemon.h"
#include "waterpokemon.h"
#include <iostream>
#include <QSqlQuery>

DatabaseManager* DatabaseManager::itsInstance = nullptr;

DatabaseManager::DatabaseManager()
{}

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

std::vector<Pokemon *>* DatabaseManager::getPokemons()
{
    std::vector<Pokemon *>* pokemons = new std::vector<Pokemon *>;

    // TODO: clean ici c'est vrm dégeu
    QSqlQuery query;
    query.exec("SELECT * FROM electrik_pokemons");
    while (query.next())
    {
        Pokemon* pokemon = new ElectrikPokemon(
            query.value("name").toString().toStdString(),
            query.value("size").toFloat(),
            query.value("weight").toFloat(),
            query.value("hp").toInt(),
            query.value("cp").toInt(),
            query.value("paws").toInt(),
            query.value("intensity").toInt(),
            query.value("wings").toInt()
        );
        pokemons->push_back(pokemon);
    }

    query.exec("SELECT * FROM fire_pokemons");
    while (query.next())
    {
        Pokemon* pokemon = new FirePokemon(
            query.value("name").toString().toStdString(),
            query.value("size").toFloat(),
            query.value("weight").toFloat(),
            query.value("hp").toInt(),
            query.value("cp").toInt(),
            query.value("paws").toInt()
        );
        pokemons->push_back(pokemon);
    }

    query.exec("SELECT * FROM plant_pokemons");
    while (query.next())
    {
        Pokemon* pokemon = new PlantPokemon(
            query.value("name").toString().toStdString(),
            query.value("size").toFloat(),
            query.value("weight").toFloat(),
            query.value("hp").toInt(),
            query.value("cp").toInt()
        );
        pokemons->push_back(pokemon);
    }

    query.exec("SELECT * FROM water_pokemons");
    while (query.next())
    {
        Pokemon* pokemon = new WaterPokemon(
            query.value("name").toString().toStdString(),
            query.value("size").toFloat(),
            query.value("weight").toFloat(),
            query.value("hp").toInt(),
            query.value("cp").toInt(),
            query.value("fins").toInt()
        );
        pokemons->push_back(pokemon);
    }

    return pokemons;
}
