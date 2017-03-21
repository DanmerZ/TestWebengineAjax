#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QSqlDatabase>

class Database : public QObject
{
    Q_OBJECT

private:
    static Database* instance;
protected:
    Database(QObject *parent = nullptr);
    QSqlDatabase database;

public:
    virtual ~Database();
    static Database *getInstance();

public slots:
    bool exec(QString sqlString);
    QList<QList<QString>> query(QString sqlString);
};

#endif // DATABASE_H
