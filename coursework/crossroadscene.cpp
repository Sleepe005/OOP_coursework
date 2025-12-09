#include "CrossroadScene.h"

CrossroadScene::CrossroadScene(QObject *parent)
    : QGraphicsScene(parent)
{
    // Рисуем дороги
    roadHorizontal = addRect(0, 200, 800, 100, QPen(Qt::NoPen), QBrush(Qt::darkGray));
    roadVertical = addRect(350, 0, 100, 500, QPen(Qt::NoPen), QBrush(Qt::darkGray));

    // Создаём светофоры (кружки)
    trafficLights[0] = addEllipse(330, 180, 20, 20, QPen(Qt::black), QBrush(Qt::red));
    trafficLights[1] = addEllipse(450, 180, 20, 20, QPen(Qt::black), QBrush(Qt::red));
    trafficLights[2] = addEllipse(330, 300, 20, 20, QPen(Qt::black), QBrush(Qt::red));
    trafficLights[3] = addEllipse(450, 300, 20, 20, QPen(Qt::black), QBrush(Qt::red));
}

void CrossroadScene::setTrafficLight(int index, const QColor &color) {
    if(index < 0 || index > 3) return;
    trafficLights[index]->setBrush(QBrush(color));
}
