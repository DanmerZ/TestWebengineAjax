#ifndef EXTERNAL_H
#define EXTERNAL_H

#include <QObject>

class External : public QObject
{
    Q_OBJECT

public:
    explicit External(QObject *parent = 0);

public slots:
    int callFromJS(QString str);
};

#endif // EXTERNAL_H
