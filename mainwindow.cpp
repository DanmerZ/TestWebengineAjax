#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>
#include <QtWebEngineWidgets>
#include <QWebChannel>
#include "external.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    view = new QWebEngineView(this);

    view->setUrl(QUrl::fromLocalFile( QCoreApplication::applicationDirPath() + "/web/index.html"));

    QWebChannel *channel = new QWebChannel;
    External *external = new External;
    channel->registerObject("external", external);
    view->page()->setWebChannel(channel);

    view->page()->settings()->globalSettings()->setAttribute(QWebEngineSettings::WebAttribute::LocalContentCanAccessRemoteUrls, true);

    setCentralWidget(view);
}

MainWindow::~MainWindow()
{
    delete ui;
}

