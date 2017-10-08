#include "gtest/gtest.h"

#include "src/pieces.h"
#include "src/side.h"


TEST(Pieces, DefaultConstructor) {
  const Piece p {Side::WHITE, 3, 4};
}
