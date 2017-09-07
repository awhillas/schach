#include "pieces.h"
#include "square.h"
#include "board.h"
#include "move.h"

using namespace std;


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

vector<Move *> Piece::getMoves(Board board) {
    return vector<Move *>();
}


King::King(Side s, int a, int b) : Piece(s,a,b) {}

string King::to_string() {
    return (side == Side::BLACK) ? "k" : "K" ;
}

vector<Move *> King::getMoves(Board board) {
    return vector<Move *>();
}




Queen::Queen(Side s, int a, int b) : Piece(s,a,b) {}

string Queen::to_string() {
    return (side == Side::BLACK) ? "q" : "Q" ;
}

vector<Move *> Queen::getMoves(Board board) {
    return vector<Move *>();
}



Bishop::Bishop(Side s, int a, int b) : Piece(s,a,b) {};

string Bishop::to_string() {
    return (side == Side::BLACK) ? "b" : "B" ;
}

vector<Move *> Bishop::getMoves(Board board) {
    return vector<Move *>();
}



Knight::Knight(Side s, int a, int b) : Piece(s,a,b) {};

string Knight::to_string() {
    return (side == Side::BLACK) ? "n" : "N" ;
}

vector<Move *> Knight::getMoves(Board board) {
    return vector<Move *>();
}



Rook::Rook(Side s, int a, int b) : Piece(s,a,b) {};

string Rook::to_string() {
    return (side == Side::BLACK) ? "r" : "R" ;
}

vector<Move *> Rook::getMoves(Board board) {
    return vector<Move *>();
}



Pawn::Pawn(Side s, int a, int b) : Piece(s,a,b) {};

string Pawn::to_string() {
    return (side == Side::BLACK) ? "p" : "P" ;
}

vector<Move *> Pawn::getMoves(Board board) {
    return vector<Move *>();
}

