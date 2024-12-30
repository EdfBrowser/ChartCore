#ifndef __RENDERERCONTEXT_HH__
#define __RENDERERCONTEXT_HH__

#include "D2dRenderer.hh"
#include "GdiRenderer.hh"

namespace ChartCore {

using byte = unsigned char;
enum class RendererType : byte { CPU, GPU };

class RendererContext {
 public:
  RendererContext(RendererType type) {
    if (type == RendererType::CPU) {
      m_renderer = new GdiRenderer();
    } else if (type == RendererType::GPU) {
      m_renderer = new D2dRenderer();
    }
  }

  ~RendererContext() { delete m_renderer; }

  void Render(unsigned int width, unsigned int height) {
    m_renderer->CreateBitmap(width, height);
    m_renderer->DrawLine(Point(10, 10), Point(200, 200));
  }

  void Save(const WCHAR* file) { m_renderer->Save(file); }

 private:
  IRenderer* m_renderer;
};
}  // namespace ChartCore

#endif