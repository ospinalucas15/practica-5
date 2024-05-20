#ifndef ROCK_H
#define ROCK_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>



class Rock : public QGraphicsItem {
    
public:
    Rock(float px, float py, float r);

    float getPosY();
    float getVelY();
    float getHeight();

    void setVelocity(float a);

    void move();
    void checkColisionBounds();

    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

private:

    float posX;
    float posY;
    float velY = 50;
    float radio;

    const float dt = 0.1;
    const int vertlim = 800;

    QPixmap* stripe = nullptr;
    qreal rowPixmap, colPixmap, width, height;

};

#endif // ROCK_H
