# TODO

- Move generation
    - En passant
        - Add to board after double pawn move
        - check for opposing pawn in correct Position
        - remove from board
    - Castling
        - check pass though squares are not attacked.
    - Reveal check
- Make Square aware of the piece it contains
    - Check this in Board::place_piece
    - Perhaps add a pointer to a Piece so that lookup us easier/fast.
- Replace all the calls to 'new' with smart pointers i.e. https://msdn.microsoft.com/en-us/library/hh279674.aspx

- Search
    - Min-Max tree search.
    - Alpha-Beta tree search.
    - Monty-Carlo tree search.

- Interface
    - cli
    - UCI
    - Web Interface?
