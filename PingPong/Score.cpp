#include <SFML/Graphics.hpp>
#include "Score.h"

Score::Score(float x, float y) {
	score = 0;

	font.loadFromFile("arial.ttf");
	text.setFont(font);
	text.setCharacterSize(24);
	text.setPosition(x, y);
	text.setFillColor(sf::Color::White);
}

void Score::draw(sf::RenderWindow& window) {
	window.draw(text);
}

void Score::update() {
	text.setString(std::to_string(score));
}