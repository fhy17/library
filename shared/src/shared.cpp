#include "shared.h"

#include <string>

int add(int x, int y) { return x + y; }

int sub(int x, int y) { return x - y; }

int print(const char* s) { return 1; }

int printVoid() { return 0; }

void returnVoid() { return; }

const char* toString(int x) {
    std::string s = std::to_string(x);
    return s.c_str();
}
