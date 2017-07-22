#include <iostream>
#include <string>
#include <vector>

#include "fen.cpp"
#include "board.h"

using namespace std;


int main(int argc, char const *argv[])
{
    string start_position_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    FENParser * fen = new FENParser(start_position_fen);
    // Board b = fen->getBoard();
}
