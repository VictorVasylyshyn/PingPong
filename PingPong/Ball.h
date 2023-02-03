#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "GameObject.h"

class Ball : public GameObject
{
public:
    sf::CircleShape shape;
    sf::Vector2f velocity;

    Ball();

    void draw(sf::RenderWindow& window) override;

    void update() override;
};