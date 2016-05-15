#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QApplication>
#include <QKeyEvent>
#include <Qtimer>
#include <QtGui>
#include <QtCore>
#include <QMessageBox>
#include <QSound>
#include <QMediaPlayer>
#include <QLayout>
#include <time.h>
#include "btn.h"
#include "rail.h"
#include "drum.h"
#include "score.h"
#include "mytimer.h"


class Scene : public QGraphicsScene
{
    Q_OBJECT

public:
    /*function*/
    Scene();
    void Init();
    void bgChange();
    void bgRecover();
    void gameInit();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);

    /*variable*/
    Btn *A;
    Btn *D;

    //for disconnect
    int dis = 0;
    //button
    Btn *btn_start;
    Btn *btn_exit;
    Btn *btn_back;
    Btn *btn_pause;
    Btn *btn_conti;
    int btn_start_w;
    int btn_start_h;
    int btn_exit_w;
    int btn_exit_h;
    int btn_back_w;
    int btn_back_h;

    //rail
    Rail *rail;

    //matong
    Rail *matong;
    int matong_w;
    int matong_h;

    //labi
    Rail *labi;

    //Drum
    Drum *drum1;
    Drum *drum2;
    int drum1_w = 150;
    int drum1_h = 150;
    int drum2_w = 170;
    int drum2_h = 170;

    //calculate how many drum create
    int num_drum = 0;
    int num = 0;

    //rand
    QList<int> rand_list;
    QList<Drum*> drum_list;

    //timer
    QTimer *timer;
    QTimer *timer_drum;

    /*Use to control scene page*/
    int screenMode;

    //score
    Score *score1;

    //counting time
    myTimer *mytime;

    //message
    QMessageBox *mybox;

    //sound
    QSound *bgm;
    QSound *bgm2;
    QSound *shit_hit1;
    QSound *shit_hit2;
    QSound *end;
    QSound *haha;

    //for確保只能運行一次
    int x = 1;

public slots:
    void endofgame();
    void timeup();
    void random()
    {
            rand_list.push_back(rand()%2+1);

            if(rand_list.back()==1)
            {
                /*happy*/
                /*drum1 picture setting*/
                drum1 = new Drum();
                QPixmap dm1;
                dm1.load(":/image/image/6-150121211244327.png");
                dm1 = dm1.scaled(150,150);
                drum1->setPixmap(dm1);
                drum1->setPos(425,115);
                addItem(drum1);
                drum_list.push_back(drum1);
                num_drum++;
            }
            else if(rand_list.back()==2)
            {
                /*sad*/
                /*drum picture setting*/
                drum2 = new Drum();
                QPixmap dm2;
                dm2.load(":/image/image/144UcA200A0-26124.png");
                dm2 = dm2.scaled(170,170);
                drum2->setPixmap(dm2);
                drum2->setPos(425,110);
                addItem(drum2);
                drum_list.push_back(drum2);
                num_drum++;
            }

            if(-20 > drum_list[num]->pos().x())
            {
                num++;
                if(score1->score > 0)
                {
                    if(rand_list[num]==1)
                    {
                        score1->decrease_shit1();
                    }
                    if(rand_list[num]==2)
                    {
                        score1->decrease_shit2();
                    }
                }
            }
            if(score1->score < 0)
            {
                score1->nono();
            }
   }

};

#endif // SCENE_H
