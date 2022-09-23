#include <SFML/Window.hpp>
#include "Controller.hpp"

Controller::Controller(sf::Window & win, Snake & snake) 
: _window(win)
{
    _snake = std::move(std::unique_ptr<Snake>(&snake));
}

void Controller::run()
{
    while( _window.isOpen() )
    {
        // blockcs while waiting for an event
        while(_window.waitEvent(_event))
        {
            if( _event.type == sf::Event::Closed)
            {
                _window.close();
            }
            else if( _event.type == sf::Event::KeyPressed)
            {
                switch(_event.key.code)
                {
                    case sf::Keyboard::Left:
                    case sf::Keyboard::Right:
                    case sf::Keyboard::Up:
                    case sf::Keyboard::Down:
                        _direction = _event.key.code;
                        break;
                    default:
                         ;
                }
            }
        }

    }
}

sf::Keyboard::Key Controller::getPressedKey() { return _direction; }
