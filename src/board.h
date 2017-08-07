#pragma once


#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>

#include "side.h"
#include "pieces.h"


using namespace std;


class Board {
    private:
        const int width;
        const int height;

        std::vector<Piece> piece_list;
        Side side_to_move;
        // castling;
        // Square en_passant;
    
    public:
        Board();
        Board(int, int);
        bool place_piece(char, int, int);
        std::string to_string();
        Piece* get(int, int);
};
