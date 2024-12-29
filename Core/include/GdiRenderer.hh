#ifndef __G
namespace ChartCore {
#include <gdiplus.h>

#include "GdiplusManager.hh"
class IRenderer {
 public:
  virtual ~IRenderer() = 0;
  virtual void Draw() = 0;
};
IRenderer::~IRenderer() {}

class GdiRenderer : public IRenderer {
 public:
  ~GdiRenderer() override {}
  void Draw() override {}

 private:
};
}  // namespace ChartCore
