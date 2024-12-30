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

  void Resize(unsigned int width, unsigned int height) {
    if (width < 10 || height < 10) return;
    m_renderer->CreateBitmap(width, height);
    Render();
  }

  void Render() {
    // 计算出边距

    m_renderer->Clear();
    m_renderer->DrawLine(Point(10, 10), Point(200, 200));
    m_renderer->FillRect(Rect(200, 200, 400, 400));

    m_renderer->DrawString(L"World", Font(L"Consolas", 12, 0), PointF(400, 400));
  }

  void Save(const wchar_t* file, const wchar_t* format) {
    m_renderer->Save(file, format);
  }

 private:
  void Layout() {}

 private:
  IRenderer* m_renderer;
};
}  // namespace ChartCore

#endif