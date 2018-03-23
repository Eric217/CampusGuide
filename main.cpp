#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QDateTime>


int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QSplashScreen *splashscreen = new QSplashScreen;
    splashscreen->setPixmap(QPixmap(":/image/Initialization.png"));


    splashscreen->show();
    MainWindow w;


    QDateTime n = QDateTime::currentDateTime(), now;
    do {
        now = QDateTime::currentDateTime();
    } while (n.secsTo(now) <= 0.5);


    splashscreen->hide();
    w.show();


    return a.exec();
}
