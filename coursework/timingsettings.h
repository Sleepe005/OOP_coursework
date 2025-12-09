#pragma once
#include <QWidget>
#include <QSpinBox>
#include <QPushButton>

class TimingSettings : public QWidget {
    Q_OBJECT
public:
    explicit TimingSettings(QWidget *parent = nullptr);

    int getRedTime() const;
    int getYellowTime() const;
    int getGreenTime() const;

signals:
    void settingsSaved();

private:
    QSpinBox *redTime;
    QSpinBox *yellowTime;
    QSpinBox *greenTime;
    QPushButton *saveBtn;
    QPushButton *cancelBtn;
};
