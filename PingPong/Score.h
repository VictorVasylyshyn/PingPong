#pragma once
#include <SFML/Graphics.hpp>
class Score : public sf::Text {
public:
	Score();
	static int hit;
	void update(int hit);

private:
	sf::Font m_font;

};
