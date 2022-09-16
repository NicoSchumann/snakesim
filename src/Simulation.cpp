#include "Simulation.hpp"
#include <chrono>
#include <thread>
#include <future>

Simulation::Simulation( Board & board)
: _board{board}
{
    _snakeDisplay = std::make_shared<Display>(board);
    _GUIDisplay = std::make_shared<Display>(board);
}


void Simulation::run()
{
    std::future<void> ftr = std::async( &Display::draw, _snakeDisplay);
    std::future<void> ftr2 = std::async( &Display::draw, _GUIDisplay);
    ftr.wait();
    ftr2.wait();
}
