#pragma once

#include "chess.h"
#include "square.h"

using namespace std;


// TODO: return a pointer to the Square instead of the unique_ptr<Square>!

class SquaresBoard {

public:
    int width = WIDTH;
    int height = HEIGHT;
    unique_ptr<Square> squares[WIDTH][HEIGHT];
    static SquaresBoard& getInstance() {
        static SquaresBoard S;
        return S;
    }
    static Square * get(int x, int y) {
        return SquaresBoard::getInstance().squares[x][y].get();
    }

private:
    SquaresBoard() {
        for (int x = 0; x < width; ++x)
            for (int y = 0; y < height; ++y)
                squares[x][y] = unique_ptr<Square>(new Square(x, y));

    }

};
