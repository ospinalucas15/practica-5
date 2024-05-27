#ifndef TIJERA_H
#define TIJERA_H

#include <QGraphicsItem>
#include <QPixmap>
#include <QPainter>
#include <QTimer>


class Tijera : public QGraphicsItem {
    
public:
    Tijera(float px, float py);

    float getPosX();
    float getVelX();

    void setVelocity(float a);

    void move();
    void checkColisionBounds();

    QRectF boundingRect() const;
    void paint(QPainter*, const QStyleOptionGraphicsItem*, QWidget*);

private:

    float posX;
    float posY;
    float velX = 50;

    const float widthCollision = 5;
    const float horlimit = 700;
    const float dt = 0.1;
    
    QPixmap* stripe = nullptr;
    qreal rowPixmap, colPixmap, width, height;

};
#endif // TIJERA_H
