#include "mytimer.h"
#include "scene.h"

myTimer::myTimer()
{
    time = 30;
    setPlainText(QString("Time Left:")+QString::number(time));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
}

void myTimer::counting()
{
    time--;
    setPlainText(QString("Time Left:")+QString::number(time));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
    if(time == 0)
    {
        disconnect(timer,SIGNAL(timeout()),this,SLOT(counting()));
    }
}

void myTimer::startTime()
{
    timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(counting()));
    timer->start(1000);
}

void myTimer::initialize()
{
    time = 30;
    setPlainText(QString("Time Left:")+QString::number(time));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
}
