#include "sqlite.h"

SQLite::SQLite(QObject *parent) :
    QObject(parent)
{
    // Default database constructor for connecting to SQLite Server that has the Baseball Stadiums Database
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setHostName("localhost");
    database.setDatabaseName("Baseball Stadiums");
    database.setUserName("root");
    database.setPassword("");

    bool open = database.open();

    if(!open)
    {
        qDebug() << endl << "Failed to start the database!" << endl;
    }
}

// Used for starting a SQL Database after it has been stopped
bool SQLite::startDatabase(QString userName, QString password)
{
    bool open = false;

    // Checks if the database is already open
    if(!database.isOpen())
    {
        if(userName != "" && password != "")
        {
            open = database.open(userName, password);
        }
        else
        {
            open = database.open();
        }
    }

#if DEBUG_SQL
    if(!open)
    {
        qDebug() << endl << "Failed to start the database!" << endl;
    }
#endif


    return open;
}

