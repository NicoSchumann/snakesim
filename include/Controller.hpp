#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <SFML/Window.hpp>
#include <memory>
#include <random>

#include "Snake.hpp"

class Controller
{
public:
    Controller(sf::Window & win, Snake & snake);

    void run();
    sf::Keyboard::Key getPressedKey();
private:
    sf::Window & _window;
    sf::Event _event;
    sf::Keyboard::Key _direction;
    std::unique_ptr<Snake> _snake;
};

#endif