#include "databasemanager.h"

DatabaseManager::DatabaseManager()
{
    itsInstance = nullptr;
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
