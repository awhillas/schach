# TODO

- Finish tests for all Pieces.
    - Black Pawns
    - Sliding attack pieces
        - Queen
        - Rook
        - Bishop
- Make Square aware of the piece it contains
    - Check this in Board::place_piece
- Use the SquaresBoard to handle square accounting.
  - Perhaps add a pointer to a Piece so that lookup us easier/fast.
- Replace all the calls to 'new' with smart pointers i.e. https://msdn.microsoft.com/en-us/library/hh279674.aspx
