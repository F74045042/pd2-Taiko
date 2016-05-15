#ifndef MYTIMER_H
#define MYTIMER_H
#include <QGraphicsTextItem>
#include <QFont>
#include <QObject>
#include <QTimer>
#include <QMessageBox>

class myTimer: public QGraphicsTextItem
{
    Q_OBJECT
public:
    myTimer();
    void startTime();
    void initialize();

    //variable
    int time;
    QTimer *timer;

public slots:
    void counting();
};

#endif // MYTIMER_H
