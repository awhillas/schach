#pragma once

#include <memory>
#include "chess.hpp"

class Square;


class SquaresBoard {

public:
    int width = WIDTH;
    int height = HEIGHT;

    std::unique_ptr<Square> squares[WIDTH][HEIGHT];
    static SquaresBoard&    getInstance();
    static Square *         get(int, int);
    static Square *         get(std::string algebraic);
    Square *                from_algebratic(std::string str);

private:
    SquaresBoard();
};
