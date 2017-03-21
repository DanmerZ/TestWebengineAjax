#include "database.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QDebug>

Database * Database::instance = nullptr;

Database::Database(QObject *parent)
   : QObject(parent)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("test.db");
    bool isOpen = database.open();
    if (!isOpen)
        QMessageBox::warning(nullptr, "DB problem", "Database wasn't opened, sorry, appologize, it's my fault... :(",
                             QMessageBox::Cancel);
}

Database::~Database()
{

}

Database *Database::getInstance()
{
    if (instance == nullptr)
        instance = new Database;
    return instance;
}

bool Database::exec(QString sqlString)
{
    QSqlQuery query(database);
    return query.exec(sqlString);
}

QList<QList<QString>> Database::query(QString sqlString)
{
    QList<QList<QString>> result;
    QSqlQuery query(database);

    if (!database.isOpen())
    {
        QMessageBox::warning(nullptr, "DB problem", "Database isn't opened, sorry:(",
                             QMessageBox::Cancel);
        return result;
    }

    bool bRet = query.exec(sqlString);
    if (!bRet)
    {
        QMessageBox::warning(nullptr, "DB problem", "Query: " + sqlString,
                             QMessageBox::Cancel);
        return result;
    }

    int recordSize = query.record().count();

    while(query.next())
    {
        QStringList row;
        for (int i = 0; i < recordSize; i++)
            row << query.value(i).toString();
        result.append(row);
    }
    return result;
}
