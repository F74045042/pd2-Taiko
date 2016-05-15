#include "drum.h"

Drum:: Drum()
{
    x_speed = 1;
}

void Drum::advance(int phase)
{
    //moving
    this->setPos(this->pos().x()-x_speed,this->pos().y());
}

/*void Drum::setspeed(int speed)
{
    x_speed = ;
}*/


