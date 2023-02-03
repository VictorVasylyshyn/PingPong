#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include "Paddle.h"
#include "Ball.h"
#include "score.h"

#pragma comment(lib, "winmm.lib")

Ball::Ball()
{
    shape.setRadius(10);
    shape.setPosition(400, 300);
    shape.setFillColor(sf::Color::White);

    velocity.x = 5;
    velocity.y = 5;
}

void Ball::draw(sf::RenderWindow& window)
{
    window.draw(shape);
}

void Ball::update()
{
    shape.move(velocity);
}