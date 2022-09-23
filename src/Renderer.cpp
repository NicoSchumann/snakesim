#include "Renderer.hpp"
#include <thread>
#include <chrono>

Renderer::Renderer(const Board & board, size_t width, size_t height, size_t frameRate)
: _board{board}, _width(width), _height(height), _frameRate(frameRate)
{
    _window = std::make_unique<sf::RenderWindow>(sf::VideoMode(_width, _height), "snakesim");

    float tileWidth = float(_width) / _board.width();
    float tileHeight = float(_height) / _board.height();
    sf::Vector2f tileSize(tileWidth,tileHeight);

    _tileEmpty.setSize(tileSize);
    _tileSnake.setSize(tileSize);
    _tileFruit.setSize(tileSize);
    _tileObstacle.setSize(tileSize);

    _tileEmpty.setFillColor(sf::Color::Black);
    _tileEmpty.setOutlineColor(sf::Color::Black);

    _tileSnake.setFillColor(sf::Color::Yellow);
    _tileSnake.setOutlineColor(sf::Color::Yellow);

    _tileFruit.setFillColor(sf::Color::Green);
    _tileFruit.setOutlineColor(sf::Color::Green);

    _tileObstacle.setFillColor(sf::Color::Red);
    _tileObstacle.setOutlineColor(sf::Color::Red);
}

void Renderer::draw()
{
    while(true) {
    // clears the buffer
    _window->clear();

    static sf::Vector2f tilePos;
    for( size_t y = 0; y < _board.height(); ++y)
    {
        tilePos.y = _tileEmpty.getSize().y * y;

        for( size_t x = 0; x < _board.width(); ++x)
        {
            tilePos.y = _tileEmpty.getSize().x * x;
            Cell cell = _board.at(x,y);

            // draws the Board
            switch(cell) {
                case Cell::kEmpty:
                    _tileEmpty.setPosition(tilePos);
                    _window->draw(_tileEmpty);
                    break;
                case Cell::kSnake:
                    _tileSnake.setPosition(tilePos);
                    _window->draw(_tileSnake);
                    break;
                case Cell::kFruit:
                    _tileFruit.setPosition(tilePos);
                    _window->draw(_tileFruit);
                    break;
                case Cell::kObstacle:
                    _tileObstacle.setPosition(tilePos);
                    _window->draw(_tileObstacle);
                    break;
            }
            
        } // end for_all x
    }  // end for_all y

    // brings the buffer to foreground
    _window->display();
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000/_frameRate));
 }

sf::Window & Renderer::getWindow() { return *_window; }
