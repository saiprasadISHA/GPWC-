#include "Bat.h"
using namespace sf;
// Definition of all methods of Bat class are written below
// Contructor
Bat::Bat(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setSize(Vector2f(100.0, 10.0));
    m_Shape.setPosition(m_Position);
}
// getPosition()
FloatRect Bat::get_Position()
{
    return m_Shape.getGlobalBounds();
}
// getShape()
RectangleShape Bat::get_Shape()
{
    return m_Shape;
}
// moveRight()
void Bat::moveRight()
{
    m_movingLeft = true;
}
// moveLeft()
void Bat::moveRight()
{
    m_movingRight = true;
}

// stopRight()
void Bat::stopRight()
{
    m_movingRight = false;
}

// stopLeft()
void Bat::stopLeft()
{
    m_movingLeft = false;
}

// update()
void Bat::update(Time dt)
{
    if (m_movingRight)
    {
        m_Position.x += m_Speed * dt.asSeconds();
    }
    if (m_movingLeft)
    {
        m_Position.x += m_Speed * dt.asSeconds();
    }
}