#pragma once
#include <QWidget>
#include <QPushButton>
#include "TrafficLightIndicator.h"
#include "TimingSettings.h"

class ControlPanel : public QWidget {
    Q_OBJECT
public:
    explicit ControlPanel(QWidget *parent = nullptr);

    TrafficLightIndicator* getTrafficLightIndicator() const;
    TimingSettings* getTimingSettings() const;

private:
    QPushButton *powerBtn;
    QPushButton *autoBtn;
    QPushButton *autonomBtn;
    QPushButton *manualBtn;
    TrafficLightIndicator *trafficLight;
    TimingSettings *timingSettings;
};
