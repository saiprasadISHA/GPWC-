#include "Ball.h"
// Definition of all methods of Ball class are written below
// Contructor
Ball::Ball(float startX, float startY)
{
    m_Position.x = startX;
    m_Position.y = startY;
    m_Shape.setRadius(10.0);
    m_Shape.setPosition(m_Position);
    // getPosition()
    FloatRect Ball::getPosition()
    {
        return m_Shape.getGlobalBounds();
    }

    // getShape()
    CircleShape Ball::getShape()
    {
        return m_Shape;
    }

    // getXVelocity
    float Ball::getXVelocity()
    {
        return m_DirectionX;
    }
    // reboundSides()
    void Ball::reboundSides()
    {
        m_DirectionX = -m_DirectionX;
    }
    // reboundBatOrTop()
    void Ball::reboundBatOrTop()
    {
        m_DirectionY = -m_DirectionY;
    }
    // reboundBottom()
    void Ball::reboundBottom()
    {
        m_DirectionY = -m_DirectionY;
        m_Shape.setPosition(500, 0);
    }
    // update(Time)
    void Ball::update(Time dt)
    {
        m_Position.x += m_DirectionX * m_Speed * dt.asSeconds();
        m_Posion.y += m_DirectionY * m_Speed * dt.asSeconds();
        m_Shape.setPosition(m_Position);
    }
}