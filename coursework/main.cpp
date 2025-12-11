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

    // Параметры коммуникатора
    TCommParams pars = {
        QHostAddress("127.0.0.1"), 10001,  // прием
        QHostAddress("127.0.0.1"), 10000   // отправка
    };

    TCommunicator *comm = new TCommunicator(pars, &w);

    // Соединяем MainWindow и Communicator
    QObject::connect(comm, &TCommunicator::recieved,
                     &w, &MainWindow::fromCommunicator);

    QObject::connect(&w, &MainWindow::toCommunicator,
                     comm, [&](QString msg){
                         comm->send(msg.toUtf8());
                     });

    w.show();
    return a.exec();
}
