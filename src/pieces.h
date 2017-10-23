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
    public:
        const Square*   position;
        const enum Side side;

        Piece(Side, int, int);
        ~Piece();

        static Piece*           make_piece(char, Side, int, int);
        bool                    isAt(int, int) const;
        bool                    isAt(Square*) const;

        virtual string          to_string() const;
        virtual vector<Square*> getMoves(Board) const;
};


class JumpingPiece : public Piece
{
    protected:
        vector<pair<int, int> > move_deltas;

    public:
                        JumpingPiece(Side, int, int, vector<pair<int, int> >);
        vector<Square*> getMoves(Board) const override;
};


class SlidingPiece : public Piece
{
    protected:
        vector<pair<int, int> > move_deltas;

    public:
                        SlidingPiece(Side, int, int, vector<pair<int, int> >);
        vector<Square*> getMoves(Board) const override;
};


class King : public JumpingPiece
{
    public:
                King(Side, int, int);
        string  to_string() const override;
};


class Queen : public SlidingPiece
{
    public:
                Queen(Side, int, int);
        string  to_string() const override;
};


class Bishop : public SlidingPiece
{
    public:
                Bishop(Side, int, int);
        string  to_string() const override;
};


class Knight : public JumpingPiece
{
    public:
                Knight(Side, int, int);
        string  to_string() const override;
};


class Rook : public SlidingPiece
{
    public:
                Rook(Side, int, int);
        string  to_string() const override;
};


class Pawn : public Piece
{
    public:
                        Pawn(Side, int, int);
        string          to_string() const override;
        vector<Square*> getMoves(Board) const override;
};
