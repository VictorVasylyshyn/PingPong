#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include "Ball.h"
#include "Paddle.h"
#include "Score.h"
class Game {
public:
    Game();
    void run();
private:
    void processEvents();
    void update();
    void render();
    std::unique_ptr<sf::RenderWindow> m_window;
    std::unique_ptr<Paddle> m_p1;
    std::unique_ptr<Paddle> m_p2;
    std::unique_ptr<Ball> m_ball;
    std::unique_ptr<Score> m_score;
    
};