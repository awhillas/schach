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

    vector<string> tokenise(string s) {
        auto tokens = split(s, ' ');
        auto ranks = split(tokens[0], '/');  // Piece Placement
        
        // debug
        for(auto item : tokens) {
            cout << item << endl;
        }
        // Piece placement
        for(auto item : ranks) {
            cout << item << endl;
        }
        return tokens;
    };

    void parse_side_to_move(string stm);


  public:
    FENParser(string fen) : original_fen(fen){};

    string getOriginalFEN() const {
        return original_fen;
    }

    void parse() {
        cout << original_fen << endl;
        auto tokens = tokenise(original_fen);
    
        // return new FEN(pieces, side_to_move);
    };
};