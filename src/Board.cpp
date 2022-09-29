#include <random>

#include "Board.hpp"
#include "Snake.hpp"

Board::Board( size_t width, size_t height)
: _width{width}, _height{height}, _matrix(width*height)
{
    spawnFruit();
}


void Board::subscribe(Snake *snake)
{
    if (snake != nullptr)
    {
        for (auto subscriber : _subscriberList)
        {
            if (snake == subscriber)
            {
                return; // snake is yet in the subscriber list so do nothing
            }
        }
        _subscriberList.push_back(snake);
    }
}

void Board::unsubscribe(Snake *snake)
{
    if( snake != nullptr)
    {
        for (auto itr = _subscriberList.begin(); itr != _subscriberList.end(); ++itr)
        {
            if( *itr == snake)
            {
                _subscriberList.erase(itr);
                return;
            }
        }
    }
}

void Board::inform() const
{
    for( auto subscriber : _subscriberList)
    {
        subscriber->inform();
    }
}

void Board::spawnFruit()
{
    static std::random_device rd;
    static std::mt19937 reng{rd()};
    static std::uniform_int_distribution<std::size_t> random_x{0, width()-1};
    static std::uniform_int_distribution<std::size_t> random_y{0,height()-1};

    while(true)
    {
        std::size_t x = random_x(reng);
        std::size_t y = random_y(reng);
        if( at(x,y) == Cell::kEmpty)
        {
            at(x,y) = Cell::kFruit;
            _fruit.x = x;
            _fruit.y = y;
            inform();
            return;
        }
    }
}

void Board::fruitEaten()
{
    spawnFruit();
}


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