#ifdef DEBUG
#include <gtest/gtest.h>
#endif
#include <iostream>
#include "MaxPrefixSymbol.h"

int main() {
#ifdef DEBUG
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
#endif
  std::string regular;
  char symbol;
  std::cin >> regular;
  std::cin >> symbol;
  std::cout << MaxPrefixSymbol(regular, symbol);
  return 0;
}
