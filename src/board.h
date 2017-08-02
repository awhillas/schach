#pragma once

#include <vector>

#include "side.h"
#include "square.h"
#include "pieces.h"


class Board {
    vector<Piece> piece_list;
    Side side_to_move;
    // castling;
    // Square en_passant;

    int width;
    int height;
    // Piece pieces_list[WIDTH * 4];
    

    public:
        Board();
        Board(int w, int h);
        bool place_piece(char type, int x, int y);
};