#include <iostream>
#include <vector>

#include "fen.h"
#include "move.h"

// uncomment to disable assert()
// #define NDEBUG
#include <cassert>

using namespace std;

/**
    TODO List
    - Only get moves for the side that can move.
    - Knight moves
    - Pawn inital double moves.
*/

int main(int argc, char const *argv[])
{
    string start_position_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    FENParser* fen = new FENParser(start_position_fen);
    Board* b = fen->parse();
    string fen_out = b->to_fen();
    cout << "Position: " << fen_out << endl;

    auto move_list = b->getMoves();
    cout << "All moves: " << endl;
    for (auto& move : move_list) {
        cout << move->to_string() << ", ";
    };
    cout << endl << "Total: " << move_list.size() << endl;

    // Test FEN parsing

//    cout << start_position_fen << endl << fen_out << endl;
    assert(start_position_fen == fen_out);
}
