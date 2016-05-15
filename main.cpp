#include "mainwindow.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QLCDNumber>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QDesktopWidget wid;
    int screenW = 610;
    int screenH = 410;

    w.setGeometry(wid.screen()->width()/2 - (screenW/2),wid.screen()->height()/2 - (screenH/2),screenW,screenH);
    w.setWindowTitle("TaiKu");
    w.setWindowIcon(QIcon(":/image/image/2040285.png"));
    w.setFixedSize(screenW,screenH);
    w.show();

    return a.exec();
}
