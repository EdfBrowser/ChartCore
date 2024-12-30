#include "RendererContext.hh"

// #if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
// #define DLL_API __attribute__((visibility("default")))
// #elif defined(_MSC_VER)
// #if defined(DLL_EXPORTS)
// #define DLL_API __declspec(dllexport)
// #endif
// #endif
#define DLL_EXPORTS

#if defined(DLL_EXPORTS)
#define DLL_API __declspec(dllexport)
// #else
// #define DLL_API __declspec(dllimport)
#endif

extern "C" {
DLL_API void* createContext(int type);
DLL_API bool destroyContext(void* ptr);
DLL_API void Render(void* ptr, unsigned int width, unsigned int height);
DLL_API void SaveToFile(const WCHAR* file, void* ptr);
}
