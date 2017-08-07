#include "board.h"


using namespace std;


#define WIDTH 8
#define HEIGHT 8


Board::Board() : width(WIDTH), height(HEIGHT) {}; 

Board::Board(int w, int h) : width(w), height(h) {};

bool Board::place_piece(char type, int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height)
        throw invalid_argument( string("Can not place a piece :(") ); // + std::to_string(y + 1) + ", " + ('a' + x) );
    
    Side side = isupper(type) ? Side::WHITE : Side::BLACK;

    Piece * NewPiece = Piece::make_piece(type, side, x, y);

    piece_list.push_back(*NewPiece);
    return true;
}

string Board::to_string() {
    stringstream out;
    for (int h = height; h > 0; h--) {
        for(int w = 0; w < width; w++) {
            auto square = this->get(w, h);
            if (square != nullptr) {
                out << square->to_string();
            }
            else {
                out << ' ';
            }
        }
        out << endl;
    }
    return out.str();
}

Piece* Board::get(int file, int rank) {
    // for (Piece piece : piece_list) {
    //     if (piece->isAt(file, rank)) {
    //         return piece;
    //     }
    // }
    return nullptr;
}
