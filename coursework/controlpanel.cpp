#include "ControlPanel.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFont>

ControlPanel::ControlPanel(QWidget *parent)
    : QWidget(parent)
{
    setFixedWidth(350);
    setStyleSheet("background-color: #f2d8ef; border-radius: 30px;");

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignTop);

    QLabel *title = new QLabel("Control Panel");
    QFont titleFont; titleFont.setPointSize(18); titleFont.setBold(true);
    title->setFont(titleFont);
    title->setAlignment(Qt::AlignCenter);
    layout->addWidget(title);

    powerBtn = new QPushButton("ON");
    powerBtn->setCheckable(true);
    powerBtn->setFixedSize(120, 40);
    powerBtn->setStyleSheet("background-color: #c8f7df; border-radius: 20px; font-size: 18px;");
    layout->addWidget(powerBtn, 0, Qt::AlignCenter);

    QHBoxLayout *modes = new QHBoxLayout();
    autoBtn = new QPushButton("Auto control");
    autonomBtn = new QPushButton("Autonomous control");
    manualBtn = new QPushButton("Manual control");

    autoBtn->setStyleSheet("background-color: #e6e6e6; border-radius: 12px;");
    autonomBtn->setStyleSheet("background-color: #c8f7df; border-radius: 12px;");
    manualBtn->setStyleSheet("background-color: #e6e6e6; border-radius: 12px;");

    modes->addWidget(autoBtn);
    modes->addWidget(autonomBtn);
    modes->addWidget(manualBtn);
    layout->addLayout(modes);

    trafficLight = new TrafficLightIndicator();
    layout->addWidget(trafficLight, 0, Qt::AlignCenter);

    timingSettings = new TimingSettings();
    layout->addWidget(timingSettings);

    setLayout(layout);
}

TrafficLightIndicator* ControlPanel::getTrafficLightIndicator() const {
    return trafficLight;
}

TimingSettings* ControlPanel::getTimingSettings() const {
    return timingSettings;
}

void ControlPanel::onMessage(QString msg)
{
    qDebug() << "Scene получила:" << msg;

    // // пример
    // setTrafficLight(0, Qt::green);
}
