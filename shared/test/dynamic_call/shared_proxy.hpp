#pragma once

#include <string>
#include <windows.h>

std::string getCurrentModPath() {
    char path[MAX_PATH] = {};
    GetModuleFileNameA(0, path, MAX_PATH);
    std::string tmp_path = path;

    auto pos = tmp_path.rfind("\\");
    if (pos != tmp_path.npos) {
        return std::move(tmp_path.substr(0, pos));
    }

    return std::string();
}

class SharedProxy {
public:
    SharedProxy() : module_(nullptr) {}
    ~SharedProxy() { unload(); }

    typedef int (*add_func)(int x, int y);
    typedef int (*sub_func)(int x, int y);

    bool load() {
        std::string cur_path = getCurrentModPath();

        auto mod = cur_path + "\\shared_library.dll";
        module_ = LoadLibrary(mod.c_str());
        if (module_ == NULL) {
            auto err = GetLastError();
            return false;
        } else {
            add_fo_ = (add_func)GetProcAddress(module_, "add");
            sub_fo_ = (sub_func)GetProcAddress(module_, "sub");
        }
        return true;
    }
    void unload() { FreeLibrary(module_); }

    int add(int x, int y) { return add_fo_(x, y); }
    int sub(int x, int y) { return sub_fo_(x, y); }

private:
    HMODULE module_;

    add_func add_fo_;
    sub_func sub_fo_;
};