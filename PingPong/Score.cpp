#include <SFML/Graphics.hpp>
#include "Score.h"

Score::Score(float x, float y) {
	m_score = 0;

	m_font.loadFromFile("arial.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(24);
	m_text.setPosition(x, y);
	m_text.setFillColor(sf::Color::White);
}

void Score::draw(sf::RenderWindow& m_window) {
	m_window.draw(m_text);
}

void Score::update() {
	m_text.setString(std::to_string(m_score));
}