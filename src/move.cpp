#include <string>

#include "move.hpp"
#include "pieces.hpp"
#include "square.hpp"


Move::Move(Piece *p, Square *s) : piece(p), to(s){};

string Move::to_string() {
    return piece->to_string() + piece->position->to_string() + "-" + to->to_string();
}

bool Move::getIsCapture() {
    return isCapture;
}
