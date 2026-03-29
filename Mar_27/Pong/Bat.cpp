#include "Bat.h"

Bat::Bat(float startX, float startY){
    bat_pos.x = startX;
    bat_pos.y = startY;

    bat_shape.setSize(sf::Vector2f(100.0,10.0));
    bat_shape.setPosition(bat_pos);
}

FloatRect Bat::getPosition(){
    return bat_shape.getGlobalBounds();
}

RectangleShape Bat::getShape(){
    return bat_shape;
}

void Bat::moveLeft(){
    bat_movingLeft = true;
}

void Bat::moveRight(){
    bat_movingRight = true;
}

void Bat::stopLeft(){
    bat_movingLeft = false;
}

void Bat::stopRight(){
    bat_movingRight = false;
}

void Bat::update(Time dt){
    if(bat_movingLeft){
        bat_pos.x -= bat_speed * dt.asSeconds();
    }
    if(bat_movingRight){
        bat_pos.x += bat_speed * dt.asSeconds();
    }

    bat_shape.setPosition(bat_pos);
}