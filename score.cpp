#include "score.h"


Score::Score()
{
    score = 0;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
}

void Score::increase_shit1()
{
    score+=1;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
}

void Score::increase_shit2()
{
    score+=2;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
}

void Score::decrease_shit1()
{
    score-=1;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
}

void Score::decrease_shit2()
{
    score-=2;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
}

void Score::nono()
{
    score == 0;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
}

void Score::initialize()
{
    score = 0;
    setPlainText(QString("Score: ")+QString::number(score));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Courier",20));
}
