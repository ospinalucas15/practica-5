#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QkeyEvent>
#include <QTimer>
#include "rock.h"
#include "tijera.h"
#include "papel.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int countRocks = 0;
    int countTijeras = 0 ;
    int countPapel = 0;

public slots:
    void actualizarEscena();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_3_released();
    void on_pushButton_4_released();
    void on_pushButton_5_released();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene = nullptr;
    QTimer* timer = nullptr;
    Rock* rock1 = nullptr;
    Rock* rock2 = nullptr;
    Rock* rock3 = nullptr;
    Rock* rock4 = nullptr;
    Rock* rock5 = nullptr;
    Papel* papel1 = nullptr;
    Papel* papel2 = nullptr;
    Papel* papel3 = nullptr;
    Papel* papel4 = nullptr;
    Papel* papel5 = nullptr;
    Tijera* tijera1 = nullptr;
    Tijera* tijera2 = nullptr;
    Tijera* tijera3 = nullptr;
    Tijera* tijera4 = nullptr;
    Tijera* tijera5 = nullptr;
    

};
#endif // MAINWINDOW_H
