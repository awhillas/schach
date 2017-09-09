#pragma once

class Square;
class Piece;

#include <string>
#include <vector>

#include "side.h"

// Forward declarations
class Square;
class Board;


using namespace std;


class Piece
{    
    protected:
        enum Side   side;
        Square*     position;
    
    public:
        Piece(Side, int, int);
        ~Piece();

        Square*         getPosition();
        static Piece*   make_piece(char, Side, int, int);
        bool            isAt(int, int);
        bool            isAt(Square*);

        virtual string            to_string();
        virtual vector<Square*>   getMoves(Board);
};

class JumpingPiece : public Piece
{
protected:

    pair<int, int> move_deltas[];

public:

    vector<Square*> getMoves(Board) override;
};

//class SlidingPiece : public Piece
//{
//    vector<Square*> getMoves(Board) override;
//};

class King : public JumpingPiece
{
    public:
        King(Side, int, int);
        string to_string() override;
};

class Queen : public Piece
{
    public:
        Queen(Side, int, int);
        string to_string() override;
};

class Bishop : public Piece
{
    public:
        Bishop(Side, int, int);
        string to_string() override;
};

class Knight : public Piece
{
    public:
        Knight(Side, int, int);
        string to_string() override;
};

class Rook : public Piece
{
    public:
        Rook(Side, int, int);
        string to_string() override;
};

class Pawn : public Piece
{
    public:
        Pawn(Side, int, int);
        string          to_string() override;
        vector<Square*> getMoves(Board) override;
};
