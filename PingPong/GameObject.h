#pragma once
#include <SFML/Graphics.hpp>
class GameObject {
public:
    virtual void draw(sf::RenderWindow& m_window) = 0;
    virtual void update() = 0;
};