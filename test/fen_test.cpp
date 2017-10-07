#include "gtest/gtest.h"
#include "src/fen.h"


class FENTest : public ::testing::Test {
 protected:
//   virtual void SetUp() {}

//   virtual void TearDown() {}
};


TEST(FENTest, getOriginalFEN)
{
    const string std_start_pos_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    const FENParser fen { std_start_pos_fen };
    ASSERT_EQ(fen.getOriginalFEN(), std_start_pos_fen);
}
