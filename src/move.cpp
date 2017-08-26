#include <string>

#include "move.h"
// #include "square.h"
// #include "pieces.h"


Move::Move(Piece *p, Square *s) : piece(p), to(s){};

string Move::to_string() {
    return piece->getPosition()->to_string() + "-" + to->to_string();
}

bool Move::getIsCapture() {
    return isCapture;
}