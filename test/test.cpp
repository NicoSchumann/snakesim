#include "Board.hpp"
#include <iostream>
#include <fstream>


void sol(bool ok = false) { std::cout << (ok?"Ok\n":"Failure!\n"); }


void test_Board()
{
    std::cout << "run test_Board()..." << std::endl;
    Board board(3, 5);

    std::ofstream ofs("board.save");
    if(!(ofs << board)) sol();
    ofs.close();


    std::ifstream 
    ifs("board.save");
    if(!(ifs >> board)) sol();
    ifs.close();
    std::cout << board;

    sol(true);
}

int main()
{
    test_Board();
}