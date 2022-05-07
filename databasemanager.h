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

    DatabaseManager *getItsInstance() const;
};

#endif // DATABASEMANAGER_H
