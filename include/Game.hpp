#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Window/Keyboard.hpp>
#include <random>
#include "Controller.hpp"
#include "Renderer.hpp"
#include "Board.hpp"
#include "Snake.hpp"

class Game
{
public:
    Game( Board & board);
    void run();

private:
    Board & _board;
    std::shared_ptr<Renderer> _snakeDisplay;
    std::shared_ptr<Controller> _controller;

    std::random_device _dev;
    std::mt19937 _engine;
    std::uniform_int_distribution<std::size_t> _randomW;
    std::uniform_int_distribution<std::size_t> _randomH;

    std::unique_ptr<Snake> _snake;

};


#endif