#include "papel.h"

Papel::Papel(float px, float py){

    rowPixmap = 0;
    colPixmap = 0;
    width = 50;
    height = 50;
    stripe = new QPixmap(":/img/paper.png");
    posX = px;
    posY = py;

}


float Papel::getPosX(){
    return posX;
}

float Papel::getPosY(){
    return posY;
}

float Papel::getVelX(){
    return velX;
}

float Papel::getVelY(){
    return velY;
}

void Papel::setVelocity(float a, float b){
    velX = a;
    velY = b;
}

void Papel::move(){
    posX += getVelX() * dt;
    posY += getVelY() * dt;

    setPos(getPosX(), getPosY());
}

void Papel::checkColisionBounds(){

    if (getPosX() < widthCollision || getPosY() < heightCollision ){

        setVelocity(-1*getVelX(), -1*getVelY());
    }

    if (getPosX() > (horlimit - widthCollision) || getPosY() > (verlimit - heightCollision)) {
        setVelocity(-1*getVelY(), -1*getVelX());
    }
}

QRectF Papel::boundingRect() const{
    return QRectF(0, 0, width, height);
}

void Papel::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget){
    QPixmap scaled = stripe->scaled(QSize(50, 50));
    painter->drawPixmap(0, 0, scaled, colPixmap, rowPixmap, width, height);
    Q_UNUSED(option);
    Q_UNUSED(widget);

}

