#include <gtest/gtest.h>

#include "static_lib.h"

TEST(staticTest, testStaticAdd) {
    int x = 8;
    int y = 1;
    EXPECT_EQ(add(x, y), 9);
}

TEST(staticTest, testStaticSub) {
    int x = 8;
    int y = 1;
    EXPECT_EQ(sub(x, y), 7);
}