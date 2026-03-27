#pragma once;
#include <SFML/Graphics.hpp>
using namespace sf;

class Bat
{
    // Declare Position
    Vector2f m_Position;

    // declare Shape
    RectangleShape m_Shape;

    // declare speed
    float m_Speed = 1000.0f;

    // declare bool var for right and ledt movement
    bool m_movingRight = false;
    bool m_movingLeft = false;

public:
    // declare construcor method
    Bat(float startX, float startY);

    // declare get_position() method
    FloatRect get_Position();

    // declare get_shape()
    RectangleShape get_Shape();
    // declare moveRight()
    void moveRight();
    // declare moveLeft()
    void moveLeft();

    // declare stopLeft()
    void stopLeft();

    // declare stopRight()
    void stopRight();
    // declare update()
    void update(Time dt);
};