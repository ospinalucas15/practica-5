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

    rock1 = new Rock(20, 0, 50);
    rock2 = new Rock(160, 0, 50);
    rock3 = new Rock(300, 0, 50);
    rock4 = new Rock(440, 0, 50);
    rock5 = new Rock(580, 0, 50);

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
}


