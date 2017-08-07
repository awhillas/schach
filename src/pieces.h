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
    // Had to change this to protected so that child classes can access side and position.
    protected:
        enum Side side;
        Square* position;
    
    public:
        Piece(Side, int, int);
        ~Piece();
        static Piece * make_piece(char, Side, int, int);
        string to_string();
};

// TODO(bedser>awhillas): I had to add the explicit constructors here and have them call the parent class
// constructor. Also, I had to remove the class declarations from the pieces.cpp file since I was getting a
// 'redefined' error on them. Best bet would be to declare the functions here and then implement them in the
// cpp file, but this can wait.
class King : public Piece
{
public:
    King(Side s, int a, int b) : Piece(s,a,b) {}
    // Commenting out for now so that I don't ahve to get move.cpp compiling.
    //Move *getMoves(Board *board) {};

    string to_string() {
        return (side == Side::WHITE) ? "k" : "K" ;
    }
};

class Queen : public Piece
{
public:
    Queen(Side s, int a, int b) : Piece(s,a,b) {}
    string to_string() {
        return (side == Side::WHITE) ? "q" : "Q" ;
    }
};

class Bishop : public Piece
{
public:
    Bishop(Side s, int a, int b) : Piece(s,a,b) {}
    string to_string() {
        (side == Side::WHITE) ? "b" : "B" ;
    }
};

class Knight : public Piece
{
public:
    Knight(Side s, int a, int b) : Piece(s,a,b) {}
    string to_string() {
        return (side == Side::WHITE) ? "n" : "N" ;
    }
};

class Rook : public Piece
{
public:
    Rook(Side s, int a, int b) : Piece(s,a,b) {}
    string to_string() {
        return (side == Side::WHITE) ? "r" : "R" ;
    }
};

class Pawn : public Piece
{
public:
    Pawn(Side s, int a, int b) : Piece(s,a,b) {}
    string to_string() {
        return (side == Side::WHITE) ? "p" : "P" ;
    }
};
