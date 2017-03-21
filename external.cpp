#include "external.h"
#include <QDebug>
#include <QMessageBox>

External::External(QObject *parent)
{

}

void External::callFromJS()
{
    QMessageBox::about(nullptr, "Desktop Viewer", "Desktop Viewer");
}
