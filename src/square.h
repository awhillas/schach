#pragma once

#include <string>

class Square {
    public:
        const int col;
        const int row;

        Square(int, int);
        std::string to_algebraic() const;
        std::string to_string() const;
        bool operator==(const Square&) const;
        static Square * from_algebratic(std::string);
};