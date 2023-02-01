#include "Paddle.h"
#include <SFML/Graphics.hpp>

Paddle::Paddle(float x, float y) : sf::RectangleShape(sf::Vector2f(20, 100)) {
    this->setPosition(x, y);
    this->m_speed = 0;
}
void Paddle::update() {
    float y = this->getPosition().y;
    y += this->m_speed;

    if (y < 0) {
        y = 0;
    }
    if (y > 450) {
        y = 450;
    }
    this->setPosition(this->getPosition().x, y);
}