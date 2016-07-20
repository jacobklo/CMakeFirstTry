#include "Main.h"
#include "Lib1/Lib1.h"
#include <iostream>

int main()
{
  Lib1 l;
  std::cout << "Hello";
  std::cout << l.getText();
  return 0;
}