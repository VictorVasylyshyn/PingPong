#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Paddle : public GameObject{
public:
    sf::RectangleShape m_shape;

    Paddle(float x, float y);

    void draw(sf::RenderWindow& m_window) override;

    void update() override;
};