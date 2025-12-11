#pragma once
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "ControlPanel.h"
#include "CrossroadScene.h"
#include "comm/communicator.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setCommunicator(TCommunicator *c);

private:
    QGraphicsView *crossroadView;
    CrossroadScene *crossroadScene;
    ControlPanel *controlPanel;

    TCommunicator *comm;
};
