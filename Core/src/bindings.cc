#include "bindings.hh"

/**
 * @brief Creates a RendererContext object.
 *
 * Only the following values are allowed:
 * - 0 corresponds to RendererType::CPU
 * - 1 corresponds to RendererType::GPU
 *
 * @param type The integer representation of the RendererType enum.
 * @return void* A pointer to a new RendererContext. Returns nullptr if the
 * input is invalid.
 */
DLL_API void* createContext(int type) {
  if (type < 0 || type > 1) {
    return nullptr;
  }

  ChartCore::RendererType rendererType =
      static_cast<ChartCore::RendererType>(type);
  return new ChartCore::RendererContext(rendererType);
}

/**
 * @brief Destroys a RendererContext object.
 *
 * Deletes the RendererContext instance created by createContext.
 *
 * @param ptr A void* pointer to the RendererContext instance to be deleted.
 */
DLL_API bool destroyContext(void* ptr) {
  if (ptr == nullptr) {
    return false;
  }

  ChartCore::RendererContext* contextPrt =
      static_cast<ChartCore::RendererContext*>(ptr);

  delete contextPrt;
  return true;
}

DLL_API void Render(void* ptr, unsigned int width, unsigned int height) {
  if (ptr == nullptr) {
    return;
  }

  ChartCore::RendererContext* contextPrt =
      static_cast<ChartCore::RendererContext*>(ptr);

  contextPrt->Render(width, height);
}

DLL_API void SaveToFile(const WCHAR* file, void* ptr) {
  if (ptr == nullptr) {
    return;
  }
  ChartCore::RendererContext* contextPrt =
      static_cast<ChartCore::RendererContext*>(ptr);
  contextPrt->Save(file);
}