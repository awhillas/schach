#pragma once

#include <vector>
#include <stdexcept>
#include <string>
#include <sstream>
#include <map>

#include "chess.h"
#include "side.h"


// Forward declerations
class Piece;
class Move;
class Square;
class SquaresBoard;


class Board {
    private:
        std::vector<Piece *>    piece_list;
        Side                    side_to_move;
        std::map<char, bool>    castling;
        /**
         * The en passant target square is specified after a double push of a
         * pawn, no matter whether an en passant capture is really possible or
         * not.
         */
        Square *        en_passant_sqr;
        /**
         * The halfmove clock specifies a decimal number of half moves with
         * respect to the 50 move draw rule. It is reset to zero after a
         * capture or a pawn move and incremented otherwise.
         */
        int             half_move_counter;
        /**
         * The number of the full moves in a game. It starts at 1, and is
         * incremented after each Black's move.
         */
        int             full_move_counter;

    public:
        const int           width;
        const int           height;

                            Board();
                            Board(int, int);
        bool                place_piece(char, int, int);
        bool                place_piece(Piece &);
        std::string         to_string() const;
        Piece *             get(int, int) const;
        Square *            getSquare(int, int) const;
        std::string         to_fen() const;

        // Move generation

        std::vector<Move*>  getMoves();

        // Setters

        void set_side_to_move(Side);
        void set_castling(char, bool);
        void set_side_has_castled(Side);
        void set_en_passant_target_square(std::string);
        void set_half_move_counter(int);
        void set_full_move_counter(int);
};
