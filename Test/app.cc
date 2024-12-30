#include <iostream>

#include "bindings.hh"

int main(int argc, char** argv) {
  void* ptr = CreateContext(0);
  Resize(ptr, 800, 800);
  Render(ptr);

  SaveToFile(L"out.png", L"image/png", ptr);
  SaveToFile(L"out.jpeg", L"image/jpeg", ptr);
  SaveToFile(L"out.bmp", L"image/bmp", ptr);

  DestroyContext(ptr);
  return 0;
}