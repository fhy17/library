#include <gtest/gtest.h>

#include "shared_proxy.hpp"

TEST(sharedDynamicCallTest, testSharedSub) {
    std::shared_ptr<SharedProxy> dll_proxy = std::make_shared<SharedProxy>();
    auto ret = dll_proxy->load();

    int x = 8;
    int y = 1;
    EXPECT_EQ(dll_proxy->sub(x, y), 7);
}

TEST(sharedDynamicCallTest, testSharedAdd) {
    std::shared_ptr<SharedProxy> dll_proxy = std::make_shared<SharedProxy>();
    auto ret = dll_proxy->load();

    int x = 8;
    int y = 1;
    EXPECT_EQ(dll_proxy->add(x, y), 9);
}