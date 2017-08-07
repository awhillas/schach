#include "pieces.h"

#include <stdexcept>

using namespace std;


Piece::Piece(Side colour, int file, int rank) : side(colour) {
    position = new Square(file, rank);
}

Piece::~Piece() {
    delete position;
}

string Piece::to_string() {
    if (side == Side::WHITE)
        return "White";
    else
        return "Black";
}

Piece * Piece::make_piece(char type, Side side, int x, int y) {
    // Piece factory
    switch(type) {
        case 'K':
        case 'k':
            return new King(side, x, y);
        case 'Q':
        case 'q':
            return new Queen(side, x, y);
        case 'B':
        case 'b':
            return new Bishop(side, x, y);
        case 'N':
        case 'n':
            return new Knight(side, x, y);
        case 'R':
        case 'r':
            return new Rook(side, x, y);
        case 'P':
        case 'p':
            return new Pawn(side, x, y);
        default:
            throw invalid_argument("Unknown piece type");
            return NULL;
    }    
}
