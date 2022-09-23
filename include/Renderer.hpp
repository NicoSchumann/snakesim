#ifndef RENDERER_HPP
#define RENDERER_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include "Snake.hpp"
#include "Board.hpp"
#include <memory>

class Renderer
{
public:
    Renderer( const Board & board, size_t width = 800, size_t height = 600, size_t frameRate = 20);

    void draw();
    sf::Window & getWindow();


private:
    const Board & _board;
    size_t _width;
    size_t _height;
    size_t _frameRate;

    std::unique_ptr<sf::RenderWindow> _window;
    sf::RectangleShape _tileEmpty;
    sf::RectangleShape _tileObstacle;
    sf::RectangleShape _tileSnake;
    sf::RectangleShape _tileFruit;
};


#endif
