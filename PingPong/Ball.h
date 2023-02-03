#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

class Ball : public GameObject{
public:
    sf::CircleShape m_shape;
    sf::Vector2f m_velocity;

    Ball();

    void draw(sf::RenderWindow& m_window) override;

    void update() override;
};