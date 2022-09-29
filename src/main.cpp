

//#include <fstream>
#include <cstdlib>

#include <X11/Xlib.h>
#undef None
#include <iostream>

#include "Game.hpp"


int main()
{

    // necessary because multi-threading support of X11 lib
    if (!XInitThreads())
    {
        std::cerr << "No multi-threading support!\n";
        std::exit(EXIT_FAILURE);
    }

    Board board;
    Game(board).run();
}