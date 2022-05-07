#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include "pokemon.h"

#include <QSqlDatabase>
#include <vector>

class DatabaseManager
{
private:
    QSqlDatabase itsDatabase;
    static DatabaseManager* itsInstance; // Utilisation du Singleton comme design-pattern
public:
    DatabaseManager();

    bool connect();
    std::vector<Pokemon*>* getPokemons();
    std::vector<Pokemon*>* getFireTypePokemons();
    std::vector<Pokemon*>* getElectrikTypePokemons();
    std::vector<Pokemon*>* getWaterTypePokemons();
    std::vector<Pokemon*>* getPlantTypePokemons();

    DatabaseManager *getItsInstance() const;
    const QSqlDatabase &getItsDatabase() const;
};

#endif // DATABASEMANAGER_H
