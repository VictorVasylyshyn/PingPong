#pragma once
#include <SFML/Graphics.hpp>
class Paddle : public sf::RectangleShape {
public:
    float m_speed;
    Paddle(float x, float y);
    void update();
};
