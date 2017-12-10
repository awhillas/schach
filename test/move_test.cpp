#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "src/move.hpp"
#include "src/board.hpp"
#include "src/square.hpp"
#include "src/side.hpp"
#include "src/pieces.hpp"

using namespace std;


class MoveTest : public testing::Test {
protected:
    Board board;
};


TEST_F(MoveTest, ConstructorWithPieceAndSquare)
{
    Square to {1, 1};
    King piece { Side::WHITE, 0, 0 };
    Move * m = new Move { &board, &piece, &to };

    EXPECT_EQ(m->getFrom()->to_string(), "a1");
    EXPECT_EQ(m->getTo()->to_string(), "b2");
    EXPECT_EQ(m->getPiece()->to_string(), "K");

    delete m;
}

TEST_F(MoveTest, ConstructorWithTwoSquares)
{
    Square from {0, 0};
    Square to {1, 1};
    King piece { Side::WHITE, 0, 0 };
    from.setOccupier(&piece);
    Move * m = new Move { &board, &from, &to };

    EXPECT_EQ(m->getFrom()->to_string(), "a1");
    EXPECT_EQ(m->getTo()->to_string(), "b2");
    EXPECT_EQ(m->getPiece()->to_string(), "K");

    delete m;
}
