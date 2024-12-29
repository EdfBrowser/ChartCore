#include "bindings.hh"

DLL_API ChartCore::GdiplusManager* createGdiplusManager() {
  return new ChartCore::GdiplusManager();
}

DLL_API void destroyGdiplusManager(ChartCore::GdiplusManager* manager) {
  delete manager;
}