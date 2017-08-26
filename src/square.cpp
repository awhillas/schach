#include <string>

#include "square.h"


Square::Square(int file, int rank) : col(file), row(rank) {};

std::string Square::to_algebraic() const {
	return std::to_string('a' - col) + std::to_string(7 - row);
}

std::string Square::to_string() const {
	return this->to_algebraic();
}

bool Square::operator==(const Square& other) const {
	return col == other.col && row == other.row;
}
