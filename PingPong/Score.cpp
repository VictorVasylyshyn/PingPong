#include <SFML/Graphics.hpp>
#include "Score.h"

Score::Score() {
	this->setPosition(500, 50);
	this->m_font.loadFromFile("arial.ttf");
	this->setCharacterSize(24);
	this->setFont(m_font);
	this->setFillColor(sf::Color::White);
	this->setString("0");
}

void Score::update(int hit) {
	this->setString(std::to_string(hit));
}