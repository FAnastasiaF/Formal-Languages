#include <iostream>
#include <vector>
#include <string>
#include "Grammar.h"


void scanrules(std::vector<std::pair<char, std::string>> &rules) {
  int n;
  std::cout << "Введите количество правил в вашей КС-грамматике\n";
  std::cin >> n;
  char noterminal;
  std::string rule;
  std::cout << "Далее введите через пробел нетерминал и правило\n";
  for (int i = 0; i < n; ++i) {
    std::cin >> noterminal >> rule;
    rules.push_back({noterminal, rule});
  }
}


int main()
{
  std::vector<std::pair<char, std::string>> rules;

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
