#include "Board.hpp"

Board::Board( size_t width, size_t height)
: _width{width}, _height{height}, _matrix(width*height)
{}


std::ostream & operator<<(std::ostream & os, const Cell & cell)
{
    switch(cell) {
        case Cell::kEmpty: os << "."; break;
        case Cell::kSnake: os << "S"; break;
        case Cell::kObstacle: os << "X"; break;
        case Cell::kFruit: os << "F"; break;
    }
    return os;
}

std::istream & operator>>(std::istream & is, Cell & cell)
{
    char ch;
    is >> ch;
    switch(ch) {
        case '.': cell = Cell::kEmpty; break;
        case 's': cell = Cell::kSnake; break;
        case 'X': cell = Cell::kObstacle; break;
        case 'F': cell = Cell::kFruit; break;
        default: is.setstate(std::ios_base::failbit);
    }
    return is;
}

std::istream &operator>>(std::istream &is, Board &board)
{
    int width, height;
    is >> width >> height;
    Board brd(width, height);
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            is >> brd.at(x, y);
        }
    }
    board = std::move(brd);

    return is;
}

std::ostream &operator<<(std::ostream &os, const Board &board)
{
    os << board.width() << " " << board.height() << "\n";
    for(size_t y = 0; y < board.height(); ++y)
    {
        for( size_t x = 0; x < board.width(); ++x)
        {
            os << board.at(x,y);
        }
        os << "\n";
    }
    return os;
}