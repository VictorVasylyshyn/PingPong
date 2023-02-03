#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Paddle.h"


Paddle::Paddle(float x, float y){
	m_shape.setSize(sf::Vector2f(10, 100));
	m_shape.setPosition(x, y);
}

void Paddle::draw(sf::RenderWindow& m_window){
	m_window.draw(m_shape);
}

void Paddle::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up) && m_shape.getPosition().y > 0){
        m_shape.move(0, -5);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down) && m_shape.getPosition().y < 500){
        m_shape.move(0, 5);
    }
}
