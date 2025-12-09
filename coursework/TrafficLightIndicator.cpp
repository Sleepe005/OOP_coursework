#include "TrafficLightIndicator.h"

TrafficLightCircle::TrafficLightCircle(const QColor &color, QWidget *parent)
    : QLabel(parent)
{
    setFixedSize(70, 70);
    setStyleSheet(QString("background-color: %1; border-radius: 35px;")
                      .arg(color.name()));
}

void TrafficLightCircle::setColor(const QColor &color) {
    setStyleSheet(QString("background-color: %1; border-radius: 35px;")
                      .arg(color.name()));
}

TrafficLightIndicator::TrafficLightIndicator(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignCenter);

    red = new TrafficLightCircle(Qt::red);
    yellow = new TrafficLightCircle(Qt::yellow);
    green = new TrafficLightCircle(Qt::green);

    layout->addWidget(red);
    layout->addWidget(yellow);
    layout->addWidget(green);
    setLayout(layout);
}

void TrafficLightIndicator::setRed() {
    red->setColor(Qt::red);
    yellow->setColor(Qt::gray);
    green->setColor(Qt::gray);
}

void TrafficLightIndicator::setYellow() {
    red->setColor(Qt::gray);
    yellow->setColor(Qt::yellow);
    green->setColor(Qt::gray);
}

void TrafficLightIndicator::setGreen() {
    red->setColor(Qt::gray);
    yellow->setColor(Qt::gray);
    green->setColor(Qt::green);
}
