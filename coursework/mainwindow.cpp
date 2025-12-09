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
    // crossroadScene = new QGraphicsScene();
    // crossroadView->setScene(crossroadScene);
    crossroadScene = new CrossroadScene();
    crossroadView->setScene(crossroadScene);

    controlPanel = new ControlPanel();

    topLayout->addWidget(crossroadView);
    topLayout->addWidget(controlPanel);

    rootLayout->addLayout(topLayout);

    central->setLayout(rootLayout);
    setCentralWidget(central);
}
