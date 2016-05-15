#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new Scene();
    ui->graphicsView->setScene(scene);
    scene->setSceneRect(5,5,600,400);
    settingBg();
    ui->graphicsView->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*setting background*/
void MainWindow::settingBg()
{
    QImage bg;
    bg.load(":/image/image/8345569094.jpg");
    bg = bg.scaled(610,410);
    scene->setBackgroundBrush(bg);
    scene->Init();
}
