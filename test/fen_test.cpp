#include "gtest/gtest.h"
#include "src/fen.hpp"

using namespace std;


TEST(FENTest, getOriginalFEN)
{
    const string std_start_pos_fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    const FENParser fen { std_start_pos_fen };
    ASSERT_EQ(fen.getOriginalFEN(), std_start_pos_fen);
}
