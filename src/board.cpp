#include <vector>

#include "side.h"
#include "square.h"
#include "pieces.h"

using namespace std;


#define WIDTH 8
#define HEIGHT 8


class Board {

   public:
        Board()
        {
            width = WIDTH;
            height = HEIGHT;
        };
        Board(int w, int h, Square ep) : width(w), height(h), en_passant(ep) {};

        Side hasPiece();
};