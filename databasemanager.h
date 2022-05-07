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
    std::vector<Pokemon*>* getPokemons() const;
    std::vector<Pokemon*>* getFireTypePokemons() const;
    std::vector<Pokemon*>* getElectrikTypePokemons() const;
    std::vector<Pokemon*>* getWaterTypePokemons() const;
    std::vector<Pokemon*>* getPlantTypePokemons() const;

    DatabaseManager *getItsInstance() const;
    const QSqlDatabase &getItsDatabase() const;
};

#endif // DATABASEMANAGER_H
