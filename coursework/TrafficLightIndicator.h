#pragma once
#include <QWidget>
#include <QColor>
#include <QLabel>
#include <QVBoxLayout>

class TrafficLightCircle : public QLabel {
    Q_OBJECT
public:
    explicit TrafficLightCircle(const QColor &color, QWidget *parent = nullptr);
    void setColor(const QColor &color);
};

class TrafficLightIndicator : public QWidget {
    Q_OBJECT
public:
    explicit TrafficLightIndicator(QWidget *parent = nullptr);
    void setRed();
    void setYellow();
    void setGreen();

private:
    TrafficLightCircle *red;
    TrafficLightCircle *yellow;
    TrafficLightCircle *green;
};
