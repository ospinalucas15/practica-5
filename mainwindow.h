#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QkeyEvent>
#include <QTimer>
#include "rock.h"


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

public slots:
    void on_pushButton_3_clicked();
    void actualizarEscena();

private:
    Ui::MainWindow *ui;
    QGraphicsScene* scene = nullptr;
    QTimer* timer = nullptr;
    Rock* rock1 = nullptr;
    Rock* rock2 = nullptr;
    Rock* rock3 = nullptr;
    Rock* rock4 = nullptr;
    Rock* rock5 = nullptr;

};
#endif // MAINWINDOW_H
