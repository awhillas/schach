#include "board.hpp"
#include "pieces.hpp"
#include "move.hpp"
#include "square.hpp"
#include "squares_board.hpp"


using namespace std;


Board::Board() : width(WIDTH), height(HEIGHT) {};

Board::Board(int w, int h) : width(w), height(h) {
    side_to_move = Side::WHITE;
    castling['K'] = false;
    castling['Q'] = false;
    castling['k'] = false;
    castling['q'] = false;
    en_passant_sqr = nullptr;
    half_move_counter = 0;
    full_move_counter = 0;
 };

Piece * Board::place_piece(char type, int file, int rank) {
    Side side = isupper(type) ? Side::WHITE : Side::BLACK;
    Piece * NewPiece = Piece::make_piece(type, side, file, rank);
    if(this->place_piece(*NewPiece)) {
        return NewPiece;
    } else {
        return nullptr;
    }
}

bool Board::place_piece(Piece & piece) {
    auto position = piece.getPosition();
    if (position->col < 0
        || position->col >= width
        || position->row < 0
        || position->row >= height
    )
        throw invalid_argument( string("Can not place a piece :(") );

    // TODO: Check that the square is not occupided... need to make sqaure aware of piece.
    // Square sqr = SquaresBoard::get(sqr->col, sqr->row);

    piece_list.push_back(&piece);  // thus piece can't be const :-/
    return true;
}

void Board::set_side_to_move(Side stm) {
    side_to_move = stm;
}

void Board::set_castling(char what, bool can_they) {
    castling[what] = can_they;
}

void Board::set_side_has_castled(Side side) {
    if (side == Side::WHITE) {
        castling['K'] = false;
        castling['Q'] = false;
    }
    else if (side == Side::BLACK) {
        castling['k'] = false;
        castling['q'] = false;
    }
    else {
        throw range_error("Unknown side when setting 'has castled'?");
    }
}

void Board::set_en_passant_target_square(string ep_square) {
    en_passant_sqr = Square::from_algebratic(ep_square);
}

void Board::set_en_passant_target_square(Square * sqr) {
    en_passant_sqr = sqr;
}

void Board::set_half_move_counter(int count) {
    half_move_counter = count;
}

void Board::set_full_move_counter(int count) {
    full_move_counter = count;
}

string Board::to_string() const {
    // Graphical representation of the board
    stringstream out;
    for (int rank = height - 1; rank >= 0; rank--) {
        for(int file = 0; file < width; file++) {
            auto piece = get(file, rank);
            if (piece != nullptr) {
                out << piece->to_string();
            }
            else {
                out << ' ';
            }
        }
        out << endl;
    }
    // Side to move
    out << ((side_to_move == Side::WHITE) ? "White" : "Black") << " to move." << endl;
    // Who can castle
    out << "Castling: ";
    for( const auto& c : castling ) {
        if (c.second)
            switch (c.first) {
                case 'K': out << "White king-side; "; break;
                case 'Q': out << "White queen-side; "; break;
                case 'k': out << "Black king-side; "; break;
                case 'q': out << "Black queen-side; "; break;
            }
    }
    if (en_passant_sqr)
       out << "En passant square: " << en_passant_sqr->to_string() << endl;
    out << endl;
    return out.str();
}

/**
 * Get piece at given Position
 */
Piece * Board::get(int file, int rank) const {
    for (auto piece : piece_list) {
        if (piece->isAt(file, rank)) {
            return piece;
        }
    }
    return nullptr;
}

Square * Board::getSquare(int file, int rank) const {
    if (file < WIDTH and file >= 0 and rank < HEIGHT and rank >= 0)
        return SquaresBoard::get(file, rank);
    else
        throw out_of_range("Rank or file is off the board");
}

Square * Board::getSquare(string algebraic) const {
    return SquaresBoard::get(algebraic);
}

string Board::to_fen() const {
    // Return FEN representation of the current Board state.
    stringstream out;

    // <Piece Placement>
    for (int rank = height - 1; rank >= 0; rank--) {
        int empty_count = 0;
        for(int file = 0; file < width; file++) {
            auto piece = get(file, rank);
            if (piece != nullptr) {
                if (empty_count > 0) {
                    out << empty_count;
                    empty_count = 0;
                }
                out << piece->to_string();
            }
            else {
                empty_count++;
            }
        }
        if (empty_count > 0) out << empty_count; // 8
        out << ((rank > 0) ? "/" : " ");
    }

    // <Side to move>
    out << ((side_to_move == Side::WHITE) ? 'w' : 'b');
    out << " ";

    // <Castling ability>
    bool has_castling = false;
    for(const auto& c : castling)
        if (c.second) {
            has_castling = true;
            out << c.first;
        }
    if (!has_castling) out << '-';
    out << " ";

    // <En passant target square>
    if(en_passant_sqr)
        out << en_passant_sqr->to_algebraic();
    else
        out << "-";
    out << " ";

    // <Halfmove clock>
    out << half_move_counter << " ";

    // <Fullmove counter>
    out << full_move_counter;

    return out.str();
}

vector<Move *> Board::getMoves() {
    // TODO:
    // - En passant
    // - castling
    // - check for revealed checks
    vector<Move*> moves {};
    for(Piece * piece : piece_list) {
        if (piece->side == side_to_move) {
            auto places = piece->getSquares(*this); // Square Piece can potentially move to
            for (Square * sqr : places) {
                moves.push_back(new Move(this, piece, sqr));
            }
        }
    }
    return moves;
}

/*
    Move a Piece to a square.
    Returns the occupier of the Square or nullptr if none.

Piece * move(Piece * piece, Square * sqr) {
    piece->set(sqr);
    auto occupier = sqr->getOccupier();
    sqr->setOccupier(piece);
    return occupier;
}
*/
