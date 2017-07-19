#include "side.h"
#include "square.h"
#include "board.h"
#include "move.h"


class Piece
{
    private:
        enum Side side;
        Square *position;

    public:
        Piece(Side colour, Square *square) : side(colour), position(square){};
        Move *getMoves(Board *board);
};

class King : public Piece
{
    public:
        Move *getMoves(Board *board);
};