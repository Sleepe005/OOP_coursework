#pragma once
#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "ControlPanel.h"
#include "CrossroadScene.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    QGraphicsView *crossroadView;
    QGraphicsScene *crossroadScene;
    ControlPanel *controlPanel;
};
