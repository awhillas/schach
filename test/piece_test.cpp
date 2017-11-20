#include <sstream>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "src/pieces.hpp"
#include "src/side.hpp"
#include "src/board.hpp"
#include "src/square.hpp"


using namespace testing;
using namespace std;


TEST(Pieces, DefaultConstructor) {
    const Piece p {Side::WHITE, 3, 4};
}

// see: https://github.com/google/googletest/blob/master/googletest/samples/sample3_unittest.cc
class PieceTest : public testing::Test {
protected:
    // Convert list of array pointers to a string for easy testing.
    template <class T>
    string vector_to_string(vector<T> listOfThings) {
        stringstream out;
        for (T thing : listOfThings) {
            out << thing->to_string();
        }
        return out.str();
    }

    Board b;
};


/*******************************************************************************
 Kight testing
*******************************************************************************/

TEST_F(PieceTest, KingAllMoves) {
    King k { Side::WHITE, 4, 4 };   // e5

    b.place_piece(k);
    auto squares = k.getSquares(b);
    EXPECT_EQ(8, squares.size());

    string test_strip = vector_to_string(squares);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("d6"));
    EXPECT_THAT(test_strip, HasSubstr("e6"));
    EXPECT_THAT(test_strip, HasSubstr("f6"));
    EXPECT_THAT(test_strip, HasSubstr("d5"));
    EXPECT_THAT(test_strip, HasSubstr("f5"));
    EXPECT_THAT(test_strip, HasSubstr("d4"));
    EXPECT_THAT(test_strip, HasSubstr("e4"));
    EXPECT_THAT(test_strip, HasSubstr("f4"));
};

TEST_F(PieceTest, KingEdgeCaseLowerLeft) {
    King k { Side::WHITE, 0, 0 };

    b.place_piece(k);
    auto squares = k.getSquares(b);
    EXPECT_EQ(3, squares.size());

    string test_strip = vector_to_string(squares);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("a2"));
    EXPECT_THAT(test_strip, HasSubstr("b2"));
    EXPECT_THAT(test_strip, HasSubstr("b1"));
};

TEST_F(PieceTest, KingEdgeCaseUpperRight) {
    King k { Side::WHITE, 7, 7 };

    b.place_piece(k);
    auto squares = k.getSquares(b);
    EXPECT_EQ(3, squares.size());

    string test_strip = vector_to_string(squares);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("g8"));
    EXPECT_THAT(test_strip, HasSubstr("g7"));
    EXPECT_THAT(test_strip, HasSubstr("h7"));
};


/*******************************************************************************
 Kight testing
*******************************************************************************/

TEST_F(PieceTest, KnightAllMoves) {
    Knight n { Side::WHITE, 3, 3 };  // d4

    b.place_piece(n);
    auto squares = n.getSquares(b);
    EXPECT_EQ(8, squares.size());

    string test_strip = vector_to_string(squares);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("c6"));
    EXPECT_THAT(test_strip, HasSubstr("e6"));
    EXPECT_THAT(test_strip, HasSubstr("b5"));
    EXPECT_THAT(test_strip, HasSubstr("f5"));
    EXPECT_THAT(test_strip, HasSubstr("b3"));
    EXPECT_THAT(test_strip, HasSubstr("c2"));
    EXPECT_THAT(test_strip, HasSubstr("f3"));
    EXPECT_THAT(test_strip, HasSubstr("e2"));
}

TEST_F(PieceTest, KnightEdgeCaseLowerLeft) {
    Knight k { Side::WHITE, 0, 0 };

    b.place_piece(k);
    auto squares = k.getSquares(b);
    EXPECT_EQ(2, squares.size());

    string test_strip = vector_to_string(squares);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("b3"));
    EXPECT_THAT(test_strip, HasSubstr("c2"));
};

TEST_F(PieceTest, KnightEdgeCaseUpperRight) {
    Knight k { Side::WHITE, 7, 7 };

    b.place_piece(k);
    auto squares = k.getSquares(b);
    EXPECT_EQ(2, squares.size());

    string test_strip = vector_to_string(squares);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("f7"));
    EXPECT_THAT(test_strip, HasSubstr("g6"));
};


/*******************************************************************************
 Pawn testing
*******************************************************************************/

TEST_F(PieceTest, WhitePawnInitialPosition) {
    Pawn p1 = Pawn { Side::WHITE, 1, 1 };  // b2
    b.place_piece(p1);

    auto squares1 = p1.getSquares(b);
    EXPECT_EQ(2, squares1.size());

    string test_strip = vector_to_string(squares1);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("b3"));
    EXPECT_THAT(test_strip, HasSubstr("b4"));

    // Obstructed from double move

    Pawn p2 = Pawn { Side::WHITE, 1, 3 };  // b4
    b.place_piece(p2);

    auto squares2 = p1.getSquares(b);
    EXPECT_EQ(1, squares2.size());

    string test_strip2 = vector_to_string(squares2);  // list -> string
    EXPECT_THAT(test_strip2, HasSubstr("b3"));

    // Obstructed from single move

    Pawn p3 = Pawn { Side::WHITE, 1, 2 };  // b3
    b.place_piece(p3);

    auto squares3 = p1.getSquares(b);
    EXPECT_EQ(0, squares3.size());
}

TEST_F(PieceTest, WhitePawnTaking) {
    Pawn p = Pawn { Side::WHITE, 2, 2 };  // c3
    b.place_piece(p);
    Pawn p1 = Pawn { Side::BLACK, 1, 3 };  // b4
    b.place_piece(p1);
    Pawn p2 = Pawn { Side::BLACK, 3, 3 };  // d4
    b.place_piece(p2);

    auto squares = p.getSquares(b);
    EXPECT_EQ(3, squares.size());

    string test_strip = vector_to_string(squares);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("b4"));
    EXPECT_THAT(test_strip, HasSubstr("c4"));
    EXPECT_THAT(test_strip, HasSubstr("d4"));
}

TEST_F(PieceTest, BlackPawnInitialPosition) {
    Pawn p = Pawn { Side::BLACK, 6, 6 };  // g7
    b.place_piece(p);

    auto squares = p.getSquares(b);
    EXPECT_EQ(2, squares.size());

    string test_strip = vector_to_string(squares);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("g6"));
    EXPECT_THAT(test_strip, HasSubstr("g5"));

    // Obstructed from double move

    Pawn p1 = Pawn { Side::BLACK, 6, 4 };  // g5
    b.place_piece(p1);
    auto squares2 = p.getSquares(b);
    EXPECT_EQ(1, squares2.size());

    string test_strip2 = vector_to_string(squares2);  // list -> string
    EXPECT_THAT(test_strip2, HasSubstr("g6"));

    // Obstructed from single move

    Pawn p2 = Pawn { Side::BLACK, 6, 5 };  // g6
    b.place_piece(p2);
    auto squares3 = p.getSquares(b);
    EXPECT_EQ(0, squares3.size());
}

TEST_F(PieceTest, BlackPawnTaking) {
    Pawn p = Pawn { Side::BLACK, 5, 5 };  // f6
    b.place_piece(p);
    Pawn p1 = Pawn { Side::WHITE, 6, 4 };  // g5
    b.place_piece(p1);
    Pawn p2 = Pawn { Side::WHITE, 4, 4 };  // e5
    b.place_piece(p2);

    auto squares = p.getSquares(b);
    EXPECT_EQ(3, squares.size());

    string test_strip = vector_to_string(squares);  // list -> string
    EXPECT_THAT(test_strip, HasSubstr("f5"));
    EXPECT_THAT(test_strip, HasSubstr("g5"));
    EXPECT_THAT(test_strip, HasSubstr("e5"));
}
