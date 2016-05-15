#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>
#include <QString>
#include <QFont>

class Score: public QGraphicsTextItem
{
public:
    Score();
    int score;
    void increase_shit1();
    void increase_shit2();
    void decrease_shit1();
    void decrease_shit2();
    void nono();
    void initialize();

};

#endif // SCORE_H
