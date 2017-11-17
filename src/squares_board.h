#pragma once

#include "chess.h"
#include "square.h"

using namespace std;


class SquaresBoard {

public:
    int width = WIDTH;
    int height = HEIGHT;
    unique_ptr<Square>      squares[WIDTH][HEIGHT];
    static SquaresBoard&    getInstance();
    static Square *         get(int, int);

private:
    SquaresBoard();
};
