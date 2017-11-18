#include "squares_board.hpp"
#include "square.hpp"

SquaresBoard::SquaresBoard() {
    for (int x = 0; x < width; ++x)
        for (int y = 0; y < height; ++y)
            squares[x][y] = std::unique_ptr<Square>(new Square(x, y));
}

SquaresBoard& SquaresBoard::getInstance() {
    static SquaresBoard S;
    return S;
}

Square * SquaresBoard::get(int x, int y) {
    return SquaresBoard::getInstance().squares[x][y].get();
}
