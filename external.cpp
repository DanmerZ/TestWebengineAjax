#include "external.h"
#include <QDebug>

External::External(QObject *parent)
{

}

void External::callFromJS()
{
    qDebug() << "Called from JS";
}
