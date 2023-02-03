#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Score : public GameObject{
public:
	int m_score;
	sf::Text m_text;
	sf::Font m_font;

	Score(float x, float y);

	void draw(sf::RenderWindow& window) override;

	void update() override;
};