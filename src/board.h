#pragma once


#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <unordered_map>

#include "side.h"
#include "pieces.h"


using namespace std;


class Board {
    private:
        const int width;
        const int height;

        std::vector<Piece*> piece_list;
        Side side_to_move;
        unordered_map<char, bool> castling;
        // Square en_passant;
    
    public:
        Board();
        Board(int, int);
        bool place_piece(char, int, int);
        std::string to_string();
        Piece* get(int, int);
        void set_side_to_move(Side);
        void set_castling(char, bool);
        void set_side_has_castled(Side);
};
