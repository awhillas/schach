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

Square * SquaresBoard::get(std::string algebraic) {
    return SquaresBoard::getInstance().from_algebratic(algebraic);
}

Square * Square::from_algebratic(std::string str) {
	if (str.length() != 2) {
		throw std::range_error(std::string("Wrong number of characters for a algebraic square location: ") + str);
		return nullptr;
	}
	if (str[0] >= 'a' && str[0] <= 'h') {
		int col = str[0] - 'a';
		if (str[1] >= '1' && str[1] <= '8') {
			int row = str[1] - '1';
			return SquaresBoard::get(col, row);
		}
		else {
			throw std::range_error(std::string("Bad rank in algebraic notation: ") + str[1]);
			return nullptr;
		}
	}
	else {
		throw std::range_error(std::string("Bad file in algebraic notation: ") + str[0]);
		return nullptr;
	}
}
