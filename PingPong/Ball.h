#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
class Ball : public sf::CircleShape {
public:
    sf::Vector2f m_velocity;
    Ball(float x, float y);
    void update(Paddle& p1, Paddle& p2);
    
    
};