#pragma once

#include <string>
#include "pieces.h"

// Forward declerations.
class Square;


using namespace std;


class Move
{
    private:
        Piece* piece;
        Square* to;
        bool isCapture;

    public:
        Move(Piece *, Square *);
        string to_string();
        bool getIsCapture();
};