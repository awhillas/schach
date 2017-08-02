#include <iostream>
#include <vector>
#include <string>

#include "split.cpp"
#include "board.h"

using namespace std;


class FENParser
{
    /* 
    FEN parser.

    Forsyth-Edwards Notation (FEN) describes a Chess Position. It is an one-line 
    ASCII-string. FEN is based on a system created by Scotsman David Forsyth in 
    the 19th century. Steven Edwards specified the FEN standard for computer chess 
    applications as part of the Portable Game Notation (PGN).

    <FEN> ::=  <Piece Placement>
       ' ' <Side to move>
       ' ' <Castling ability>
       ' ' <En passant target square>
       ' ' <Halfmove clock>
       ' ' <Fullmove counter>
    
    <Piece Placement> ::= <rank8>'/'<rank7>'/'<rank6>'/'<rank5>'/'<rank4>'/'<rank3>'/'<rank2>'/'<rank1>
    <ranki>       ::= [<digit17>]<piece> {[<digit17>]<piece>} [<digit17>] | '8'
    <piece>       ::= <white Piece> | <black Piece>
    <digit17>     ::= '1' | '2' | '3' | '4' | '5' | '6' | '7'
    <white Piece> ::= 'P' | 'N' | 'B' | 'R' | 'Q' | 'K'
    <black Piece> ::= 'p' | 'n' | 'b' | 'r' | 'q' | 'k'

    <Side to move> ::= {'w' | 'b'}

    <Castling ability> ::= '-' | ['K'] ['Q'] ['k'] ['q'] (1..4)

    <En passant target square> ::= '-' | <epsquare>
    <epsquare>   ::= <fileLetter> <eprank>
    <fileLetter> ::= 'a' | 'b' | 'c' | 'd' | 'e' | 'f' | 'g' | 'h'
    <eprank>     ::= '3' | '6'
        
    <Halfmove Clock> ::= <digit> {<digit>}
    <digit> ::= '0' | '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'

    <Fullmove counter> ::= <digit19> {<digit>}
    <digit19> ::= '1' | '2' | '3' | '4' | '5' | '6' | '7' | '8' | '9'
    <digit>   ::= '0' | <digit19>
    */
  private:
    string original_fen;

    void parse_piece_placement(vector<string> ranks, shared_ptr<Board> board) {
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
                    board->place_piece(p, current_rank, current_file);
                    current_file++;
                }
                else {
                    throw range_error("Not a nunmber or a known piece type: " + p)
                }
            }
            current_file = 0;
            current_rank--;
        }
        
    }

    void parse_side_to_move(string stm);


  public:
    FENParser(string fen) : original_fen(fen){};

    string getOriginalFEN() const {
        return original_fen;
    }

    void parse() {
        shared_ptr<Board> board = make_shared<Board>();
        auto tokens = split(original_fen, ' ');
        auto ranks = split(tokens[0], '/');  // Piece Placement

        parse_piece_placement(ranks, board);
    
        // return board;
    };
};