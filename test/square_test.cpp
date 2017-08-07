#include "gtest/gtest.h"
#include "square.h"


TEST(Square, DefaultConstructor) {
	const Square s {3, 4};
	EXPECT_EQ(s.col, 3);
	EXPECT_EQ(s.row, 4);
}

TEST(Square, to_algebraic) {
	const Square s {3, 4};
	const auto notation = s.to_algebraic(); 
	EXPECT_EQ(notation, "d4");
}

TEST(Square, to_string) {
	const Square s {3, 4};
	const auto notation = s.to_string(); 
	EXPECT_EQ(notation, "d4");
}

TEST(Square, equality_operator) {
	const Square s1 {3, 4};
	const Square s2 {1, 2};
	const Square s3 {1, 2};
	ASSERT_FALSE(s1 == s2);
	ASSERT_TRUE(s2 == s3);
}