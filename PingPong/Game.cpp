#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "score.h"

Game::Game()
	: m_window(std::make_unique<sf::RenderWindow>(sf::VideoMode(1000, 500), "Pong")),
	m_p1(std::make_unique<Paddle>(0, 200)),
	m_p2(std::make_unique<Paddle>(980, 200)),
	m_ball(std::make_unique<Ball>(rand() % 200 + 500, rand() % 100 + 250)),
	m_score(std::make_unique<Score>()) {}

void Game::run() {
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

	while (m_window->isOpen()) {
		processEvents();

		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame) {
			timeSinceLastUpdate -= TimePerFrame;
			update();
		}

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
		m_p1->m_speed = -4;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		m_p1->m_speed = 4;
	}
	else {
		m_p1->m_speed = 0;
	}

	// control the second paddle to follow the ball
	if (m_ball->getPosition().y + m_ball->getRadius() >
		m_p2->getPosition().y + m_p2->getSize().y / 2) {
		m_p2->m_speed = 4;
	}
	else if (m_ball->getPosition().y + m_ball->getRadius() <
		m_p2->getPosition().y + m_p2->getSize().y / 2) {
		m_p2->m_speed = -4;
	}
	else {
		m_p2->m_speed = 0;
	}

	m_p1->update();
	m_p2->update();
	m_ball->update(*m_p1, *m_p2);
	m_score->update(Score::hit);
}

void Game::render() {
	m_window->clear();
	m_window->draw(*m_p1);
	m_window->draw(*m_p2);
	m_window->draw(*m_ball);
	m_window->draw(*m_score);
	m_window->display();
}