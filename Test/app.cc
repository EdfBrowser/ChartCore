#include <iostream>

#include "bindings.hh"

int main(int argc, char** argv) {
  auto ptr = createGdiplusManager();
  std::cout << "st:" << ptr->st << std::endl;
  destroyGdiplusManager(ptr);
  return 0;
}