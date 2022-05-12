#include <gtest/gtest.h>
#include "src/message.h"

TEST(A, B) {
    std::stringstream out;
    message(out, "% % %", "sdfsd", 121, 'c');
    EXPECT_EQ("sdfsd 121 c", out.str());
}
