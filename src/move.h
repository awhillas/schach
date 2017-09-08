#pragma once

#include <string>
#include <vector>

// Forward declarations.
class Square;
class Piece;

using namespace std;


class Move
{
    private:
        Piece*  piece;
        Square* to;
        bool    isCapture;

    public:
        Move(Piece*, Square*);
        string          to_string();
        bool            getIsCapture();
        vector<Move*>   getMoves();
};
