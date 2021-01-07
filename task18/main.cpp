#include <iostream>
#include "MaxPrefixSymbol.h"

int main() {
  std::string regular;
  char symbol;
  std::cin >> regular;
  std::cin >> symbol;
  std::cout << MaxPrefixSymbol(regular, symbol);
  return 0;
}
