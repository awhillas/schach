#include "gtest/gtest.h"

#include "src/board.hpp"
#include "src/pieces.hpp"
#include "src/side.hpp"


using namespace std;


class BoardTest : public testing::Test {
protected:
    virtual void SetUp() {}
    virtual void TearDown() {}
    Board b;  // not working???
};


TEST_F(BoardTest, ConstructorNoArgs)
{
    ASSERT_EQ(b.width, 8);
    ASSERT_EQ(b.height, 8);
}

TEST_F(BoardTest, ConstructorWithArgs)
{
    const Board b1 = Board {666, 69};

    ASSERT_EQ(b1.width, 666);
    ASSERT_EQ(b1.height, 69);
}

TEST_F(BoardTest, PlacePieceMethodPassPieceVersion)
{
    Piece p = Piece {Side::WHITE, 4, 4};  // generic piece
    b.place_piece(p);
    Piece * ptr = b.get(4, 4);

    ASSERT_EQ(&p, ptr);  // same object
    ASSERT_EQ(p.getPosition(), ptr->getPosition());
}

TEST_F(BoardTest, PlacePieceMethodFactoryVersion)
{
    Piece * p = b.place_piece('P', 4, 4);
    Piece * ptr = b.get(4, 4);

    ASSERT_EQ(p, ptr);  // same object
    ASSERT_EQ(p->getPosition(), ptr->getPosition());
}
