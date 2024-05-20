#ifndef ROCK_H
#define ROCK_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>



class Rock : public QGraphicsItem {
    
public:
    Rock(float px, float py);

    float getPosY();
    float getVelY();

    void setVelocity(float a);

    void move();
    void checkColisionBounds();

    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

private:

    float posX;
    float posY;
    float velY = 50;

    const float heightCollision = 5;
    const float vertlim = 700;
    const float dt = 0.1;
    
    QPixmap* stripe = nullptr;
    qreal rowPixmap, colPixmap, width, height;

};

#endif // ROCK_H
