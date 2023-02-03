#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "score.h"

void Game::run() {

	m_window.create(sf::VideoMode(800, 600), "Pong");
	m_window.setFramerateLimit(60);
	m_leftPaddle = std::make_shared<Paddle>(10, 300);
	m_rightPaddle = std::make_shared<Paddle>(780, 300);
	m_ball = std::make_shared<Ball>();
	m_leftScore = std::make_shared<Score>(100, 20);
	m_rightScore = std::make_shared<Score>(700, 20);

	m_objects.push_back(m_leftPaddle);
	m_objects.push_back(m_rightPaddle);
	m_objects.push_back(m_ball);
	m_objects.push_back(m_leftScore);
	m_objects.push_back(m_rightScore);


	while (m_window.isOpen()) {
		sf::Event event;
		while (m_window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				m_window.close();
			}
		}

		update();
		render();
	}
}
void Game::update() {
	for (auto object : m_objects)
		object->update();

	sf::Vector2f ballPos = m_ball->m_shape.getPosition();
	sf::Vector2f leftPaddlePos = m_leftPaddle->m_shape.getPosition();
	sf::Vector2f rightPaddlePos = m_rightPaddle->m_shape.getPosition();

	if (m_ball->m_shape.getPosition().y + m_ball->m_shape.getRadius() > rightPaddlePos.y + m_rightPaddle->m_shape.getSize().y / 2) {
		m_rightPaddle->m_shape.move(0, 5);

	}else if (m_ball->m_shape.getPosition().y + m_ball->m_shape.getRadius() < rightPaddlePos.y + m_rightPaddle->m_shape.getSize().y / 2) {
		m_rightPaddle->m_shape.move(0, -5);

	}else {
		m_rightPaddle->m_shape.move(0, 0);
	}

	// check for ball collision with paddles
	if (ballPos.x - 10 < leftPaddlePos.x + 10 && ballPos.x - 10 > leftPaddlePos.x && ballPos.y + 10 > leftPaddlePos.y && ballPos.y - 10 < leftPaddlePos.y + 100) {
		m_ball->m_velocity.x = -m_ball->m_velocity.x;
	}
	if (ballPos.x + 10 > rightPaddlePos.x && ballPos.x + 10 < rightPaddlePos.x + 10 && ballPos.y + 10 > rightPaddlePos.y && ballPos.y - 10 < rightPaddlePos.y + 100){
		m_ball->m_velocity.x = -m_ball->m_velocity.x;
	}

	// check for ball out of bounds
	if (ballPos.y + 10 > 600 || ballPos.y - 10 < 0) {
		m_ball->m_velocity.y = -m_ball->m_velocity.y;
	}
	if (ballPos.x < 0){
		m_rightScore->m_score++;
		m_ball->m_shape.setPosition(400, 300);
	}
	if (ballPos.x > 800){
		m_leftScore->m_score++;
		m_ball->m_shape.setPosition(400, 300);
	}
}

void Game::render() {
	m_window.clear();

	for (auto object : m_objects) {
		object->draw(m_window);
	}

	m_window.display();
}