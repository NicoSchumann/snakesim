#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "Board.hpp"

class Snake
{
public:
    Snake( Board & board, sf::Vector2<std::size_t> head );
    sf::Vector2<std::size_t> & getHeadPos();

    void move( sf::Keyboard::Key direction);

private:
    void moveTail();
    Board & _board;
    bool _grow;
    int _size;    /// Length of the snake
    std::vector<sf::Vector2<std::size_t>> _body;
    sf::Keyboard::Key _direction;
};

#endif