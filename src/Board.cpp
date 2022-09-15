#include "Board.hpp"

Board::Board( size_t width, size_t height)
: _width{width}, _height{height}, _board(width*height)
{

}
