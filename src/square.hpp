#pragma once

#include <string>
#include <memory>

class Piece;


class Square {
private:
    Piece *         occupier;

public:
    const int       col;
    const int       row;

                    Square(int, int);
    void            setOccupier(Piece *);
    Piece *         getOccupier();
    std::string     to_algebraic() const;
    std::string     to_string() const;
    bool            operator==(const Square&) const;
};
