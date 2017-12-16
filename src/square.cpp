#include <string>

#include "square.hpp"


Square::Square(int file, int rank) : col(file), row(rank) {
    occupier = nullptr;
};

void Square::setOccupier(Piece * piece) {
    occupier = piece;
}

Piece * Square::getOccupier() {
    return occupier;
}

std::string Square::to_algebraic() const {
	return std::string(1, 'a' + col) + std::to_string(1 + row);
}

std::string Square::to_string() const {
	return this->to_algebraic();
}

bool Square::operator==(const Square& other) const {
	return col == other.col && row == other.row;
}
