#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>

struct Point
{
    int x, y;
    Point(int x = 0, int y = 0);
};
Point operator+(const Point & lhs, const Point & rhs);
Point operator-(const Point & lhs, const Point & rhs);

enum class Cell { kEmpty, kObstacle, kFruit };

std::ostream & operator<<(std::ostream & os, const Cell & cell);
std::istream & operator>>(std::istream & is, Cell & cell);


class Board
{
public:
    Board(size_t width, size_t height);
    Board();
    ~Board() = default;

    inline Cell &at(size_t x, size_t y);
    inline Cell at(size_t x, size_t y) const;
    inline size_t width() const;
    inline size_t height() const;

    std::vector<Point> & getFruits();

private:
    size_t _width;
    size_t _height;
    std::vector<Cell> _matrix;
    std::vector<Point> _fruits;
};


std::istream &operator>>(std::istream &is, Board &board);
std::ostream &operator<<(std::ostream &os, const Board &board);

#endif