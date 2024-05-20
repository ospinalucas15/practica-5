#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rock.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene(this);
    timer = new QTimer;

    scene->setSceneRect(0, 0, 700, 700);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->resize(scene->width()+2, scene->height()+2);
    this->resize(ui->graphicsView->width()+100, ui->graphicsView->height()+100);

    timer->stop();

    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEscena()));

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete timer;

}



void MainWindow::on_pushButton_3_clicked()
{
    timer->start(20);

    //countRocks += 1;


    // if (countRocks == 1){

    //     rock1 = new Rock(20, 10);
    //     scene->addItem(rock1);
    // }

    // else if (countRocks == 2){


    //     rock2 = new Rock(160, 10);
    //     scene->addItem(rock2);
    // }

    // else if (countRocks == 3){
        

    //     rock3 = new Rock(300, 10);
    //     scene->addItem(rock3);
    // }

    // else if (countRocks == 4){


    //     rock4 = new Rock(440, 10);
    //     scene->addItem(rock4);
    // }

    // else if (countRocks == 5){

    //     rock5 = new Rock(580, 10);
    //     scene->addItem(rock5);
    // }

    rock1 = new Rock(20, 10);
    rock2 = new Rock(160, 10);
    rock3 = new Rock(300, 10);
    rock4 = new Rock(440, 10);
    rock5 = new Rock(580, 10);

    scene->addItem(rock1);
    scene->addItem(rock2);
    scene->addItem(rock3);
    scene->addItem(rock4);
    scene->addItem(rock5);
}

void MainWindow::actualizarEscena(){

    rock1->move();
    rock2->move();
    rock3->move();
    rock4->move();
    rock5->move();

    rock1->checkColisionBounds();
    rock2->checkColisionBounds();
    rock3->checkColisionBounds();
    rock4->checkColisionBounds();
    rock5->checkColisionBounds();
}




