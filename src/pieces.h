#pragma once

#include "side.h"
#include "square.h"
#include "board.h"
#include "move.h"


class Piece
{
    public:
        Piece(Side colour, Square *square) : side(colour), position(square){};
        Move *getMoves(Board *board);
};
