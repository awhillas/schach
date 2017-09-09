#include "pieces.h"
#include "square.h"
#include "board.h"
#include "move.h"


Piece::Piece(Side colour, int file, int rank) : side(colour) {
    position = new Square(file, rank);
}

Piece::~Piece() {
    delete position;
}

Square* Piece::getPosition() {
    return position;
}

string Piece::to_string() {
    if (side == Side::WHITE)
        return "White";
    else
        return "Black";
}

bool Piece::isAt(int file, int rank) {
    // cout << "position: " << position->col << "," << position->row;
    return position->col == file && position->row == rank;
    // return position == new Square(file, rank);
}

bool Piece::isAt(Square* place) {
    return position == place;
}


Piece * Piece::make_piece(char type, Side side, int file, int rank) {
    // Piece factory
    switch(type) {
        case 'K':
        case 'k':
            return new King(side, file, rank);
        case 'Q':
        case 'q':
            return new Queen(side, file, rank);
        case 'B':
        case 'b':
            return new Bishop(side, file, rank);
        case 'N':
        case 'n':
            return new Knight(side, file, rank);
        case 'R':
        case 'r':
            return new Rook(side, file, rank);
        case 'P':
        case 'p':
            return new Pawn(side, file, rank);
        default:
            throw invalid_argument("Unknown piece type");
            return NULL;
    }    
}

//vector<Square *> Piece::getMoves(Board board) {
//    return vector<Square *>();
//}

JumpingPiece::JumpingPiece(pair<int, int> deltas[]) : move_deltas(deltas) {}

vector<Square *> JumpingPiece::getMoves(Board board) {
    vector<Square *> moves;
    for (auto delta : move_deltas) {

    }
    return moves;
}

//vector<Square *> SlidingPiece::getMoves(Board board) {
//    return;
//}



//
// King
//

King::King(Side s, int x, int y) : Piece(s, x, y), move_deltas{
        {-1,-1},{0,-1},{1,-1},
        {-1,0}, {0,0}, {1,0},
        {-1,1}, {0,1}, {1,1}
} {}

string King::to_string() {
    return (side == Side::BLACK) ? "k" : "K" ;
}

vector<Square *> King::getMoves(Board board) {
    return vector<Square *>();
}


//
// Queen
//

Queen::Queen(Side s, int a, int b) : Piece(s,a,b) {}

string Queen::to_string() {
    return (side == Side::BLACK) ? "q" : "Q" ;
}

vector<Square *> Queen::getMoves(Board board) {
    return vector<Square *>();
}


//
// Bishop
//

Bishop::Bishop(Side s, int a, int b) : Piece(s,a,b) {};

string Bishop::to_string() {
    return (side == Side::BLACK) ? "b" : "B" ;
}

vector<Square *> Bishop::getMoves(Board board) {
    return vector<Square *>();
}


//
// Knight
//

Knight::Knight(Side s, int a, int b) : Piece(s,a,b) {};

string Knight::to_string() {
    return (side == Side::BLACK) ? "n" : "N" ;
}

vector<Square *> Knight::getMoves(Board board) {
    return vector<Square *>();
}


//
// Rook
//

Rook::Rook(Side s, int a, int b) : Piece(s,a,b) {};

string Rook::to_string() {
    return (side == Side::BLACK) ? "r" : "R" ;
}

vector<Square *> Rook::getMoves(Board board) {
    return vector<Square *>();
}


//
// Pawn
//

Pawn::Pawn(Side s, int a, int b) : Piece(s,a,b) {};

string Pawn::to_string() {
    return (side == Side::BLACK) ? "p" : "P" ;
}

vector<Square *> Pawn::getMoves(Board board) {
    return vector<Square *>();
}
