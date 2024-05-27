#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "rock.h"
#include "tijera.h"
#include "papel.h"

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


    timer->start(20);

    connect(timer, SIGNAL(timeout()), this, SLOT(actualizarEscena()));


}


MainWindow::~MainWindow()
{
    delete timer;
    delete scene;
    delete ui;

}


void MainWindow::on_pushButton_3_clicked()
{

    if (countRocks == 1){
        scene->addItem(new Rock(20, 10));
    }

    else if (countRocks == 2){
        scene->addItem(new Rock(160, 10));
    }

    else if (countRocks == 3){
        scene->addItem(new Rock(300, 10));
    }

    else if (countRocks == 4){
        scene->addItem(new Rock(440, 10));
    }

    else if (countRocks == 5){
        scene->addItem(new Rock(580, 10));
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    if (countPapel == 1){
        scene->addItem(new Papel(10, 100));
    }

    else if (countPapel == 2){
        scene->addItem(new Papel(10, 240));
    }

    else if (countPapel == 3){
        scene->addItem(new Papel(380, 500));
    }

    else if (countPapel == 4){
        scene->addItem(new Papel(520, 500));
    }

    else if (countPapel == 5){
        scene->addItem(new Papel(660, 500));
    }
}

void MainWindow::on_pushButton_5_clicked()
{

    if (countTijeras == 1){
        scene->addItem(new Tijera(0, 100));
    }

    else if (countTijeras == 2){
        scene->addItem(new Tijera(0, 240));
    }

    else if (countTijeras == 3){
        scene->addItem(new Tijera(0, 380));
    }

    else if (countTijeras == 4){
        scene->addItem(new Tijera(0, 520));
    }

    else if (countTijeras == 5){
        scene->addItem(new Tijera(0, 600));
    }
}

void MainWindow::on_pushButton_3_released()
{
    countRocks += 1;
}

void MainWindow::on_pushButton_4_released()
{
    countPapel += 1;
}

void MainWindow::on_pushButton_5_released()
{
    countTijeras += 1;
}

void MainWindow::actualizarEscena(){

    auto listaElementosEscena = scene->items();
    for (auto elemento : listaElementosEscena){
        Rock* roca = dynamic_cast<Rock*>(elemento);

        if (roca != nullptr){
            roca->move();
            roca->checkColisionBounds();
        }
        else{
            Tijera* tijera = dynamic_cast<Tijera*>(elemento);
            if (tijera != nullptr){
                tijera->move();
                tijera->checkColisionBounds();
            }
            else {
                Papel* papel = dynamic_cast<Papel*>(elemento);
                    if (papel != nullptr){
                       papel->move();
                       papel->checkColisionBounds();
                    }
                //return;
            }

        }
    }
}








