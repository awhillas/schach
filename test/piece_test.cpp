#include "gtest/gtest.h"

#include "src/pieces.h"
#include "src/side.h"
#include "src/board.h"




TEST(Pieces, DefaultConstructor) {
    const Piece p {Side::WHITE, 3, 4};
}

// see: https://github.com/google/googletest/blob/master/googletest/samples/sample3_unittest.cc
class KingTest : public testing::Test {
    protected:
        virtual void SetUp() {

        }
    Board b;
}

TEST_F(KingTest, AllMoves) {
    const King k { Side::WHITE, 4, 4 };
    auto moves = k.getMoves();
    std::find()
}
