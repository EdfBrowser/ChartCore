#ifndef __IRENDERER_HH__
#define __IRENDERER_HH__

namespace ChartCore {

struct Point {
  unsigned int x;
  unsigned int y;

  Point(unsigned int xVal, unsigned int yVal) : x(xVal), y(yVal) {}
};

struct PointF {
  float x;
  float y;

  PointF(float xVal, float yVal) : x(xVal), y(yVal) {}
};

class IRenderer {
 public:
  virtual ~IRenderer() = default;

  virtual void CreateBitmap(unsigned int width, unsigned int height) = 0;
  virtual void DrawLine(Point p1, Point p2) = 0;
  virtual void DrawLineF(PointF p1, PointF p2) = 0;
  virtual void Save(const wchar_t* file) = 0;
};
}  // namespace ChartCore
#endif