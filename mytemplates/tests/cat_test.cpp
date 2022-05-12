#include <gtest/gtest.h>
#include <array>
#include <src/cat.h>

TEST(A, B) {
    array<int, 3> a{1, 2, 3};
    array<int, 3> b{4, 5, 6};
    array<int, 6> c{1, 2, 3, 4, 5 ,6};
    EXPECT_EQ(c, cat(a, b));
}
