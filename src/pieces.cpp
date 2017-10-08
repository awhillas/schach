#include "pieces.h"
#include "square.h"
#include "board.h"
#include "move.h"


Piece::Piece(Side colour, int file, int rank) : side(colour) {
    position = new Square(file, rank);
}

Piece::~Piece() {
    delete position;
}

string Piece::to_string() {
    if (side == Side::WHITE)
        return "White";
    else
        return "Black";
}

bool Piece::isAt(int file, int rank) {
    return position->col == file && position->row == rank;
}

bool Piece::isAt(Square* place) {
    return position == place;
}


Piece * Piece::make_piece(char type, Side side, int file, int rank) {
    // Piece factory
    switch(type) {
        case 'K':
        case 'k':
            return new King(side, file, rank);
        case 'Q':
        case 'q':
            return new Queen(side, file, rank);
        case 'B':
        case 'b':
            return new Bishop(side, file, rank);
        case 'N':
        case 'n':
            return new Knight(side, file, rank);
        case 'R':
        case 'r':
            return new Rook(side, file, rank);
        case 'P':
        case 'p':
            return new Pawn(side, file, rank);
        default:
            throw invalid_argument("Unknown piece type");
            return NULL;
    }
}

vector<Square*> Piece::getMoves(Board) { return vector<Square*>(); }  // TODO: isn't this redundant as its virtual???


//
// JumpingPiece
//

JumpingPiece::JumpingPiece(
        Side side,
        int file,
        int rank,
        vector<pair<int, int> > deltas
) : Piece::Piece(side, file, rank), move_deltas(deltas) {}

vector<Square*> JumpingPiece::getMoves(Board board) {
    vector<Square*> moves {};
    for (auto delta : move_deltas) {
        int x = position->col + delta.first;
        int y = position->row + delta.second;
        Piece* occupier = board.get(x, y);
        if (    x >= 0                              // square is within the board...
            and x < board.width
            and y >= 0
            and y < board.height
            and occupier and occupier->side != side  // ...and no occupied by a friendly
        ) {
            Square* sqr = new Square(x, y);
            moves.push_back(sqr);
        }
    }
    return moves;
}



//
// SlidingPiece
//


SlidingPiece::SlidingPiece(
        Side side,
        int file,
        int rank,
        vector<pair<int, int> > deltas
) : Piece::Piece(side, file, rank), move_deltas(deltas) {}

vector<Square*> SlidingPiece::getMoves(Board board) {
    vector<Square*> moves {};
    for (auto delta : move_deltas) {
        int x = position->col + delta.first;
        int y = position->row + delta.second;
        while(true) {
            if (x >= 0 and x < board.width and y >= 0 and y < board.height) {
                Piece* occupier = board.get(x, y);
                Square* sqr = new Square(x, y);
                if (occupier) {
                    if (occupier->side != side) // an attack!
                        moves.push_back(sqr);
                    break;
                }
                moves.push_back(sqr);  // empty square
                x = x + delta.first;
                y = y + delta.second;
            }
            else { // off-board
                break;
            }
        };
    }
    return moves;
}



//
// King
//

King::King(Side s, int x, int y) : JumpingPiece(s, x, y,
                                                {{-1,-1},{0,-1},{1,-1},
                                                 {-1,0}, {0,0}, {1,0},
                                                 {-1,1}, {0,1}, {1,1}
                                                }) {}

string King::to_string() {
    return (side == Side::BLACK) ? "k" : "K" ;
}


//
// Queen
//

Queen::Queen(Side s, int x, int y) : SlidingPiece(s, x, y,
                                                  {{-1,-1},{0,-1},{1,-1},
                                                   {-1,0}, {0,0}, {1,0},
                                                   {-1,1}, {0,1}, {1,1}
                                                  }) {}

string Queen::to_string() {
    return (side == Side::BLACK) ? "q" : "Q" ;
}


//
// Bishop
//

Bishop::Bishop(Side s, int x, int y) : SlidingPiece(s, x, y, {{-1,-1}, {1,-1}, {1, -1}, {1, 1}}) {}

string Bishop::to_string() {
    return (side == Side::BLACK) ? "b" : "B" ;
}


//
// Knight
//

Knight::Knight(Side s, int x, int y) : JumpingPiece(s, x, y, {}) {}

string Knight::to_string() {
    return (side == Side::BLACK) ? "n" : "N" ;
}


//
// Rook
//

Rook::Rook(Side s, int x, int y) : SlidingPiece(s, x, y, {{0,-1}, {0,1}, {-1,0}, {1,0}}) {}

string Rook::to_string() {
    return (side == Side::BLACK) ? "r" : "R" ;
}


//
// Pawn
//

Pawn::Pawn(Side s, int a, int b) : Piece(s,a,b) {}

string Pawn::to_string() {
    return (side == Side::BLACK) ? "p" : "P" ;
}

vector<Square*> Pawn::getMoves(Board board) {
    vector<Square*> moves {};

    // Forward depending on the side && noting occupying it

    int x = position->col;
    int y = (side == Side::WHITE) ? position->row + 1 : position->row - 1 ;
    if (y >= 0 and y < board.height) {
        if (not board.get(x, y))
            moves.push_back(new Square(x, y));

        // Attack left & right
        Piece* occupier = board.get(x - 1, y);
        if (occupier and occupier->side != side)
            moves.push_back(new Square(x - 1, y));

        occupier = board.get(x - 1, y);
        if (occupier and occupier->side != side)
            moves.push_back(new Square(x - 1, y));
    }
    return moves;
}
