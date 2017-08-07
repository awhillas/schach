#include "gtest/gtest.h"
#include "pieces.h"
#include "side.h"


TEST(Pieces, DefaultConstructor) {
  const Piece p {Side::WHITE, 3, 4};
}