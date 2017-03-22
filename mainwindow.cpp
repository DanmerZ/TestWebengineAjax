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
    db = Database::getInstance();
    channel->registerObject("external", external);
    channel->registerObject("database", db);
    view->page()->setWebChannel(channel);

    view->page()->settings()->globalSettings()->setAttribute(QWebEngineSettings::WebAttribute::LocalContentCanAccessRemoteUrls, true);

    setCentralWidget(view);

    connect(db, &Database::emitError, [=](QString err) {
        ui->statusBar->showMessage(err);
        view->page()->runJavaScript(QString("console.log('Database error: ' + '%1');").arg(err));
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionRun_localhost_3000_triggered()
{
    QDesktopServices::openUrl(QUrl("http://localhost:3000"));
}
