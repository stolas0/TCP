#include <gtest/gtest.h>
#include "rotate.h"

int main() {
    Vector<int> vec(1, 2);

    Vector<int> ans1(1, 2);
    EXPECT_EQ(ans1, rotate(vec, -360));

    Vector<int> ans2(1, 2);
    EXPECT_EQ(ans2, rotate(vec, 360));
    
    Vector<int> ans3(-2, 1);
    EXPECT_EQ(ans3, rotate(vec, 90));
    
    Vector<int> ans4(-1, -2);
    EXPECT_EQ(ans4, rotate(vec, 180));
    
    Vector<int> ans5(2, -1);
    EXPECT_EQ(ans5, rotate(vec, 270));

    EXPECT_FALSE(Vector<int>(1, 1) == Vector<int>(1, 2));
    EXPECT_FALSE(Vector<int>(1, 1) == Vector<int>(2, 1));

    return 0;
}
