#include "rock.h"

Rock::Rock(float px, float py, float r){

    rowPixmap = 0;
    colPixmap = 0;
    width = 50;
    height = 50;
    stripe = new QPixmap(":/img/rock.png");
    posX = px;
    posY = py;
    radio = r;

}


float Rock::getPosY(){
    return posY;
}

float Rock::getVelY(){
    return velY;
}

float Rock::getHeight(){
    return radio;
}

void Rock::setVelocity(float a){
    velY = a;
}

void Rock::move(){
    posY += getVelY() * dt;

    setPos(posX, getPosY());
}

void Rock::checkColisionBounds(){
    if (getPosY() > 50 || getPosY() < vertlim - 50){
        
        setVelocity(-1*getVelY());
    }
}

QRectF Rock::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Rock::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    QPixmap scaled = stripe->scaled(QSize(50, 50));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}
