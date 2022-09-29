#include <chrono>
#include <thread>

#include "Snake.hpp"
#include "Board.hpp"

Snake::Snake( Board & board, sf::Vector2<std::size_t> head )
: _board(board), _isAlive(true), _grow(false), _size(1), _direction(sf::Keyboard::Key::Down)
{
    _body.push_back(head);
    _board.subscribe(this);
}
Snake::~Snake() { _board.unsubscribe(this); }

sf::Vector2<std::size_t> & Snake::getHeadPos()
{ 
    return _body[0];
}
void Snake::setDirection( sf::Keyboard::Key dir) { _direction = dir; }

void Snake::setDead() { _isAlive = false; };
bool Snake::isDead() { return !_isAlive; }
void Snake::run()
{
    while(_isAlive) {
        move(_direction);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

void Snake::inform()
{
    /// TODO: This should moved to AIcontroller. Here nothing to do.
}

void Snake::move(sf::Keyboard::Key dir)
{
    // tail segments should be moved first
    moveTail();


    // move the snake head
    if (dir == sf::Keyboard::Left && _direction != sf::Keyboard::Right)
    {
        --_body[0].x;
        _direction = dir;
    }
    else if (dir == sf::Keyboard::Right && _direction != sf::Keyboard::Left)
    {
        ++_body[0].x;
        _direction = dir;
    }
    else if (dir == sf::Keyboard::Up && _direction != sf::Keyboard::Down)
    {
        --_body[0].y;
        _direction = dir;
    }
    else if (dir == sf::Keyboard::Down && _direction != sf::Keyboard::Up)
    {
        ++_body[0].y;
        _direction = dir;
    }

    // because the board is a donut
    _body[0].x %= _board.width();
    _body[0].y %= _board.height();

    // eats snake food?
    if( _board.at(_body[0].x, _body[0].y) == Cell::kFruit )
    {
        _grow = true;
        ++ _size;
    }

    // mark new head position as part of the snake positiion on the board
    _board.at(_body[0].x, _body[0].y) = Cell::kSnake;
}

void Snake::moveTail()
{
    // copy tail_end for potential growing position
    sf::Vector2<std::size_t> tail_end = _body.back();

    // move all tail segments
    for( int i = _body.size()-1; i > 0; --i)
    {
        _body[i] = _body[i-1];
    }
    
    // Should the snake grow?
    if( _grow)
    {
        _body.push_back(tail_end);
        _grow = false;  // reset flag
    }
    // if not, release the old tail position from the board
    else
    {
        _board.at(tail_end.x, tail_end.y) = Cell::kEmpty;
    }

}
