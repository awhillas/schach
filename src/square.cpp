#include <string>

#include "square.h"


Square::Square(int file, int rank) : col(file), row(rank) {};

std::string Square::to_algebraic() const {
	return std::to_string('a' + col) + std::to_string(7 - row);
}

std::string Square::to_string() const {
	return this->to_algebraic();
}

Square * Square::from_algebratic(std::string str) {
	if (str.length() != 2) {
		throw std::range_error(std::string("Wrong number of characters for a algebraic square location: ") + str);
		return NULL;
	}
	if (str[0] >= 'a' && str[0] <= 'h') {
		int col = str[0] - 'a';
		if (str[1] >= '1' && str[1] <= '8') {
			int row = '1' - str[1];
			return new Square(col, row);
		}
		else {
			throw std::range_error(std::string("Bad rank in algebraic notation: ") + str[1]);	
			return NULL;	
		}
	}
	else {
		throw std::range_error(std::string("Bad file in algebraic notation: ") + str[0]);
		return NULL;
	}
}

bool Square::operator==(const Square& other) const {
	return col == other.col && row == other.row;
}
