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

struct Rect {
  unsigned int x;
  unsigned int y;
  unsigned int width;
  unsigned int height;

  Rect(unsigned int xVal, unsigned int yVal, unsigned int wVal,
       unsigned int hVal)
      : x(xVal), y(yVal), width(wVal), height(hVal) {}
};

struct RectF {
  float x;
  float y;
  float width;
  float height;

  RectF(float xVal, float yVal, float wVal, float hVal)
      : x(xVal), y(yVal), width(wVal), height(hVal) {}
};

class IRenderer {
 public:
  virtual ~IRenderer() = default;

  virtual void CreateBitmap(unsigned int width, unsigned int height) = 0;
  virtual void DrawLine(Point p1, Point p2) = 0;
  virtual void DrawLineF(PointF p1, PointF p2) = 0;
  virtual void Save(const wchar_t* file, const wchar_t* format) = 0;
  virtual void FillRect(Rect rect) = 0;
  virtual void FillRectF(RectF rect) = 0;
  virtual void Clear() = 0;
};
}  // namespace ChartCore
#endif