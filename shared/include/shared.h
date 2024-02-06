#pragma once

#ifdef TEST_EXPORTS
#define EXPORT_DLL __declspec(dllexport)
#else
#define EXPORT_DLL __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

EXPORT_DLL int __stdcall add(int a, int b);

EXPORT_DLL int __stdcall sub(int x, int y);

EXPORT_DLL int __stdcall print(const char* s);

EXPORT_DLL int __stdcall printVoid();

EXPORT_DLL void __stdcall returnVoid();

EXPORT_DLL const char* __stdcall toString(int x);

#ifdef __cplusplus
}
#endif