#include "tijera.h"

Tijera::Tijera(float px, float py){

    rowPixmap = 0;
    colPixmap = 0;
    width = 50;
    height = 50;
    stripe = new QPixmap(":/img/scissors.png");
    posX = px;
    posY = py;

}


float Tijera::getPosX(){
    return posX;
}

float Tijera::getVelX(){
    return velX;
}

void Tijera::setVelocity(float a){
    velX = a;
}

void Tijera::move(){
    posX += getVelX() * dt;

    setPos(getPosX(), posY);
}

void Tijera::checkColisionBounds(){
    if (getPosX() < widthCollision || getPosX() > (horlimit - widthCollision)){
        
        setVelocity(-1*getVelX());
    }
}

QRectF Tijera::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Tijera::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    QPixmap scaled = stripe->scaled(QSize(50, 50));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

