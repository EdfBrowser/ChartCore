#include <iostream>

#include "bindings.hh"

int main(int argc, char** argv) {
  void* ptr = createContext(0);
  Render(ptr, 500, 500);

  SaveToFile(L"out.png", ptr);

  destroyContext(ptr);
  return 0;
}