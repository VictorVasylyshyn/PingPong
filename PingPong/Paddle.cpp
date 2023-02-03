#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Paddle.h"


Paddle::Paddle(float x, float y)
{
	shape.setSize(sf::Vector2f(10, 100));
	shape.setPosition(x, y);
}

void Paddle::draw(sf::RenderWindow& window){
	window.draw(shape);
}

void Paddle::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && shape.getPosition().y > 0)
    {
        shape.move(0, -5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && shape.getPosition().y < 500)
    {
        shape.move(0, 5);
    }
}
