#pragma once

#include <vector>

#include "side.h"
#include "square.h"
#include "pieces.h"


class Board {
    Board();
    Board(int w, int h){};
    Side hasPiece();
};