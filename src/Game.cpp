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
    _board.at(head.x,head.y) = Cell::kSnake;

    _renderer = std::make_shared<Renderer>(board); 
    _humanController = std::make_shared<HumanController>(_renderer->getWindow(), *_snake, _board);
}


void Game::run()
{  
    std::future<void> ftr_controller = std::async(&Controller::run, _humanController);

    /// TODO: When ftr_controller terminates, ftr_renderer runs
    /// still, so it tries to draw to a deleted RenderWindow
    /// -> seg fault
    std::future<void> ftr_renderer = std::async( &Renderer::draw, _renderer);

    // terminate when window will closed;
    while( _renderer->getWindow().isOpen());

    ftr_controller.wait();
    ftr_renderer.wait();
}
