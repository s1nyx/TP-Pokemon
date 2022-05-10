#include "databasemanager.h"
#include "electrikpokemon.h"
#include "firepokemon.h"
#include "plantpokemon.h"
#include "waterpokemon.h"

#include <QSqlQuery>

/*!
 * \brief DatabaseManager::DatabaseManager
 */
DatabaseManager::DatabaseManager()
{
    itsElectrikTypePokemons = new std::vector<Pokemon*>();
    itsWaterTypePokemons = new std::vector<Pokemon*>();
    itsFireTypePokemons = new std::vector<Pokemon*>();
    itsPlantTypePokemons = new std::vector<Pokemon*>();
}

/*!
 * \brief DatabaseManager::~DatabaseManager
 */
DatabaseManager::~DatabaseManager()
{
    delete itsFireTypePokemons;
    delete itsElectrikTypePokemons;
    delete itsWaterTypePokemons;
    delete itsPlantTypePokemons;
    itsDatabase.close();
}

/*!
 * Permet de se connecter à la BDD
 * Renvoie si la connexion a été établie
 * \brief DatabaseManager::connect
 * \return
 */
bool DatabaseManager::connect()
{
    itsDatabase = QSqlDatabase::addDatabase("QSQLITE");
    itsDatabase.setDatabaseName("database.db");

    return itsDatabase.open();
}

/*!
 * Permet de sauvegarder un dresseur
 * \brief DatabaseManager::saveTrainer
 * \param name
 * \param pokemons
 */
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

/*!
 * Récupère les pokemons des différents types
 * \brief DatabaseManager::startQueries
 */
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

/*!
 * Renvoie la liste des pokemons
 * \brief DatabaseManager::getPokemons
 * \return
 */
std::vector<Pokemon *>* DatabaseManager::getPokemons() const
{
    std::vector<Pokemon *>* pokemons = new std::vector<Pokemon *>;

    pokemons->insert(pokemons->end(), itsFireTypePokemons->begin(), itsFireTypePokemons->end());
    pokemons->insert(pokemons->end(), itsPlantTypePokemons->begin(), itsPlantTypePokemons->end());
    pokemons->insert(pokemons->end(), itsElectrikTypePokemons->begin(), itsElectrikTypePokemons->end());
    pokemons->insert(pokemons->end(), itsWaterTypePokemons->begin(), itsWaterTypePokemons->end());

    return pokemons;
}

/*!
 * Renvoie la liste des pokemons FEU
 * \brief DatabaseManager::getFireTypePokemons
 * \return
 */
std::vector<Pokemon *> *DatabaseManager::getFireTypePokemons() const
{
    return itsFireTypePokemons;
}

/*!
 * Renvoie la liste des pokemons ELECTRIK
 * \brief DatabaseManager::getElectrikTypePokemons
 * \return
 */
std::vector<Pokemon *> *DatabaseManager::getElectrikTypePokemons() const
{
    return itsElectrikTypePokemons;
}

/*!
 * Renvoie la liste des pokemons EAU
 * \brief DatabaseManager::getWaterTypePokemons
 * \return
 */
std::vector<Pokemon *> *DatabaseManager::getWaterTypePokemons() const
{
    return itsWaterTypePokemons;
}

/*!
 * Renvoie la liste des pokemons PLANT
 * \brief DatabaseManager::getPlantTypePokemons
 * \return
 */
std::vector<Pokemon *> *DatabaseManager::getPlantTypePokemons() const
{
    return itsPlantTypePokemons;
}
