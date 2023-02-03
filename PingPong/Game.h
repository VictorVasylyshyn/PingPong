#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <list>
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"
#include "GameObject.h"
class Game
{
public:
    void run();

private:
    void update();

    void render();

private:
    sf::RenderWindow window;
    std::list<std::shared_ptr<GameObject>> objects;
    std::shared_ptr<Paddle> leftPaddle;
    std::shared_ptr<Paddle> rightPaddle;
    std::shared_ptr<Ball> ball;
    std::shared_ptr<Score> leftScore;
    std::shared_ptr<Score> rightScore;
};