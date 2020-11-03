#include <vector>
#include <string>

void check(std::pair<int, int> &max, int &type) {
  if (type == 6) {
    if (max.first >= max.second) {
      type = 3;
      max.second = max.first;
    }
  }
}

void doplus (std::vector<std::pair<int, int>> &max, std::vector<int> &typesymbol) {
  std::pair<int, int> maxm;
  int type;
  size_t size = max.size() - 1;

  if (typesymbol[size] == 0 || typesymbol[size - 1] == 0) { // 0 + x, x + 0
    maxm = {max[size].first + max[size - 1].first,
            max[size].second + max[size - 1].second};
    type = typesymbol[size] + typesymbol[size - 1];
  } else if (typesymbol[size] == 4 || typesymbol[size - 1] == 4) { // 4+x, x+4
    maxm = {0, 0};
    type = 4;
  } else if ((typesymbol[size] == 1 && typesymbol[size - 1] == 2) // 1+2, 2+1
      || (typesymbol[size] == 2 && typesymbol[size - 1] == 1)){
    type = 5;
    maxm = {0, max[max.size() - 1].first + max[max.size() - 1].first};
  } else if ((typesymbol[size] == 1 || typesymbol[size - 1] == 1)) { // 1+y, y+1, y = 1,3,4,5
    type = std::max(typesymbol[size], typesymbol[size]);
    maxm = {max[size].first + max[size - 1].first,
            max[size].second + max[size - 1].second};
  } else if (typesymbol[size] == 2 && typesymbol[size - 1] == 2) { // 2+2
    type = 2;
    maxm = {std::max(max[size].first, max[size - 1].first),
            std::max(max[size].second, max[size - 1].second)};
  } else if ((typesymbol[size] == 3 && typesymbol[size - 1] == 2) // 3+2, 2+3
      || (typesymbol[size] == 2 && typesymbol[size - 1] == 3)) {
    type = 6;
    if (typesymbol[size] == 2) {
      maxm = {max[size - 1].first, max[size].first};
    } else {
      maxm = {max[size].first, max[size - 1].first};
    }
  } else if (typesymbol[size - 1] == 2 || typesymbol[size] == 2) { // 2+5, 2+6
    type = std::max(typesymbol[size], typesymbol[size - 1]);
    if (typesymbol[size - 1] == 2) {
      maxm = {max[size].first, std::max(max[size].second, max[size - 1].second)};
    } else {
      maxm = {max[size - 1].first, std::max(max[size].second, max[size - 1].second)};
    }
  } else if(typesymbol[size - 1] == 3 && typesymbol[size] == 3) { // 3+3
    type = 3;
    if (max[size].first >= max[size - 1].first) {
      maxm = max[size];
    } else {
      maxm = max[size - 1];
    }
  } else if (typesymbol[size] == 3) { // 3+5, 3+6
    type = 6;
    maxm = {std::max(max[size].first, max[size - 1].first), max[size - 1].second};
  } else if (typesymbol[size - 1] == 3) { // 5+3, 6+3
    type = 6;
    maxm = {std::max(max[size - 1].first, max[size].first), max[size].second};
  } else if (typesymbol[size - 1] == 5 && typesymbol[size] == 5) { // 5+5
    type = 5;
    maxm = {0, std::max(max[size].second, max[size - 1].second)};
  } else { // 6+6 5+5
    type = 6;
    maxm = {std::max(max[size].first, max[size-1].first),
            std::max(max[size].second, max[size - 1].second)};
  }
  check(maxm, type);
  typesymbol.pop_back();
  typesymbol.pop_back();
  typesymbol.push_back(type);
  max.pop_back();
  max.pop_back();
  max.push_back(maxm);
}


void dostar (std::vector<std::pair<int, int>> &max, std::vector<int> &typesymbol) {
  int size = max.size() - 1;
  if (typesymbol[size] == 3 || typesymbol[size] == 6) {
    typesymbol[size] = 4;
    max[size] = {0, 0};
  } else if (typesymbol[size] == 0) {
    typesymbol[size] = 1;
    max[size] = {0, 0};
  }
}

void dopoint (std::vector<std::pair<int, int>> &max, std::vector<int> &typesymbol) {
  size_t size = max.size() - 1;
  int type;
  std::pair<int, int> maxm;
  if (typesymbol[size - 1] == 0) { // 0.x
    type = 0;
    maxm = max[size - 1];
  } else if (typesymbol[size] == 0) { //x.0
    if (typesymbol[size - 1] < 3 || typesymbol[size - 1] == 4) {
      type = typesymbol[size - 1];
      maxm = max[size - 1];
    } else if(typesymbol[size - 1] == 3) {
      type = 2;
      maxm = max[size - 1];
    } else if(typesymbol[size - 1] == 5) {
      type = 2;
      maxm = {max[size - 1].second, max[size - 1].second};
    } else {
      type = 2;
      maxm = {std::max(max[size - 1].first, max[size - 1].second),
              std::max(max[size - 1].first, max[size - 1].second)};
    }
  } else if (typesymbol[size] == 1) { // x.1
    type = typesymbol[size - 1];
    maxm = max[size - 1];
  } else if (typesymbol[size - 1] == 1) { // 1.x
    type = typesymbol[size];
    maxm = max[size];
  } else if (typesymbol[size - 1] == 4 && typesymbol[size - 1] == 2) { // 4.x, 2.x
    type = typesymbol[size - 1];
    maxm = max[size-1];
  } else if (typesymbol[size] == 2) { // x.2
    if (typesymbol[size - 1] == 3) {
      type = 2;
      maxm = {max[size].first + max[size - 1].first, max[size].second + max[size - 1].second};
    } else if (typesymbol[size - 1] == 5) {
      type = 2;
      maxm = {std::max(max[size-1].second, max[size].second), std::max(max[size-1].second, max[size].second)};
    } else {
      type = 2;
      maxm = {std::max(max[size-1].second, max[size].first + max[size - 1].first),
              std::max(max[size-1].second, max[size].first + max[size - 1].first)};
    }
  } else if (typesymbol[size] == 3) { // x.3
    if (typesymbol[size - 1] == 3) {
      type = typesymbol[size - 1];
      maxm = {max[size].first + max[size - 1].first, max[size].first + max[size - 1].first};
    } else if (typesymbol[size - 1] == 4) {
      type = 4;
      maxm = {0,0};
    } else {
      type = 6;
      maxm = {max[size].first + max[size - 1].first, max[size - 1].second};
    }
  } else if (typesymbol[size - 1] == 3) { // 3.x
    type = 6;
    maxm = {max[size].first + max[size - 1].first, max[size - 1].second};
  } else if (typesymbol[size] == 4) { // x.4
    type = 4;
    maxm = {0, 0};
  } else if (typesymbol[size] == 5) { // x.5
    if (typesymbol[size - 1] == 5) {
      type = typesymbol[size];
      maxm = {0, std::max(max[size].second, max[size - 1].second)};
    } else {
      type = typesymbol[size - 1];
      maxm = {max[size - 1].first, std::max(max[size].second, max[size - 1].second)};
    }
  } else if (typesymbol[size - 1] == 5) { // 5.x
    type = 6;
    maxm = {max[size].first, std::max(max[size].second, max[size - 1].second)};
  } else {
    type = 6;
    maxm = {max[size].first + max[size - 1].first,
            std::max(max[size].second + max[size - 1].first, max[size - 1].second)};
  }
  check(maxm, type);
  typesymbol.pop_back();
  typesymbol.pop_back();
  typesymbol.push_back(type);
  max.pop_back();
  max.pop_back();
  max.push_back(maxm);
}

std::string MaxPrefixSymbol (std::string regular, char symbol) {
  if (symbol == '1') {
    return "INF";
  }
  if (symbol != 'a' && symbol != 'b' && symbol != 'c') {
    return "ERROR";
  }
  std::vector<std::pair<int, int>> max;
  std::vector<int> typesymbol;
  std::string expression;
  for (size_t i = 0; i < regular.length(); ++i) {
    if (regular[i] == 'a' || regular[i] == 'b' || regular[i] == 'c' || (regular[i]) == '1') {
      expression = regular[i];
      if (regular[i] == symbol) {
        max.push_back({1, 1});
        typesymbol.push_back(3);
      } else if (regular[i] == '1'){
        max.push_back({0, 0});
        typesymbol.push_back(1);
      } else {
        max.push_back({0, 0});
        typesymbol.push_back(0);
      }
    } else if (regular[i] == '+' && max.size() >= 2) {
      doplus(max, typesymbol);
    } else if (regular[i] == '.' && max.size() >= 2) {
      dopoint(max, typesymbol);
    } else if (regular[i] == '*' && max.size() >= 1) {
      dostar(max, typesymbol);
    } else {
      return "ERROR";
    }
  }
  if (typesymbol.size() == 1) {
    if (typesymbol[0] == 4) {
      return "INF";
    } else {
      return std::to_string(std::max(max[0].first, max[0].second) );
    }
  } else {
    return "ERROR";
  }
}