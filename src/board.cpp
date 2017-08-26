#include "board.h"
#include <iostream>

using namespace std;


#define WIDTH 8
#define HEIGHT 8


Board::Board() : width(WIDTH), height(HEIGHT) {}; 

Board::Board(int w, int h) : width(w), height(h) {
    side_to_move = Side::WHITE;
    castling['K'] = false;
    castling['Q'] = false;
    castling['k'] = false;
    castling['q'] = false;
 };

bool Board::place_piece(char type, int file, int rank) {
    if (file < 0 || file >= width || rank < 0 || rank >= height)
        throw invalid_argument( string("Can not place a piece :(") ); // + std::to_string(y + 1) + ", " + ('a' + x) );
    
    Side side = isupper(type) ? Side::WHITE : Side::BLACK;

    Piece * NewPiece = Piece::make_piece(type, side, file, rank);

    piece_list.push_back(NewPiece);
    // cout << "piece_list: " << piece_list.size() << "\n";
    return true;
}

void Board::set_side_to_move(Side stm) {
    side_to_move = stm;
}

void Board::set_castling(char what, bool can_they) {
    castling[what] = can_they;
}

void Board::set_side_has_castled(Side side) {
    if (side == Side::WHITE) {
        castling['K'] = false;
        castling['Q'] = false;
    }
    else if (side == Side::BLACK) {
        castling['k'] = false;
        castling['q'] = false;
    }
    else {
        throw range_error("Unknown side as castled?");
    }
}

string Board::to_string() {
    stringstream out;
    for (int rank = height - 1; rank >= 0; rank--) {
        for(int file = 0; file < width; file++) {
            auto piece = get(file, rank);
            if (piece != nullptr) {
                out << piece->to_string();
            }
            else {
                out << ' ';
            }
        }
        out << endl;
    }
    // Side to move
    out << ((side_to_move == Side::WHITE) ? "White" : "Black") << " to move." << endl;
    // Who can castle
    out << "Castling: ";
    for( const auto& c : castling ) {
        if (c.second)
            switch (c.first) {
                case 'K': out << "White king-side; "; break;
                case 'Q': out << "White queen-side; "; break;
                case 'k': out << "Black king-side; "; break;
                case 'q': out << "Black queen-side; "; break;
            }
    }
    out << endl;
    return out.str();
}

Piece* Board::get(int file, int rank) {
    for (Piece* piece : piece_list) {
        // cout << (piece->isAt(file, rank) ? "T" : "F");
        if (piece->isAt(file, rank)) {
            return piece;
        }
    }
    return nullptr;
}
