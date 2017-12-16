#pragma once

#include <string>
#include <vector>

// Forward declarations.
class Square;
class Piece;
class Board;

/*
    Move interface. Also a simple move of a piece from one empty square to another.
    Follows the _Command Design Pattern_ to allow different kinds of Moves and
    allows 'undo' so Board does not need to be cloned to search the move tree.

    - A Move needs to be displayed independantly of the Board and Piece state so
      the from and to Squares are recorded as well as the Piece moved.
    - The Board passed is assumed to be
*/
class Move
{
    protected:
        Board *     board;
        Piece *     piece;
        Square *    from;
        Square *    to;

    public:
                                Move(Board *, Piece *, Square *);
                                Move(Board *, Square *, Square *);
        virtual                 ~Move();
        virtual std::string     to_string();
        virtual bool            make();   // Command execute
        virtual bool            unmake(); // Command undo
        Piece *                 getPiece();
        Square *                getFrom();
        Square *                getTo();
};


class Capture : public Move
{
    protected:
        Piece * captured;

    public:
        bool make() override;
        bool unmake() override;
};


class EnPassant : public Capture
{
    private:
        Square * capture_square;

    public:
        bool make() override;
        bool unmake() override;
};
