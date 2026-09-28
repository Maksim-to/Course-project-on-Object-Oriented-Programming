#pragma once
#include <string>

using namespace std;

#ifdef DLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif


DLL_API void UpdateFile();
DLL_API string ShowAll();
DLL_API string CheckMemory();
DLL_API string GetCount();
DLL_API bool Reverse();
DLL_API bool Sort();
DLL_API bool Swap(int a, int b);
DLL_API void Add(string Title, double price, int amount);
DLL_API void Add(string Title, double price, int amount, string producer);
DLL_API void Delete(int a);