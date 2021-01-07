#include <vector>
#include <string>
#include <iostream>

struct parametrs {
  int type = 1;
  int maxprefixonlyletter = 0;
  int maxprefixnoonlyletter = 0;
  bool isinf = false;
  parametrs () = default;
  parametrs(int type_, int maxprefixonlyletter_, int maxprefixnoonlyletter_, bool isinf_ = false) : 
  type(type_), maxprefixonlyletter(maxprefixonlyletter_), 
  maxprefixnoonlyletter(maxprefixnoonlyletter_), isinf(isinf_){};
  void fixedtype () {
    if (type == 2 && maxprefixonlyletter >= maxprefixnoonlyletter) {
      type = 1;
      maxprefixnoonlyletter = 0;
    }
  }
  void print() {
    printf("type = %d, prefixa = %d, prefixnoa = %d, isinf = %d\n", type, maxprefixonlyletter, maxprefixnoonlyletter, isinf);
  }
};

void doplus (std::vector<parametrs> &words) {
  int size = words.size() - 1;
  parametrs word;
  if (words[size].isinf || words[size - 1].isinf) {
    word.isinf = true;
  } else {
    if (words[size].type == words[size - 1].type) {
      word.type = words[size].type;
    } else  {
      word.type = 2;
    }
    word.maxprefixonlyletter = std::max(words[size -1].maxprefixonlyletter, words[size].maxprefixonlyletter);
    word.maxprefixnoonlyletter = std::max(words[size - 1].maxprefixnoonlyletter, words[size].maxprefixnoonlyletter);
    word.fixedtype();
  }
  words.pop_back();
  words.pop_back();
  words.push_back(word);
  //word.print();
}

void dostar (std::vector<parametrs> &words) {
  if (words.back().type != 0 && words.back().maxprefixonlyletter != 0) {
    words.back().type = 1;
    words.back().maxprefixonlyletter = 0;
    words.back().maxprefixnoonlyletter = 0;
    words.back().isinf = true;
  } else {
    words.back().type = 3;
    words.back().maxprefixonlyletter = 0;
    words.back().fixedtype();
  }
  //words.back().print();
}

void dopoint (std::vector<parametrs> &words) {
  int size = words.size() - 1;
  parametrs word;
  if (words[size - 1].isinf || (words[size].isinf && words[size - 1].type != 0)) {
    word.isinf = true;
  } else if (words[size - 1].type == 0) {
    word = words[size - 1];
  } else if (words[size].type == 0) {
    word.type = 0;
    word.maxprefixonlyletter = 0;
    word.maxprefixnoonlyletter =
        std::max(words[size].maxprefixnoonlyletter + words[size-1].maxprefixonlyletter, words[size-1].maxprefixnoonlyletter);
  } else if (words[size - 1].type == 1) {
    word.type = words[size].type;
    word.maxprefixonlyletter = words[size].maxprefixonlyletter + words[size - 1].maxprefixonlyletter;
    word.maxprefixnoonlyletter = words[size].maxprefixnoonlyletter + words[size - 1].maxprefixonlyletter;
  } else if (words[size].type == 1) {
    word.type = 2;
    word.maxprefixonlyletter = words[size].maxprefixonlyletter + words[size - 1].maxprefixonlyletter;
    word.maxprefixnoonlyletter = words[size - 1].maxprefixnoonlyletter;
    word.fixedtype();
  } else {
    word.type = 2;
    word.maxprefixonlyletter = words[size-1].maxprefixonlyletter + words[size].maxprefixonlyletter;
    word.maxprefixnoonlyletter = std::max(words[size - 1].maxprefixonlyletter + words[size].maxprefixnoonlyletter,
                                          words[size - 1].maxprefixnoonlyletter);
    word.fixedtype();
  }
  words.pop_back();
  words.pop_back();
  words.push_back(word);
//  word.print();
}


std::string MaxPrefixSymbol (std::string regular, char symbol) {
  if (symbol == '1') {
    return "INF";
  }
  if (symbol != 'a' && symbol != 'b' && symbol != 'c') {
    return "ERROR";
  }
  std::vector<parametrs> words;
  std::string expression;
  for (size_t i = 0; i < regular.length(); ++i) {
    if (regular[i] == 'a' || regular[i] == 'b' || regular[i] == 'c' || (regular[i]) == '1') {
      expression = regular[i];
      if (regular[i] == symbol) {
        words.push_back(parametrs(1, 1, 0));
      } else if (regular[i] == '1'){
        words.push_back(parametrs(1, 0, 0));
      } else {
        words.push_back(parametrs(0, 0, 0));
      }
    } else if (regular[i] == '+' && words.size() >= 2) {
      doplus(words);
    } else if (regular[i] == '.' && words.size() >= 2) {
      dopoint(words);
    } else if (regular[i] == '*' && words.size() >= 1) {
      dostar(words);
    } else {
      return "ERROR";
    }
  }
  if (words.size() == 1) {
    if (words.back().isinf) {
      return "INF";
    } 
    return std::to_string(std::max(words.back().maxprefixonlyletter, words.back().maxprefixnoonlyletter));
  } 
    return "ERROR";
}
