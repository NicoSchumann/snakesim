#include "Game.hpp"
#include <chrono>
#include <thread>
#include <future>

Game::Game( Board & board)
: _board{board}
{
  
    _engine = std::mt19937(_dev());
    _randomW = std::uniform_int_distribution<std::size_t>(std::size_t(0), std::size_t(_board.width()-1));
    _randomH = std::uniform_int_distribution<std::size_t>(std::size_t(0), std::size_t(_board.height()-1));

    sf::Vector2<std::size_t> head;
    head.x = _randomW(_engine);
    head.y = _randomH(_engine);
    _snake = std::make_unique<Snake>(_board, head);

    _snakeDisplay = std::make_shared<Renderer>(board); 
    _controller = std::make_shared<Controller>(_snakeDisplay->getWindow(), *_snake);
}


void Game::run()
{
    std::future<void> ftr = std::async( &Renderer::draw, _snakeDisplay);
    std::future<void> ftr_controller = std::async(&Controller::run, _controller);

    while( _snakeDisplay->getWindow().isOpen())

    ftr_controller.wait();
    ftr.wait();
}
