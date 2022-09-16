#ifndef SIMULATION_HPP
#define SIMULATION_HPP

#include "Display.hpp"
#include "Board.hpp"

class Simulation
{
public:
    Simulation( Board & board);
    void run();

private:
    Board & _board;
    std::shared_ptr<Display> _snakeDisplay;
    std::shared_ptr<Display> _GUIDisplay;

};


#endif