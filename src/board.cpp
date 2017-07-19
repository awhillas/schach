#include <vector>

#include "side.h"
#include "square.h"
#include "pieces.h"

using namespace std;


#define WIDTH 8
#define HEIGHT 8


class Board {

    private:
        vector<Piece> piece;
        Side side_to_move;
        // castling;
        Square en_passant;

        int width;
        int height;
        // Piece pieces_list[WIDTH * 4];

    public:
        Board()
        {
            width = WIDTH;
            height = HEIGHT;
        };
        Board(int w, int h) : width(w), height(h){};

        Side hasPiece();
};