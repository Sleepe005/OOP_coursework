#include "TimingSettings.h"
#include <QFormLayout>
#include <QVBoxLayout>

TimingSettings::TimingSettings(QWidget *parent)
    : QWidget(parent)
{
    setStyleSheet("background-color: #f2d8ef; border-radius: 20px;");

    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    QFormLayout *form = new QFormLayout();

    redTime = new QSpinBox(); redTime->setValue(20);
    yellowTime = new QSpinBox(); yellowTime->setValue(20);
    greenTime = new QSpinBox(); greenTime->setValue(20);

    form->addRow("Red time", redTime);
    form->addRow("Yellow time", yellowTime);
    form->addRow("Green time", greenTime);

    QVBoxLayout *buttons = new QVBoxLayout();
    saveBtn = new QPushButton("Save settings");
    cancelBtn = new QPushButton("Cancel");
    saveBtn->setStyleSheet("background-color: #f7e8f7; border-radius: 12px;");
    cancelBtn->setStyleSheet("background-color: #f7e8f7; border-radius: 12px;");

    buttons->addWidget(saveBtn);
    buttons->addWidget(cancelBtn);

    mainLayout->addLayout(form);
    mainLayout->addLayout(buttons);

    connect(saveBtn, &QPushButton::clicked, this, &TimingSettings::settingsSaved);
}

int TimingSettings::getRedTime() const { return redTime->value(); }
int TimingSettings::getYellowTime() const { return yellowTime->value(); }
int TimingSettings::getGreenTime() const { return greenTime->value(); }
