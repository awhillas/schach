#include <iostream>
#include <string>
#include <vector>

#include "fen.cpp"

using namespace std;


int main(int argc, char const *argv[])
{
    string start_position_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    FEN * fen = new FEN(start_position_fen);
    fen->getBoard();
}
