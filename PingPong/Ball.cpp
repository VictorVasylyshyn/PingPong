#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Ball.h"

Ball::Ball()
{
    m_shape.setRadius(10);
    m_shape.setPosition(400, 300);
    m_shape.setFillColor(sf::Color::White);

    m_velocity.x = 5;
    m_velocity.y = 5;
}

void Ball::draw(sf::RenderWindow& m_window)
{
    m_window.draw(m_shape);
}

void Ball::update()
{
    m_shape.move(m_velocity);
}
