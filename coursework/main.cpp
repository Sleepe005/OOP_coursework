#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include "comm/communicator.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "coursework_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }
    MainWindow w;

    // параметры коммуникатора
    TCommParams pars = {
        QHostAddress("127.0.0.1"), 10001,
        QHostAddress("127.0.0.1"), 10000
    };

    TCommunicator *comm = new TCommunicator(pars, &w);
    w.setCommunicator(comm);

    w.show();
    return a.exec();
}
