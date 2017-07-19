#include "square.h"
#include "pieces.h"

class Move
{
    private:
        Piece *piece;
        Square *to;

    public:
        Move(Piece *p, Square *s) : piece(p), to(s){};
};