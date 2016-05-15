#include "scene.h"

Scene::Scene()
{
    screenMode = 0;
}
void Scene::Init()
{
    //start
    btn_start = new Btn();
    QPixmap start;
    start.load(":/image/image/play.png");
    start = start.scaled(110,110,Qt::KeepAspectRatio);
    btn_start->setPixmap(start);
    btn_start->setPos(310,300);
    btn_start_w = 50;
    btn_start_h = 50;
    addItem(btn_start);

    //exit
    btn_exit = new Btn();
    QPixmap exit;
    exit.load(":/image/image/exit.png");
    exit = exit.scaled(150,150,Qt::KeepAspectRatio);
    btn_exit->setPixmap(exit);
    btn_exit->setPos(180,290);
    btn_exit_w = 50;
    btn_exit_h = 50;
    addItem(btn_exit);

    //sound
    bgm = new QSound(":/sound/bgm1.wav");
    bgm->setLoops(INFINITE);

    bgm2 = new QSound(":/sound/bgm2.wav");
    bgm2->setLoops(INFINITE);

    shit_hit1 = new QSound(":/sound/0177.WAV");

    shit_hit2 = new QSound(":/sound/0178.WAV");

    end = new QSound(":/sound/_cnwav_mp3.wav");

    haha = new QSound(":/sound/haha.wav");

    bgm->play();
}

void Scene::bgChange()
{
    //A && D
    A = new Btn;
    QPixmap a;
    a.load(":/image/image/A.png");
    a = a.scaled(150,150);
    A->setPixmap(a);
    A->setPos(180,280);
    addItem(A);

    D = new Btn;
    QPixmap d;
    d.load(":/image/image/D.png");
    d = d.scaled(170,170);
    D->setPixmap(d);
    D->setPos(270,270);
    addItem(D);

    /*connect*/
    dis = 0;
    /*change background*/
    QImage bg;
    bg.load(":/image/image/7658225_656869.jpg");
    bg = bg.scaled(610,410);
    this->setBackgroundBrush(bg);

    /*remove button*/
    this->removeItem(btn_start);
    this->removeItem(btn_exit);

    /*rail picture setting*/
    rail = new Rail();
    QPixmap rl;
    rl.load(":/image/image/panel.png");
    rl = rl.scaled(610,100);
    rail->setPixmap(rl);
    rail->setPos(0,170);
    addItem(rail);

    /*matong pic setting*/
    matong = new Rail();
    QPixmap mt;
    mt.load(":/image/image/toilet-toilet-bowl_small.png");
    mt = mt.scaled(300,300);
    matong->setPixmap(mt);
    matong->setPos(-100,35);
    addItem(matong);

    /*back button setting*/
    btn_back = new Btn();
    QPixmap bk;
    bk.load(":/image/image/go.png");
    bk = bk.scaled(90,90);
    btn_back->setPixmap(bk);
    btn_back->setPos(0,5);
    btn_back_w = 80;
    btn_back_h = 85;
    addItem(btn_back);

    /*labi*/
    labi = new Rail();
    QPixmap lb;
    lb.load(":/image/image/0.gif");
    lb = lb.scaled(250,250);
    labi->setPixmap(lb);
    labi->setPos(450,40);
    addItem(labi);

    /*Score*/
    score1 = new Score();
    score1->setPos(420,35);
    addItem(score1);

    /*time count*/
    mytime = new myTimer();
    mytime->setPos(200,35);
    addItem(mytime);



}

void Scene::bgRecover()
{
    /*disconnect*/
    dis = 1;
    /*remove item*/
    removeItem(btn_back);
    removeItem(rail);
    removeItem(labi);
    removeItem(matong);
    removeItem(A);
    removeItem(D);

    /*remove drum*/
    for(int i=0;i<num_drum;i++)
    {
        removeItem(drum_list[i]);
    }

    /*add back start page button*/
    addItem(btn_start);
    addItem(btn_exit);

    /*add back background*/
    QImage bg;
    bg.load(":/image/image/8345569094.jpg");
    bg = bg.scaled(610,410);
    this->setBackgroundBrush(bg);
}



void Scene::gameInit()
{
        if(dis == 0)
        {
        timer = new QTimer(this);
        timer_drum = new QTimer(this);
        connect(timer_drum,SIGNAL(timeout()),this,SLOT(random()));
        connect(timer,SIGNAL(timeout()),this,SLOT(advance()));
        connect(timer,SIGNAL(timeout()),this,SLOT(timeup()));
        timer_drum->start(2000);
        timer->start(20);
        }

        if(dis == 1)
        {
        disconnect(timer_drum,SIGNAL(timeout()),this,SLOT(random()));
        disconnect(timer,SIGNAL(timeout()),this,SLOT(advance()));
        disconnect(timer,SIGNAL(timeout()),this,SLOT(timeup()));
        }
}

void Scene::timeup()
{
    if(mytime->time <= 0)
    {
        mybox = new QMessageBox;
        mybox->setIconPixmap(QPixmap(":/image/image/5_141211115056_17.gif"));
        mybox->setWindowTitle("Time up");
        mybox->setText(QString("Score: ")+QString::number(score1->score)+(QString("\n\nPlay again?")));
        mybox->setStandardButtons(QMessageBox::Yes | QMessageBox::No);
        mybox->setButtonText(QMessageBox::No,("Play Again"));
        mybox->setButtonText(QMessageBox::Yes,("Home"));
        mybox->show();
        end->play();

        dis = 1;
        gameInit();
        mytime->initialize();
        score1->initialize();

        bgm2->stop();

        //設定yes no按鈕事件
        //Play again
        if(mybox->exec() == QMessageBox::No)
        {
            for(int i=0;i<num_drum;i++)
            {
                removeItem(drum_list[i]);
            }
            drum_list.clear();
            rand_list.clear();
            num =0;
            num_drum = 0;
            mytime->startTime();
            dis = 0;
            gameInit();
            bgm2->play();

        }
        //Home
        else if(mybox->exec() == QMessageBox::Yes)
        {
            removeItem(A);
            removeItem(D);
            removeItem(score1);
            removeItem(mytime);
            bgRecover();
            gameInit();

            //Initialize
            drum_list.clear();
            rand_list.clear();
            num =0;
            num_drum = 0;
            screenMode = 0;
            bgm->play();

        }
    }
}

void Scene::endofgame()
{
    QApplication::exit();
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(screenMode == 0)
    {
        /*Beginning page*/
        //Start Game button
        if(event->scenePos().x() > btn_start->pos().x()+20 && event->scenePos().x() <= btn_start->pos().x()+80)
        {
           if(event->scenePos().y() > btn_start->pos().y()+20 && event->scenePos().y() <= btn_start->pos().y()+80)
           {
               if(x == 1)
               {
               cout<<"Start Game!"<<endl;
               bgChange();
               gameInit();
               screenMode = 1;
               /*start counting time*/
               mytime->startTime();

               //stop bgm
               bgm->stop();
               bgm2->play();
               }

           }
        }
        /*Beginning page*/
        //Exit button
        else if(event->scenePos().x() > btn_exit->pos().x()+20 && event->scenePos().x() <= btn_exit->pos().x()+100)
        {
            if(event->scenePos().y() > btn_exit->pos().y()+20 && event->scenePos().y() <= btn_exit->pos().y()+110)
            {
                if(x == 1)
                {
                    bgm->stop();
                    haha->play();
                    QTimer::singleShot(8000,this,SLOT(endofgame()));
                    //QApplication::exit();
                    x = 0;
                }
            }
        }
    }

    if(screenMode == 1)
    {

        /*Playing page*/
        //Back button setting
        if(event->scenePos().x() > btn_back->pos().x() && event->scenePos().x() <= btn_back->pos().x()+btn_back_w)
        {
            if(event->scenePos().y() > btn_back->pos().y() && event->scenePos().y() <= btn_back->pos().y()+btn_back_h)
            {
                bgRecover();
                gameInit();
                removeItem(score1);
                removeItem(mytime);

                //Initialize
                drum_list.clear();
                rand_list.clear();
                num =0;
                num_drum = 0;
                screenMode = 0;

                //add back sound
                bgm->play();
                bgm2->stop();
            }
        }
    }

}

void Scene::keyPressEvent(QKeyEvent *event)
{
    if(screenMode == 1 && num_drum > 1)
    {
        if(20 > drum_list[num]->pos().x() && -19< drum_list[num]->pos().x())
        {
            if(event->key() == Qt::Key_A)
            {
                if(rand_list[num]==1)
                {
                    removeItem(drum_list[num]);
                    num++;
                    score1->increase_shit1();
                    shit_hit1->play();
                }
            }

            if(event->key() == Qt::Key_D)
            {
                if(rand_list[num]==2)
                {
                    removeItem(drum_list[num]);
                    num++;
                    score1->increase_shit2();
                    shit_hit2->play();
                }
            }
        }
    }
}
