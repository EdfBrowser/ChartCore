#ifndef __D2DRENDERER_HH__
#define __D2DRENDERER_HH__

#include "IRenderer.hh"

namespace ChartCore {

class D2dRenderer : public IRenderer {
 public:
  virtual void CreateBitmap(unsigned int width, unsigned int height) override {
  };
  virtual void DrawLine(Point p1, Point p2) override {};
  virtual void DrawLineF(PointF p1, PointF p2) override {};
  virtual void Save(const wchar_t* file) override {}
};
}  // namespace ChartCore

#endif