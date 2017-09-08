#pragma once

class Square;
class Piece;

#include <string>
#include <vector>

#include "side.h"

// Forward declarations
class Square;
class Board;
class Move;

using namespace std;


class Piece
{    
    protected:
        enum Side side;
        Square* position;
    
    public:
        Piece(Side, int, int);
        ~Piece();

        Square*         getPosition();
        static Piece*   make_piece(char, Side, int, int);
        bool            isAt(int, int);
        bool            isAt(Square*);

        virtual string          to_string();
        virtual vector<Move*>   getMoves(Board);
};

class King : public Piece
{
    public:
        King(Side, int, int);
        string                  to_string();
        virtual vector<Move*>   getMoves(Board);
};

class Queen : public Piece
{
    public:
        Queen(Side, int, int);
        string                  to_string();
        virtual vector<Move*>   getMoves(Board);
};

class Bishop : public Piece
{
    public:
        Bishop(Side, int, int);
        string                  to_string();
        virtual vector<Move*>   getMoves(Board);
};

class Knight : public Piece
{
    public:
        Knight(Side, int, int);
        string                  to_string();
        virtual vector<Move*>   getMoves(Board);
};

class Rook : public Piece
{
    public:
        Rook(Side, int, int);
        string                  to_string();
        virtual vector<Move*>   getMoves(Board);
};

class Pawn : public Piece
{
    public:
        Pawn(Side, int, int);
        string                  to_string();
        virtual vector<Move*>   getMoves(Board);
};
