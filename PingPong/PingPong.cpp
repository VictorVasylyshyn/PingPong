#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <memory>
#include "Paddle.h"
#include "Ball.h"
#include "Game.h"
#include <random>

int main() {
    srand((unsigned int)time(NULL));
    Game game;
    game.run();

    return 0;
}
