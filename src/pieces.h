#pragma once

class Square;

#include "side.h"
#include "square.h"
// #include "board.h"
//#include "move.h"
#include <string>
using namespace std;


class Piece
{    
    protected:
        enum Side side;
        Square* position;
    
    public:
        Piece(Side, int, int);
        ~Piece();
        Square* getPosition();
        static Piece * make_piece(char, Side, int, int);
        virtual string to_string();
        bool isAt(int, int);
        bool isAt(Square*);
};

class King : public Piece
{
    public:
        King(Side, int, int);
        string to_string();
};

class Queen : public Piece
{
    public:
        Queen(Side, int, int);
        string to_string();
};

class Bishop : public Piece
{
    public:
        Bishop(Side, int, int);
        string to_string();
};

class Knight : public Piece
{
    public:
        Knight(Side, int, int);
        string to_string();
};

class Rook : public Piece
{
    public:
        Rook(Side, int, int);
        string to_string();
};

class Pawn : public Piece
{
    public:
        Pawn(Side, int, int);
        string to_string();
};
