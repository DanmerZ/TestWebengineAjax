#include "mainwindow.h"
#include <QApplication>
#include <QtWebEngineWidgets>

int main(int argc, char *argv[])
{    
    qputenv("QTWEBENGINE_REMOTE_DEBUGGING", QByteArray("3000"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
