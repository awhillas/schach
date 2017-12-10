#pragma once

#include <string>
#include <vector>
#include "side.hpp"


// Forward declarations
class Board;
class Square;
class SquaresBoard;


class Piece {
protected:
    Square *                        position;

public:
    const enum Side                 side;

                                    Piece(Side, int, int);
    virtual                         ~Piece();

    static Piece *                  make_piece(char, Side, int, int);
    void                            set(Square *);
    Square *                        getPosition();
    bool                            isAt(int, int) const;
    bool                            isAt(Square *) const;

    virtual std::string             to_string() const;
    virtual std::vector<Square *>   getSquares(Board) const;
};


class JumpingPiece : public Piece {
protected:
    std::vector<std::pair<int, int> > move_deltas;

public:
                            JumpingPiece(Side, int, int, std::vector<std::pair<int, int> >);
    std::vector<Square *>   getSquares(Board) const override;
};


class SlidingPiece : public Piece {
protected:
    std::vector<std::pair<int, int> > move_deltas;

public:
                            SlidingPiece(Side, int, int, std::vector<std::pair<int, int> >);
    std::vector<Square *>   getSquares(Board) const override;
};


class King : public JumpingPiece {
public:
                King(Side, int, int);
    std::string to_string() const override;
};


class Queen : public SlidingPiece {
public:
                Queen(Side, int, int);
    std::string to_string() const override;
};


class Bishop : public SlidingPiece {
public:
                Bishop(Side, int, int);
    std::string to_string() const override;
};


class Knight : public JumpingPiece {
public:
                Knight(Side, int, int);
    std::string to_string() const override;
};


class Rook : public SlidingPiece {
public:
                Rook(Side, int, int);
    std::string to_string() const override;
};


class Pawn : public Piece {
public:
                            Pawn(Side, int, int);
    std::string             to_string() const override;
    std::vector<Square *>   getSquares(Board) const override;
};
