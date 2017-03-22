#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"

namespace Ui {
class MainWindow;
}

class QWebEngineView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_actionRun_localhost_3000_triggered();

private:
    Ui::MainWindow *ui;

    QWebEngineView *view;
    Database *db;
};

#endif // MAINWINDOW_H
