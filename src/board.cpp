#include <vector>
#include <stdexcept>

#include "side.h"
#include "square.h"
#include "pieces.h"

using namespace std;


#define WIDTH 8
#define HEIGHT 8


class Board {
    int width;
    int height;

    public:
        Board()
        {
            width = WIDTH;
            height = HEIGHT;
        };
        Board(int w, int h) : width(w), height(h) {};
};

static char Board::iToFile(int i) {
    return 'a' + i;
}

bool Board::place_piece(char type, int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height)
        throw invalid_argument( "Can not place a piece at " + to_string(y + 1) + ", " + iToFile(x) );

    Piece NewPiece;
    
    switch(type) {
        case 'K':
            NewPiece = new King(Side::WHITE, x, y);
            break;
        case 'k':
            NewPiece = new King(Side::BLACK, x, y);
            break;
        case 'Q':
            NewPiece = new Queen(Side::WHITE, x, y);
            break;
        case 'q':
            NewPiece = new Queen(Side::BLACK, x, y);
            break;
        case 'B':
            NewPiece = new Bishop(Side::WHITE, x, y);
            break;        
        case 'b':
            NewPiece = new Bishop(Side::BLACK, x, y);
            break;        
        case 'N':
            NewPiece = new Knight(Side::WHITE, x, y);
            break;
        case 'n':
            NewPiece = new Knight(Side::BLACK, x, y);
            break;        
        case 'R':
            NewPiece = new Rook(Side::WHITE, x, y);
            break;
        case 'r':
            NewPiece = new Rook(Side::BLACK, x, y);
            break;
        case 'P':
            NewPiece = new Pawn(Side::WHITE, x, y);
            break;
        case 'p':
            NewPiece = new Pawn(Side::BLACK, x, y);
            break;
        default:
            // Error
    }
    piece_list.push(NewPiece);
}