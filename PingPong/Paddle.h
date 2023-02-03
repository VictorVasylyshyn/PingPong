#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Paddle : public GameObject
{
public:
    sf::RectangleShape shape;

    Paddle(float x, float y);

    void draw(sf::RenderWindow& window) override;

    void update() override;
};