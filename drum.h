#ifndef DRUM_H
#define DRUM_H
#include <QGraphicsPixmapItem>

class Drum : public QGraphicsPixmapItem
{
public:
    Drum();
    /*variable*/
    int x_speed;

    /*function*/
    void advance(int phase);
    void setspeed(int speed);

};

#endif // DRUM_H
