#ifndef __GDIPLUSMANAGER_HH__
#define __GDIPLUSMANAGER_HH__

// #if defined(__clang__) || defined(__GNUC__) || defined(__GNUG__)
// #define DLL_API __attribute__((visibility("default")))
// #elif defined(_MSC_VER)
// #if defined(DLL_EXPORTS)
// #define DLL_API __declspec(dllexport)
// #endif
// #endif
#define DLL_EXPORTS

#if defined(DLL_EXPORTS)
#define DLL_API __declspec(dllexport)
// #else
// #define DLL_API __declspec(dllimport)
#endif

namespace ChartCore {
#include <Windows.h>
#include <gdiplus.h>

class GdiplusManager {
 public:
  GdiplusManager() : st(Gdiplus::Ok) {
    st = Gdiplus::GdiplusStartup(&_token, &_gdiplusInput, NULL);
  }
  ~GdiplusManager() { Gdiplus::GdiplusShutdown(_token); }

  INT GetEncoderClsid(const WCHAR* format, CLSID* pClsid) {
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

 public:
  Gdiplus::Status st;

 private:
  UINT_PTR _token;
  Gdiplus::GdiplusStartupInput _gdiplusInput;
};
}  // namespace ChartCore

#endif  // GdiplusManager.hh
