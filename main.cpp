#include "mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QDateTime>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //初始
     QSplashScreen *splashscreen = new QSplashScreen;
     splashscreen->setPixmap(QPixmap(":/image/Initialization.png"));
     splashscreen->show();

     //欢迎界面延时器3秒
     QDateTime n = QDateTime::currentDateTime();
     QDateTime now;
     do {
     now = QDateTime::currentDateTime();
     } while (n.secsTo(now) <= 0.5);


    //主窗口
    MainWindow w;
    w.show();



    return a.exec();
}
