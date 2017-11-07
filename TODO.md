# TODO

- Finish tests for all Pieces.
    - Black Pawns
    - Sliding attack pieces
        - Queen
        - Rook
        - Bishop
- Use the SquaresBoard to handle square accounting.
  - !!! Return a pointer to the Square instead of the unique_ptr<Square> from
  - Perhaps add a pointer to a Piece so that lookup us easier/fast.
- Replace all the calls to 'new' with smart pointers i.e. https://msdn.microsoft.com/en-us/library/hh279674.aspx
