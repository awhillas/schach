#include <iostream>

#include "square.hpp"
#include "pieces.hpp"
#include "board.hpp"
#include "squares_board.hpp"


using namespace std;


Piece::~Piece() {}

Piece::Piece(Side colour, int file, int rank) : side(colour) {
    position = SquaresBoard::get(file, rank);
};

string Piece::to_string() const {
    if (side == Side::WHITE)
        return "White";
    else
        return "Black";
}

bool Piece::isAt(int file, int rank) const {
    return position->col == file && position->row == rank;
}

bool Piece::isAt(Square * place) const {
    return *position == *place;
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
    }
    return nullptr;
}

vector<Square *> Piece::getSquares(Board b) const { return vector<Square *>(); }




//
// JumpingPiece
//

JumpingPiece::JumpingPiece(
        Side side,
        int file,
        int rank,
        vector<pair<int, int> > deltas
) : Piece::Piece(side, file, rank), move_deltas(deltas) {}

vector<Square*> JumpingPiece::getSquares(Board board) const {
    vector<Square *> moves {};
    for (auto delta : move_deltas) {
        int x = position->col + delta.first;
        int y = position->row + delta.second;
        Piece * occupier = board.get(x, y);
        if (    x >= 0                              // square is within the board...
            and x < board.width
            and y >= 0
            and y < board.height
            and (occupier == nullptr or occupier->side != side)  // ...and not occupied by a friendly
        ) {
            Square * sqr = SquaresBoard::get(x, y);
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

vector<Square *> SlidingPiece::getSquares(Board board) const {
    vector<Square *> moves {};
    for (auto delta : move_deltas) {
        int x = position->col + delta.first;
        int y = position->row + delta.second;
        while(true) {
            if (x >= 0 and x < board.width and y >= 0 and y < board.height) {
                Piece * occupier = board.get(x, y);
                Square * sqr = SquaresBoard::get(x, y);
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

King::King(Side s, int x, int y) : JumpingPiece(s, x, y, {
    {-1,-1}, {0,-1}, {1,-1},
    {-1,0},          {1,0},
    {-1,1},  {0,1},  {1,1}
}) {}

string King::to_string() const {
    return (side == Side::BLACK) ? "k" : "K" ;
}



//
// Queen
//

Queen::Queen(Side s, int x, int y) : SlidingPiece(s, x, y,{
    {-1,-1}, {0,-1}, {1,-1},
    {-1,0},          {1,0},
    {-1,1},  {0,1},  {1,1}
}) {}

string Queen::to_string() const {
    return (side == Side::BLACK) ? "q" : "Q" ;
}



//
// Bishop
//

Bishop::Bishop(Side s, int x, int y) : SlidingPiece(s, x, y, {{-1,-1}, {1,-1}, {1, -1}, {1, 1}}) {}

string Bishop::to_string() const {
    return (side == Side::BLACK) ? "b" : "B" ;
}



//
// Knight
//

Knight::Knight(Side s, int x, int y) : JumpingPiece(s, x, y, {
    {-1, 2}, {1, 2},
    {-2, 1}, {2, 1},
    {-2,-1}, {2,-1},
    {-1,-2}, {1,-2},
}) {}

string Knight::to_string() const {
    return (side == Side::BLACK) ? "n" : "N" ;
}



//
// Rook
//

Rook::Rook(Side s, int x, int y) : SlidingPiece(s, x, y, {{0,-1}, {0,1}, {-1,0}, {1,0}}) {}

string Rook::to_string() const {
    return (side == Side::BLACK) ? "r" : "R" ;
}



//
// Pawn
//

Pawn::Pawn(Side s, int a, int b) : Piece(s, a, b) {}

string Pawn::to_string() const {
    return (side == Side::BLACK) ? "p" : "P" ;
}

vector<Square *> Pawn::getSquares(Board board) const {
    vector<Square *> moves {};

    // Forward depending on the side && nothing occupying it

    const int y_delta = (side == Side::WHITE) ? 1 : -1;  // dir. we're movings
    const int y = position->row + y_delta;
    const int x = position->col;

    if (y >= 0 and y < board.height) {
        if (not board.get(x, y))
            moves.push_back(board.getSquare(x, y));

        // Double moves from inital position

        if ((side == Side::WHITE and position->row == 1) or (side == Side::BLACK and position->row == 6))
            if(not board.get(x, y + y_delta))
                moves.push_back(board.getSquare(x, y + y_delta));

        // Attack left & right

        auto occupier = board.get(x - 1, y);  // left
        if (occupier and occupier->side != side)
            moves.push_back(board.getSquare(x - 1, y));

        occupier = board.get(x + 1, y);  // right
        if (occupier and occupier->side != side)
            moves.push_back(board.getSquare(x + 1, y));

    }
    return moves;
}
