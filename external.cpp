#include "external.h"
#include <QDebug>
#include <QMessageBox>

External::External(QObject *parent)
{

}

int External::callFromJS(QString str)
{
    qDebug() << str;
    QMessageBox::about(nullptr, "Desktop Viewer", "Desktop Viewer");
    return 42;
}
