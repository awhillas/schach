#pragma once

#include "side.h"
#include "square.h"
#include "board.h"
//#include "move.h"


class Piece
{
    enum Side side;
    Square* position;
    
    public:
        Piece(Side colour, int file, int rank) : side(colour) {};
        ~Piece() {};
        // Piece(Side colour, Square *square) : side(colour), position(square){};
        //Move *getMoves(Board *board);
};

class King : public Piece {};

class Queen : public Piece {};

class Bishop : public Piece {};

class Knight : public Piece {};

class Rook : public Piece {};

class Pawn : public Piece {};
