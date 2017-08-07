#pragma once

class Square;

#include "side.h"
#include "square.h"
// #include "board.h"
//#include "move.h"


class Piece
{    
    private:
        enum Side side;
        Square* position;
    
    public:
        Piece(Side, int, int);
        ~Piece() {};
        static Piece * make_piece(char, Side, int, int);
};

class King : public Piece {};

class Queen : public Piece {};

class Bishop : public Piece {};

class Knight : public Piece {};

class Rook : public Piece {};

class Pawn : public Piece {};
