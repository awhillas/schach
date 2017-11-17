#include "gtest/gtest.h"

#include "src/square.h"


TEST(Square, DefaultConstructor) {
	const Square s {3, 4};
	EXPECT_EQ(s.col, 3);
	EXPECT_EQ(s.row, 4);
}

TEST(Square, to_algebraic) {
	const Square s {7, 7}; // zero indexed!
	const auto notation = s.to_algebraic();
	EXPECT_EQ("h8", notation);
}

TEST(Square, to_string) {
	const Square s {0, 0};
	const auto notation = s.to_string();
	EXPECT_EQ("a1", notation);
}

TEST(Square, equality_operator) {
	const Square s1 {3, 4};
	const Square s2 {1, 2};
	const Square s3 {1, 2};
	ASSERT_FALSE(s1 == s2);
	ASSERT_TRUE(s2 == s3);
}

TEST(Square, from_algebratic) {
	auto s1 = Square::from_algebratic("a8");
	EXPECT_EQ(s1->col, 0);
	EXPECT_EQ(s1->row, 7);

	auto s2 = Square::from_algebratic("h1");
	EXPECT_EQ(s2->col, 7);
	EXPECT_EQ(s2->row, 0);

}
