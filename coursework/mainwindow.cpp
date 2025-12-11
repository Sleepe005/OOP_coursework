#include "MainWindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this);
    QVBoxLayout *rootLayout = new QVBoxLayout(central);

    QHBoxLayout *topLayout = new QHBoxLayout();
    crossroadView = new QGraphicsView();
    crossroadView->setMinimumSize(800, 500);

    crossroadScene = new CrossroadScene(this);
    crossroadView->setScene(crossroadScene);

    controlPanel = new ControlPanel(this);

    topLayout->addWidget(crossroadView);
    topLayout->addWidget(controlPanel);

    rootLayout->addLayout(topLayout);

    central->setLayout(rootLayout);
    setCentralWidget(central);
}

void MainWindow::setCommunicator(TCommunicator *c)
{
    comm = c;

    //
    // ControlPanel → Communicator
    //
    connect(controlPanel, &ControlPanel::sendMessage,
            comm, [&](QString s){
                comm->send(s.toUtf8());
            });

    //
    // Communicator → ControlPanel
    //
    connect(comm, &TCommunicator::recieved,
            controlPanel, [&](QByteArray a){
                controlPanel->onMessage(QString(a));
            });

    //
    // CrossroadScene → Communicator
    //
    connect(crossroadScene, &CrossroadScene::sendMessage,
            comm, [&](QString s){
                comm->send(s.toUtf8());
            });

    //
    // Communicator → CrossroadScene
    //
    connect(comm, &TCommunicator::recieved,
            crossroadScene, [&](QByteArray a){
                crossroadScene->onMessage(QString(a));
            });
}
