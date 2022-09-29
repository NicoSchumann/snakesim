#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <iostream>
#include <SFML/System/Vector2.hpp>

class Snake; // forward declaration

enum class Cell { kEmpty, kSnake, kObstacle, kFruit };

std::ostream & operator<<(std::ostream & os, const Cell & cell);
std::istream & operator>>(std::istream & is, Cell & cell);


class Board
{
public:
    Board(size_t width = 10, size_t height = 10);
    ~Board() = default;

    inline Cell & at(size_t x, size_t y);
    inline Cell at(size_t x, size_t y) const;
    inline std::size_t width() const;
    inline std::size_t height() const;

    inline sf::Vector2<size_t> getFruitPos() const;


    /// @brief Informs Board, that the Fruit got eaten.
    void fruitEaten();
    
    /// A Snake object can subscribe to the subscriber list.
    void subscribe(Snake *subscriber);
    void unsubscribe(Snake *unsubscriber);

private:
    std::size_t _width;
    std::size_t _height;
    std::vector<Cell> _matrix;
    sf::Vector2<size_t> _fruit;

    std::vector<Snake*> _subscriberList;

    /// @brief Set a new fruit and inform all listeners.
    void spawnFruit();
    
    /// Informs each Snake which subscribed to the
    /// subscriber list.
    void inform() const;
};

// declared as inline
std::size_t Board::width() const { return _width; }
std::size_t Board::height() const { return _height; }
Cell & Board::at( size_t x, size_t y) { return _matrix[x+y*_width]; }
Cell Board::at(size_t x, size_t y) const { return _matrix[x+y*_width]; }
sf::Vector2<size_t> Board::getFruitPos() const { return _fruit; }


std::istream &operator>>(std::istream &is, Board &board);
std::ostream &operator<<(std::ostream &os, const Board &board);

#endif