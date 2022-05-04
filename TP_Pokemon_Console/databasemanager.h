#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>

class DatabaseManager
{
private:
    QSqlDatabase itsDatabase;
    static DatabaseManager* itsInstance; // Utilisation du Singleton comme design-pattern
public:
    DatabaseManager();

    bool connect();
    void getPokemons();

    DatabaseManager *getItsInstance() const;
};

#endif // DATABASEMANAGER_H
