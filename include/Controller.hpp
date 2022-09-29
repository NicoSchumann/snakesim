#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <SFML/Window.hpp>
//#include <X11/Xlib.h>
#include <memory>
#include <random>

#include "Snake.hpp"


class Controller
{
public:
    Controller(Snake & snake, Board & board);
    void inform();

    virtual void run() = 0;
protected:
    std::shared_ptr<Snake> _snake;
    std::shared_ptr<Board> _board;
};

class HumanController : public Controller
{
public:
    HumanController(sf::Window & win, Snake & snake, Board & board);

    void run() override;
private:
    sf:: Window & _window;
    sf::Event _event;
};


#endif