#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>

enum class Cell { kEmpty, kSnake, kObstacle, kFruit };

std::ostream & operator<<(std::ostream & os, const Cell & cell);
std::istream & operator>>(std::istream & is, Cell & cell);


class Board
{
public:
    Board(size_t width = 80, size_t height = 60);
    ~Board() = default;

    inline Cell & at(size_t x, size_t y);
    inline Cell at(size_t x, size_t y) const;
    inline std::size_t width() const;
    inline std::size_t height() const;

    inline std::vector<sf::Vector2<size_t>> getFruits() const;

private:
    std::size_t _width;
    std::size_t _height;
    std::vector<Cell> _matrix;
    std::vector<sf::Vector2<size_t>> _fruits;
};

// declared as inline
std::size_t Board::width() const { return _width; }
std::size_t Board::height() const { return _height; }
Cell & Board::at( size_t x, size_t y) { return _matrix[x+y*_width]; }
Cell Board::at(size_t x, size_t y) const { return _matrix[x+y*_width]; }
std::vector<sf::Vector2<size_t>> Board::getFruits() const { return _fruits; }


std::istream &operator>>(std::istream &is, Board &board);
std::ostream &operator<<(std::ostream &os, const Board &board);

#endif