#include "GdiplusManager.hh"

extern "C" {
DLL_API ChartCore::GdiplusManager* createGdiplusManager();
DLL_API void destroyGdiplusManager(ChartCore::GdiplusManager* manager);
}
