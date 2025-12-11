#pragma once
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsEllipseItem>
#include <QColor>

class CrossroadScene : public QGraphicsScene {
    Q_OBJECT
public:
    explicit CrossroadScene(QObject *parent = nullptr);

    void setTrafficLight(int index, const QColor &color); // 0-3 светофоры

private:
    QGraphicsRectItem *roadHorizontal;
    QGraphicsRectItem *roadVertical;
    QGraphicsEllipseItem *trafficLights[4]; // четыре светофора

signals:
    void sendMessage(QString msg);

public slots:
    void onMessage(QString msg);

};
