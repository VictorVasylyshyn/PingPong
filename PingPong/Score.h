#pragma once
#include <SFML/Graphics.hpp>
class Score : public sf::Text {
public:

    Score() {
        this->setPosition(500, 50);
        this->m_font.loadFromFile("arial.ttf");
        this->setCharacterSize(24);
        this->setFillColor(sf::Color::White);
        this->setString("0 : 0");
    }
    static int hit;
    void update(int hit, int player2_score) {
        this->setString(std::to_string(hit) + " : " + std::to_string(player2_score));
    }
private:
    sf::Font m_font;
};