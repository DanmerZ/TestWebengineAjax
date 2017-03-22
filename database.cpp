#include "database.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonArray>
#include <QDebug>

Database * Database::instance = nullptr;

Database::Database(QObject *parent)
   : QObject(parent)
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("test.db");
    bool isOpen = database.open();
    if (!isOpen)
        showError("Database wasn't opened, sorry, appologize, it's my fault... :(");
//        QMessageBox::warning(nullptr, "DB problem", "Database wasn't opened, sorry, appologize, it's my fault... :(",
//                             QMessageBox::Cancel);
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

void Database::showError(QString err)
{
    qDebug() << err;
    emitError(err);
}

bool Database::exec(QString sqlString)
{
    QSqlQuery query(database);
    return query.exec(sqlString);
}

QString Database::queryJson(QString sqlString)
{
    QSqlQuery query(database);

    if (!database.isOpen())
    {
        //QMessageBox::warning(nullptr, "DB problem", "Database isn't opened, sorry:(",
        //                     QMessageBox::Cancel);
        showError("Database isn't opened, sorry:(");
        return "[]";
    }

    bool bRet = query.exec(sqlString);
    if (!bRet)
    {
        //QMessageBox::warning(nullptr, "DB problem", "Query failed: " + sqlString,
        //                     QMessageBox::Cancel);
        showError("Query failed: " + sqlString);
        return "[]";
    }

    int recordSize = query.record().count();
    QJsonArray jsonArray;

    while(query.next())
    {
        QJsonObject obj;
        for (int i = 0; i < recordSize; i++)
        {
            QString key = query.record().fieldName(i);
            obj[key] = query.value(i).toString();
        }
        jsonArray.append(QJsonValue(obj));
    }

    return QJsonDocument(jsonArray).toJson();
}
