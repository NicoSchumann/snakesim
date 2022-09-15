#include "Board.hpp"

Point::Point( int xx, int yy) : x{xx}, y{yy} {};

Point operator+(const Point & lhs, const Point & rhs) {
    return Point(lhs.x+rhs.x, lhs.y+rhs.y);
}
Point operator-(const Point & lhs, const Point & rhs) {
    return Point(lhs.x-rhs.x, lhs.y-rhs.y); 
}

Board::Board( size_t width, size_t height)
: _width{width}, _height{height}, _matrix(width*height)
{}

Board::Board() : Board(20,10) {}

size_t Board::width() const { return _width; }
size_t Board::height() const { return _height; }

Cell & Board::at( size_t x, size_t y) { return _matrix[x+y*_width]; }
Cell Board::at(size_t x, size_t y) const{ return _matrix[x+y*_width]; }

std::ostream & operator<<(std::ostream & os, const Cell & cell)
{
    switch(cell) {
        case Cell::kEmpty: os << "."; break;
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
        case 'X': cell = Cell::kObstacle; break;
        case 'F': cell = Cell::kFruit; break;
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
            os << board.at(x,y) << " ";
        }
        os << "\n";
    }
    return os;
}