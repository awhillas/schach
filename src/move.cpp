#include <string>

#include "move.hpp"
#include "pieces.hpp"
#include "square.hpp"
#include "board.hpp"

using namespace std;


Move::Move(Board * b, Piece * p, Square * s)
    : board(b), piece(p), from(p->getPosition()), to(s) {};

Move::Move(Board * b, Square * from, Square * to)
    : board(b), piece(from->getOccupier()), from(from), to(to) {};

Move::~Move() {};

Piece * Move::getPiece() { return piece; };

Square * Move::getFrom() { return from; };

Square * Move::getTo() { return to; };


string Move::to_string() {
    return piece->to_string() + piece->getPosition()->to_string() + "-" + to->to_string();
}

/*
    A Move move is for moving a piece to an empty square.
    The square is checked to be empty before the move to ensure it is not a Capture
*/
bool Move::make() {
    if (to->getOccupier()) {
        throw runtime_error("Standard Move should be to an empty square. Use Capture move instead. "  + to_string());
        return false;
    }
    else {
        piece->set(to);
        from->setOccupier(nullptr);
        to->setOccupier(piece);
    }
    return true;
}

bool Move::unmake() {
    if (from->getOccupier()) {
        throw runtime_error("Piece missing to unmove?"  + to_string());
        return false;
    }
    else {
        piece->set(from);
        from->setOccupier(piece);
        to->setOccupier(nullptr);
    }
    return true;
}


// // // // // // // // // // // // // // // // // // // // // // // // // // //
// Capture
// // // // // // // // // // // // // // // // // // // // // // // // // // //

bool Capture::make() {
    captured = to->getOccupier();
    if(captured) {
        to->setOccupier(nullptr);
        return Move::make();
    }
    else
        throw runtime_error("No Piece to capture? " + to_string());
    return false;
}

bool Capture::unmake() {
    if(captured) {
        to->setOccupier(captured);
        captured = nullptr;
        return Move::unmake();
    }
    else
        throw runtime_error("No piece was captured? " + to_string());
    return false;
}


// // // // // // // // // // // // // // // // // // // // // // // // // // //
// En passant
// // // // // // // // // // // // // // // // // // // // // // // // // // //

bool EnPassant::make() {
    int delta = (piece->side == Side::WHITE) ? 1 : -1;
    capture_square = board->getSquare(to->col, to->row  + delta);
    captured = capture_square->getOccupier();
    if (captured and capture_square) {
        board->set_en_passant_target_square(nullptr);
        capture_square->setOccupier(nullptr);
        return Move::make();
    }
    else
        throw runtime_error("No piece capturedv via en passant? " + to_string());
    return false;
}

bool EnPassant::unmake() {
    if(captured and capture_square) {
        board->set_en_passant_target_square(capture_square);
        capture_square->setOccupier(captured);
        captured = nullptr;
        return Move::unmake();
    }
    else
        throw runtime_error("No piece captured via en passant? " + to_string());
    return false;
}
