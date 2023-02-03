#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
class Score : public GameObject
{
public:
	int score;
	sf::Text text;
	sf::Font font;

	Score(float x, float y);

	void draw(sf::RenderWindow& window) override;

	void update() override;
};