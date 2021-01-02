#ifdef DEBUG
#include <gtest/gtest.h>
#endif
#include <iostream>
#include <vector>
#include <string>
#include "Grammar.h"


void scanrules(std::vector<std::vector<std::string>> &rules) {
  int n;
  std::cout << "Введите количество правил в вашей КС-грамматике\n";
  std::cin >> n;
  char noterminal;
  std::string rule;
  std::cout << "Далее введите через пробел нетерминал и правило\n";
  for (int i = 0; i < n; ++i) {
    std::cin >> noterminal >> rule;
    rules[noterminal].push_back(rule);
  }
}


int main()
{
#ifdef DEBUG
  ::testing::InitGoogleTest();
  return RUN_ALL_TESTS();
#endif

  std::vector<std::vector<std::string>> rules('Z',std::vector<std::string>());

  scanrules(rules);
  std::cout << "Введите стартовый нетерминал\n";
  std::string start;
  std::cin >> start;
  Grammar grammar(rules, start);

  std::cout << "Введите слово, которое хотите проверить на принадлежность к этой КС-грамматике\n";
  std::string word;
  std::cin >> word;
  if (grammar.EarleyParser(word)) {
    std::cout << "Ваше слово принадлежит данной КС-грамматике\n";
  } else {
    std::cout << "Ваше слово не принадлежит данной КС-грамматике\n";
  }

  return 0;
}
