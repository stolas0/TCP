#include <gtest/gtest.h>
#include <array>
#include "src/tie.h"

TEST(A, B) {
    array<int, 3> a1, a2;
    array<int, 6> b{1, 2, 3, 4, 5, 6};
    mytie(a1, a2) = b;
    array<int, 3> c1{1, 2, 3};
    array<int, 3> c2{4, 5, 6};
    EXPECT_EQ(a1, c1);
    EXPECT_EQ(a2, c2);
}
