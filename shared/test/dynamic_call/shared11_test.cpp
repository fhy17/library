#include <gtest/gtest.h>

#include "dll_proxy.h"

TEST(sharedDynamicCallTest, testShared11Sub) {
    DllProxyPtr dll_proxy = std::make_shared<DllProxy>("shared_library.dll");
    // dll_proxy->load("shared_lib.dll");
    using type = int(int, int);

    int x = 8;
    int y = 1;
    EXPECT_EQ(dll_proxy->call<type>("sub", x, y), 7);
}

TEST(sharedDynamicCallTest, testShared11Add) {
    DllProxyPtr dll_proxy = std::make_shared<DllProxy>("shared_library.dll");
    using type = int(int, int);

    int x = 8;
    int y = 1;
    EXPECT_EQ(dll_proxy->call<type>("add", x, y), 9);
}

// TEST(sharedDynamicCallTest, testShared11Print) {
//     DllProxyPtr dll_proxy = std::make_shared<DllProxy>("shared_library.dll");
//     using type = int(const char*);

//     const char* s = "1";
//     EXPECT_EQ(dll_proxy->call<type>("print", s), 1);
// }

// TEST(sharedDynamicCallTest, testShared11PrintVoid) {
//     DllProxyPtr dll_proxy = std::make_shared<DllProxy>("shared_library.dll");
//     using type = int();

//     EXPECT_EQ(dll_proxy->call<type>("printVoid"), 0);
// }

// TEST(sharedDynamicCallTest, testShared11ReturnVoid) {
//     DllProxyPtr dll_proxy = std::make_shared<DllProxy>("shared_library.dll");
//     using type = void();

//     dll_proxy->call<type>("returnVoid");
//     EXPECT_TRUE(1);
// }

// TEST(sharedDynamicCallTest, testShared11ToString) {
//     DllProxyPtr dll_proxy = std::make_shared<DllProxy>("shared_library.dll");
//     using type = const char*(int x);

//     int x = 7;
//     std::string tmp = dll_proxy->callOnce<type>("toString", x);
//     EXPECT_EQ(tmp, "7");
// }