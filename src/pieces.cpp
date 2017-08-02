#include "side.h"
#include "square.h"
#include "board.h"
#include "move.h"


class Piece
{
    public:
        Piece(Side colour, int file, int rank) : side(colour) {
            position = new Square(x, y);
        }

        ~Piece() {
            delete position;
        }
        // Piece(Side colour, Square *square) : side(colour), position(square){};
        // Move *getMoves(Board *board);
        
        string to_string() {
            if (side == Side::WHITE)
                return "White";
            else
                return "Black";
        }
};

class King : public Piece
{
    public:
        Move *getMoves(Board *board) {};

        string to_string() {
            return Piece::to_string() + "King!";
        }
};

class Queen : public Piece
{
    public:
        string to_string() {
            return Piece::to_string() + "Queen!";
        }
};

class Bishop : public Piece
{
    public:
        string to_string() {
            return Piece::to_string() + "Bishop!";
        }
};

class Knight : public Piece
{
    public:
        string to_string() {
            return Piece::to_string() + "Knight!";
        }
};

class Rook : public Piece
{
    public:
        string to_string() {
            return Piece::to_string() + "Rook!";
        }
};

class Pawn : public Piece
{
    public:
        string to_string() {
            return Piece::to_string() + "Pawn!";
        }
};