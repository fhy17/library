#include <gtest/gtest.h>

#include "shared.h"

TEST(sharedTest, testStaticAdd) {
    int x = 8;
    int y = 1;
    EXPECT_EQ(add(x, y), 9);
}

TEST(sharedTest, testStaticSub) {
    int x = 8;
    int y = 1;
    EXPECT_EQ(sub(x, y), 7);
}