#include <sstream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "src/pieces.h"
#include "src/side.h"
#include "src/board.h"
#include "src/square.h"


using namespace testing;

// Convert list of array pointers to a string for easy testing.
template <class T>
std::string vector_to_string(std::vector<T> listOfThings) {
    stringstream out;
    for (T thing : listOfThings) {
        out << thing->to_string();
    }
    return out.str();
}

TEST(Pieces, DefaultConstructor) {
    const Piece p {Side::WHITE, 3, 4};
}

// see: https://github.com/google/googletest/blob/master/googletest/samples/sample3_unittest.cc
class PieceTest : public testing::Test {
    protected:
        // virtual void SetUp() {}
        Board b;
};


/*******************************************************************************
 Kight testing
*******************************************************************************/

TEST_F(PieceTest, KingAllMoves) {
    King k { Side::WHITE, 4, 4 };   // e5

    b.place_piece(k);
    auto squares = k.getMoves(b);
    ASSERT_EQ(8, squares.size());

    std::string test_strip = vector_to_string(squares);  // list -> string
    ASSERT_THAT(test_strip, HasSubstr("d6"));
    ASSERT_THAT(test_strip, HasSubstr("e6"));
    ASSERT_THAT(test_strip, HasSubstr("f6"));
    ASSERT_THAT(test_strip, HasSubstr("d5"));
    ASSERT_THAT(test_strip, HasSubstr("f5"));
    ASSERT_THAT(test_strip, HasSubstr("d4"));
    ASSERT_THAT(test_strip, HasSubstr("e4"));
    ASSERT_THAT(test_strip, HasSubstr("f4"));
};

TEST_F(PieceTest, KingEdgeCaseLowerLeft) {
    King k { Side::WHITE, 0, 0 };

    b.place_piece(k);
    auto squares = k.getMoves(b);
    ASSERT_EQ(3, squares.size());

    std::string test_strip = vector_to_string(squares);  // list -> string
    ASSERT_THAT(test_strip, HasSubstr("a2"));
    ASSERT_THAT(test_strip, HasSubstr("b2"));
    ASSERT_THAT(test_strip, HasSubstr("b1"));
};

TEST_F(PieceTest, KingEdgeCaseUpperRight) {
    King k { Side::WHITE, 7, 7 };

    b.place_piece(k);
    auto squares = k.getMoves(b);
    ASSERT_EQ(3, squares.size());

    std::string test_strip = vector_to_string(squares);  // list -> string
    ASSERT_THAT(test_strip, HasSubstr("g8"));
    ASSERT_THAT(test_strip, HasSubstr("g7"));
    ASSERT_THAT(test_strip, HasSubstr("h7"));
};


/*******************************************************************************
 Kight testing
*******************************************************************************/

TEST_F(PieceTest, KnightAllMoves) {
    Knight n { Side::WHITE, 3, 3 };  // d4

    b.place_piece(n);
    auto squares = n.getMoves(b);
    ASSERT_EQ(8, squares.size());

    std::string test_strip = vector_to_string(squares);  // list -> string
    ASSERT_THAT(test_strip, HasSubstr("c6"));
    ASSERT_THAT(test_strip, HasSubstr("e6"));
    ASSERT_THAT(test_strip, HasSubstr("b5"));
    ASSERT_THAT(test_strip, HasSubstr("f5"));
    ASSERT_THAT(test_strip, HasSubstr("b3"));
    ASSERT_THAT(test_strip, HasSubstr("c2"));
    ASSERT_THAT(test_strip, HasSubstr("f3"));
    ASSERT_THAT(test_strip, HasSubstr("e2"));
}
