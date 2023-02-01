#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include <iostream>
#include <memory>
#include "score.h"
Game::Game()
    : m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 500), "Pong")),
    m_p1(std::make_unique<Paddle>(0, 200)),
    m_p2(std::make_unique<Paddle>(980, 200)),
    m_ball(std::make_unique<Ball>(rand() % 200 + 500, rand() % 100 + 250)),
    m_score(std::make_unique<Score>()){}

void Game::run() {
    while (m_window->isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (m_window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            m_window->close();
        }
    }
}

void Game::update() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_p1->m_speed = -3;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_p1->m_speed = 3;
    }
    else {
        m_p1->m_speed = 0;
    }

    // control the second paddle to follow the ball
    if (m_ball->getPosition().y + m_ball->getRadius() >
        m_p2->getPosition().y + m_p2->getSize().y / 2) {
        m_p2->m_speed = 3;
    }
    else if (m_ball->getPosition().y + m_ball->getRadius() <
        m_p2->getPosition().y + m_p2->getSize().y / 2) {
        m_p2->m_speed = -3;
    }
    else {
        m_p2->m_speed = 0;
    }

    m_p1->update();
    m_p2->update();
    m_ball->update(*m_p1, *m_p2);
    m_score->update(Score::hit, 0);
}

void Game::render() {
    m_window->clear();
    m_window->draw(*m_p1);
    m_window->draw(*m_p2);
    m_window->draw(*m_ball);
    m_window->draw(*m_score);
    m_window->display();
}