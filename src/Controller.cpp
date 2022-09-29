#include <SFML/Window.hpp>
#include "Controller.hpp"
#include "Board.hpp"
#include <future>


Controller::Controller(Snake & snake, Board & board)
{
    _snake = std::shared_ptr<Snake>(&snake);
    _board = std::shared_ptr<Board>(&board);
}

void Controller::inform()
{
    _board->fruitEaten();
}

HumanController::HumanController(sf::Window & win, Snake & snake, Board & board) 
: Controller(snake, board), _window(win)
{}

void HumanController::run()
{
    std::future<void> snake_ftr = std::async(&Snake::run, _snake);

    // deactivate window's OpenGL context
    _window.setActive(false);

    while( _window.isOpen() && !_snake->isDead())
    {
        // blocks while waiting for an event
        while(_window.waitEvent(_event))
        {
            if( _event.type == sf::Event::Closed)
            {
                _window.close();
                return;
            }
            else if( _event.type == sf::Event::KeyPressed)
            {
                switch(_event.key.code)
                {
                    case sf::Keyboard::Left:
                    case sf::Keyboard::Right:
                    case sf::Keyboard::Up:
                    case sf::Keyboard::Down:
                        _snake->setDirection(_event.key.code);
                        break;
                    default:
                         ;
                }
            }
        }

    }
    snake_ftr.wait();
}
