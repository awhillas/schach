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

void Move::make() {
    piece->set(to);
}

void Move::unmake() {
    piece->set(from);
}
