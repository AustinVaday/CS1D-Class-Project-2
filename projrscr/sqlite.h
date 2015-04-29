
#ifndef DEBUG_SQL
#define DEBUG_SQL 1
#include <QDebug>
#endif

#ifndef SQLITE_H
#define SQLITE_H
#include <QObject>
#include <QSql>
#include <QSqlDatabase>

class SQLite : public QObject
{
        Q_OBJECT
    public:
        explicit SQLite(QObject *parent = 0);
        bool startDatabase(QString userName = "", QString password = "");
        // Connects to a SQLite localhost database
        //  considering to overload the function

        bool stopDatabase();
        // Removes Connection

        QSqlDatabase getDatabase();
        // returns the database to the calling function. This might be moved to private

    signals:

    public slots:


    private:
        QSqlDatabase database;
        QString data;
};

#endif // SQLITE_H
