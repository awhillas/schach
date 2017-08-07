#include "fen.h"


using namespace std;


FENParser::FENParser(string fen) : original_fen(fen){};

void FENParser::parse_piece_placement(vector<string> ranks, Board* board) {
    // TODO: remove this hard coded dependancy on these strings? But is part of FEN...?
    static const char white[] = "kqbnrp";
    static const char black[] = "KQBNRP";
    
    int current_rank = 7;  // start at the 8th rank
    int current_file = 0;
    for(auto rank : ranks) {
        for (char p : rank) {
            if ('0' <= p && p <= '8') {
                current_file += p - '0';
            }
            else if (strchr(white, p) != NULL || strchr(black, p) != NULL) {
                // board->place_piece(p, current_rank, current_file);
                current_file++;
            }
            else {
                throw range_error(string("Not a number or a known piece type: ") + p);
            }
        }
        current_file = 0;
        current_rank--;
    }
}

void FENParser::parse_side_to_move(string stm) {}

string FENParser::getOriginalFEN() const {
    return original_fen;
}

void FENParser::parse() {
    // Can't get these working :(
    // shared_ptr<Board> board = make_shared<Board>();
    // std::shared_ptr<Board> board(new Board());
    Board * board = new Board();

    auto tokens = split(original_fen, ' ');
    auto ranks = split(tokens[0], '/');  // Piece Placement

    parse_piece_placement(ranks, board);

    board->to_string();

    // parse_side_to_move();

    // return board;
};
