#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "pokemon.h"

#include <QSqlDatabase>
#include <vector>

class DatabaseManager
{
private:
    QSqlDatabase itsDatabase;
    std::vector<Pokemon*>* itsFireTypePokemons;
    std::vector<Pokemon*>* itsWaterTypePokemons;
    std::vector<Pokemon*>* itsPlantTypePokemons;
    std::vector<Pokemon*>* itsElectrikTypePokemons;

public:
    DatabaseManager();

    bool connect();
    void startQueries();
    void saveTrainer(QString name, std::vector<Pokemon*>* pokemons);
    std::vector<Pokemon*>* getPokemons() const;
    std::vector<Pokemon*>* getFireTypePokemons() const;
    std::vector<Pokemon*>* getElectrikTypePokemons() const;
    std::vector<Pokemon*>* getWaterTypePokemons() const;
    std::vector<Pokemon*>* getPlantTypePokemons() const;

    const QSqlDatabase &getItsDatabase() const;
};

#endif // DATABASEMANAGER_H
