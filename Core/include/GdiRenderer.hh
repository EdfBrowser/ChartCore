#ifndef __GDIRENDERER_HH__
#define __GDIRENDERER_HH__

#include <Windows.h>
#include <gdiplus.h>

#include <stdexcept>

#include "IRenderer.hh"

namespace ChartCore {

class GdiRenderer : public IRenderer {
 public:
  GdiRenderer() : m_bitmap(nullptr), m_st(Gdiplus::Ok) {
    m_st = Gdiplus::GdiplusStartup(&m_token, &m_gdiplusInput, NULL);
    if (m_st != Gdiplus::Ok) {
      throw new std::runtime_error("Failed to initialize GDI+!!!");
    }
  }

  ~GdiRenderer() {
    delete m_bitmap;
    Gdiplus::GdiplusShutdown(m_token);
  }

  virtual void CreateBitmap(unsigned int width, unsigned int height) {
    if (m_bitmap != nullptr) {
      delete m_bitmap;
    }

    m_bitmap = new Gdiplus::Bitmap(width, height);
  }

  virtual void Clear() override {
    Gdiplus::Graphics* g = CreateGraphics(m_bitmap);

    Gdiplus::Color bgColor(Gdiplus::Color::White);
    g->Clear(bgColor);

    delete g;
  }

  virtual void DrawLine(Point p1, Point p2) override {
    Gdiplus::Graphics* g = CreateGraphics(m_bitmap);

    Gdiplus::Color penColor(Gdiplus::Color::Black);
    Gdiplus::Pen pen(penColor);

    g->DrawLine(&pen, Gdiplus::Point(p1.x, p1.y), Gdiplus::Point(p2.x, p2.y));

    delete g;
  }

  virtual void DrawLineF(PointF p1, PointF p2) override {
    Gdiplus::Graphics* g = CreateGraphics(m_bitmap);

    Gdiplus::Color color;
    Gdiplus::Pen pen(color);

    g->DrawLine(&pen, Gdiplus::PointF(p1.x, p1.y), Gdiplus::PointF(p2.x, p2.y));

    delete g;
  }

  virtual void FillRect(Rect rect) override {
    Gdiplus::Graphics* g = CreateGraphics(m_bitmap);

    Gdiplus::SolidBrush rectBrush(Gdiplus::Color::Cyan);
    g->FillRectangle(&rectBrush,
                     Gdiplus::Rect(rect.x, rect.y, rect.width, rect.height));

    delete g;
  }

  virtual void FillRectF(RectF rect) override {
    Gdiplus::Graphics* g = Gdiplus::Graphics::FromImage(m_bitmap);

    Gdiplus::SolidBrush rectBrush(Gdiplus::Color::Cyan);
    g->FillRectangle(&rectBrush,
                     Gdiplus::RectF(rect.x, rect.y, rect.width, rect.height));

    delete g;
  }

  virtual void Save(const wchar_t* file, const wchar_t* format) override {
    CLSID pClsid;
    GetEncoderClsid(format, &pClsid);
    m_bitmap->Save(file, &pClsid, nullptr);
  }

 private:
  Gdiplus::Graphics* CreateGraphics(bool lowerQuality = false) {
    Gdiplus::Graphics* g = Gdiplus::Graphics::FromImage(m_bitmap);
    Gdiplus::SmoothingMode mode = lowerQuality ? Gdiplus::SmoothingModeAntiAlias
                                               : Gdiplus::SmoothingModeDefault;
    g->SetSmoothingMode(mode);
    return g;
  }

  int GetEncoderClsid(const wchar_t* format, CLSID* pClsid) {
    UINT num = 0;   // number of image encoders
    UINT size = 0;  // size of the image encoder array in bytes

    Gdiplus::ImageCodecInfo* pImageCodecInfo = NULL;

    Gdiplus::GetImageEncodersSize(&num, &size);
    if (size == 0) return -1;  // Failure

    pImageCodecInfo = (Gdiplus::ImageCodecInfo*)(malloc(size));
    if (pImageCodecInfo == NULL) return -1;  // Failure

    GetImageEncoders(num, size, pImageCodecInfo);

    for (UINT j = 0; j < num; ++j) {
      if (wcscmp(pImageCodecInfo[j].MimeType, format) == 0) {
        *pClsid = pImageCodecInfo[j].Clsid;
        free(pImageCodecInfo);
        return j;  // Success
      }
    }

    free(pImageCodecInfo);
    return -1;  // Failure
  }

 private:
  Gdiplus::Status m_st;
  Gdiplus::Bitmap* m_bitmap;
  UINT_PTR m_token;
  Gdiplus::GdiplusStartupInput m_gdiplusInput;
};
}  // namespace ChartCore

#endif
