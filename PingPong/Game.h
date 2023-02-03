#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <list>
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"
#include "GameObject.h"

class Game{
public:
    void run();

private:
    void update();
    void render();

private:
    sf::RenderWindow m_window;
    std::list<std::shared_ptr<GameObject>> m_objects;
    std::shared_ptr<Paddle> m_leftPaddle;
    std::shared_ptr<Paddle> m_rightPaddle;
    std::shared_ptr<Ball> m_ball;
    std::shared_ptr<Score> m_leftScore;
    std::shared_ptr<Score> m_rightScore;
};