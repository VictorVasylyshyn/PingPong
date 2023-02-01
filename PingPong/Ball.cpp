#include <SFML/Graphics.hpp>
#include <iostream>
#include "Paddle.h"
#include "Ball.h"
#include "score.h"
#include <Windows.h>
#pragma comment(lib, "winmm.lib")
int Score::hit = 0;
Ball::Ball(float x, float y) : sf::CircleShape(10) {
    this->setPosition(x, y);
    this->m_velocity = sf::Vector2f(3, 3);
}

void Ball::update(Paddle& p1, Paddle& p2) {
    this->move(this->m_velocity);

    if (this->getPosition().y <= 0 || this->getPosition().y >= 500) {
        this->m_velocity.y *= -1;
    }

    if (this->getGlobalBounds().intersects(p1.getGlobalBounds())) {
        this->m_velocity.x *= -1;
        PlaySound(TEXT("hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
        Score::hit++;
        
    }

    if (this->getGlobalBounds().intersects(p2.getGlobalBounds())) {
        this->m_velocity.x *= -1;
        PlaySound(TEXT("hit.wav"), NULL, SND_FILENAME | SND_ASYNC);
       
    }

    if (this->getPosition().x <= 0) {
        std::cout << "Player 2 wins!" << std::endl;
        exit(0);
    }

    if (this->getPosition().x >= 990) {
        std::cout << "Player 1 wins!" << std::endl;
        exit(0);
    }
}