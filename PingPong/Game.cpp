#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Game.h"
#include "Ball.h"
#include "Paddle.h"
#include "score.h"

void Game::run()
{
    window.create(sf::VideoMode(800, 600), "Pong");
    window.setFramerateLimit(60);
    leftPaddle = std::make_shared<Paddle>(10, 300);
    rightPaddle = std::make_shared<Paddle>(780, 300);
    ball = std::make_shared<Ball>();
    leftScore = std::make_shared<Score>(100, 20);
    rightScore = std::make_shared<Score>(700, 20);

    objects.push_back(leftPaddle);
    objects.push_back(rightPaddle);
    objects.push_back(ball);
    objects.push_back(leftScore);
    objects.push_back(rightScore);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        update();
        render();
    }
}
void Game::update()
{
    for (auto object : objects)
        object->update();

    sf::Vector2f ballPos = ball->shape.getPosition();
    sf::Vector2f leftPaddlePos = leftPaddle->shape.getPosition();
    sf::Vector2f rightPaddlePos = rightPaddle->shape.getPosition();

    if (ball->shape.getPosition().y + ball->shape.getRadius() >
        rightPaddlePos.y + rightPaddle->shape.getSize().y / 2) {
        rightPaddle->shape.move(0, 5);
    }
    else if (ball->shape.getPosition().y + ball->shape.getRadius() <
        rightPaddlePos.y + rightPaddle->shape.getSize().y / 2) {
        rightPaddle->shape.move(0, -5);
    }
    else {
        rightPaddle->shape.move(0, 0);
    }
    // check for ball collision with paddles
    if (ballPos.x - 10 < leftPaddlePos.x + 10 && ballPos.x - 10 > leftPaddlePos.x && ballPos.y + 10 > leftPaddlePos.y && ballPos.y - 10 < leftPaddlePos.y + 100)
    {
        ball->velocity.x = -ball->velocity.x;
    }
    if (ballPos.x + 10 > rightPaddlePos.x && ballPos.x + 10 < rightPaddlePos.x + 10 && ballPos.y + 10 > rightPaddlePos.y && ballPos.y - 10 < rightPaddlePos.y + 100)
    {
        ball->velocity.x = -ball->velocity.x;
    }

    // check for ball out of bounds
    if (ballPos.y + 10 > 600 || ballPos.y - 10 < 0)
    {
        ball->velocity.y = -ball->velocity.y;
    }
    if (ballPos.x < 0)
    {
        rightScore->score++;
        ball->shape.setPosition(400, 300);
    }
    if (ballPos.x > 800)
    {
        leftScore->score++;
        ball->shape.setPosition(400, 300);
    }
}

void Game::render()
{
    window.clear();

    for (auto object : objects)
        object->draw(window);

    window.display();
}