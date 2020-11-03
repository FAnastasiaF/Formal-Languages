#include <vector>
#include <string>

void check(std::pair<int, int> &sum, int &type) {
  if (type == 6) {
    if (sum.first >= sum.second) {
      type = 3;
      sum.second = sum.first;
    }
  }
}

void doplus (std::vector<std::pair<int, int>> &sum, std::vector<int> &typesymbol) {
  std::pair<int, int> summ;
  int type;
  size_t size = sum.size() - 1;

  if (typesymbol[size] == 0 || typesymbol[size - 1] == 0) { // 0 + x, x + 0
    summ = {sum[size].first + sum[size - 1].first,
            sum[size].second + sum[size - 1].second};
    type = typesymbol[size] + typesymbol[size - 1];
  } else if (typesymbol[size] == 4 || typesymbol[size - 1] == 4) { // 4+x, x+4
    summ = {0, 0};
    type = 4;
  } else if ((typesymbol[size] == 1 && typesymbol[size - 1] == 2) // 1+2, 2+1
      || (typesymbol[size] == 2 && typesymbol[size - 1] == 1)){
    type = 5;
    summ = {0, sum[sum.size() - 1].first + sum[sum.size() - 1].first};
  } else if ((typesymbol[size] == 1 || typesymbol[size - 1] == 1)) { // 1+y, y+1, y = 1,3,4,5
    type = std::max(typesymbol[size], typesymbol[size]);
    summ = {sum[size].first + sum[size - 1].first,
            sum[size].second + sum[size - 1].second};
  } else if (typesymbol[size] == 2 && typesymbol[size - 1] == 2) { // 2+2
    type = 2;
    summ = {std::max(sum[size].first, sum[size - 1].first),
            std::max(sum[size].second, sum[size - 1].second)};
  } else if ((typesymbol[size] == 3 && typesymbol[size - 1] == 2) // 3+2, 2+3
      || (typesymbol[size] == 2 && typesymbol[size - 1] == 3)) {
    type = 6;
    if (typesymbol[size] == 2) {
      summ = {sum[size - 1].first, sum[size].first};
    } else {
      summ = {sum[size].first, sum[size - 1].first};
    }
  } else if (typesymbol[size - 1] == 2 || typesymbol[size] == 2) { // 2+5, 2+6
    type = std::max(typesymbol[size], typesymbol[size - 1]);
    if (typesymbol[size - 1] == 2) {
      summ = {sum[size].first, std::max(sum[size].second, sum[size - 1].second)};
    } else {
      summ = {sum[size - 1].first, std::max(sum[size].second, sum[size - 1].second)};
    }
  } else if(typesymbol[size - 1] == 3 && typesymbol[size] == 3) { // 3+3
    type = 3;
    if (sum[size].first >= sum[size - 1].first) {
      summ = sum[size];
    } else {
      summ = sum[size - 1];
    }
  } else if (typesymbol[size] == 3) { // 3+5, 3+6
    type = 6;
    summ = {std::max(sum[size].first, sum[size - 1].first), sum[size - 1].second};
  } else if (typesymbol[size - 1] == 3) { // 5+3, 6+3
    type = 6;
    summ = {std::max(sum[size - 1].first, sum[size].first), sum[size].second};
  } else if (typesymbol[size - 1] == 5 && typesymbol[size] == 5) { // 5+5
    type = 5;
    summ = {0, std::max(sum[size].second, sum[size - 1].second)};
  } else { // 6+6 5+5
    type = 6;
    summ = {std::max(sum[size].first, sum[size-1].first),
            std::max(sum[size].second, sum[size - 1].second)};
  }
  check(summ, type);
  typesymbol.pop_back();
  typesymbol.pop_back();
  typesymbol.push_back(type);
  sum.pop_back();
  sum.pop_back();
  sum.push_back(summ);
}


void dostar (std::vector<std::pair<int, int>> &sum, std::vector<int> &typesymbol) {
  int size = sum.size() - 1;
  if (typesymbol[size] == 3 || typesymbol[size] == 6) {
    typesymbol[size] = 4;
    sum[size] = {0, 0};
  } else if (typesymbol[size] == 0) {
    typesymbol[size] = 1;
    sum[size] = {0, 0};
  }
}

void dopoint (std::vector<std::pair<int, int>> &sum, std::vector<int> &typesymbol) {
  size_t size = sum.size() - 1;
  int type;
  std::pair<int, int> summ;
  if (typesymbol[size - 1] == 0) { // 0.x
    type = 0;
    summ = sum[size - 1];
  } else if (typesymbol[size] == 0) { //x.0
    if (typesymbol[size - 1] < 3 || typesymbol[size - 1] == 4) {
      type = typesymbol[size - 1];
      summ = sum[size - 1];
    } else if(typesymbol[size - 1] == 3) {
      type = 2;
      summ = sum[size - 1];
    } else if(typesymbol[size - 1] == 5) {
      type = 2;
      summ = {sum[size - 1].second, sum[size - 1].second};
    } else {
      type = 2;
      summ = {std::max(sum[size - 1].first, sum[size - 1].second),
              std::max(sum[size - 1].first, sum[size - 1].second)};
    }
  } else if (typesymbol[size] == 1) { // x.1
    type = typesymbol[size - 1];
    summ = sum[size - 1];
  } else if (typesymbol[size - 1] == 1) { // 1.x
    type = typesymbol[size];
    summ = sum[size];
  } else if (typesymbol[size - 1] == 4 && typesymbol[size - 1] == 2) { // 4.x, 2.x
    type = typesymbol[size - 1];
    summ = sum[size-1];
  } else if (typesymbol[size] == 2) { // x.2
    if (typesymbol[size - 1] == 3) {
      type = 2;
      summ = {sum[size].first + sum[size - 1].first, sum[size].second + sum[size - 1].second};
    } else if (typesymbol[size - 1] == 5) {
      type = 2;
      summ = {std::max(sum[size-1].second, sum[size].second), std::max(sum[size-1].second, sum[size].second)};
    } else {
      type = 2;
      summ = {std::max(sum[size-1].second, sum[size].first + sum[size - 1].first),
              std::max(sum[size-1].second, sum[size].first + sum[size - 1].first)};
    }
  } else if (typesymbol[size] == 3) { // x.3
    if (typesymbol[size - 1] == 3) {
      type = typesymbol[size - 1];
      summ = {sum[size].first + sum[size - 1].first, sum[size].first + sum[size - 1].first};
    } else if (typesymbol[size - 1] == 4) {
      type = 4;
      summ = {0,0};
    } else {
      type = 6;
      summ = {sum[size].first + sum[size - 1].first, sum[size - 1].second};
    }
  } else if (typesymbol[size - 1] == 3) { // 3.x
    type = 6;
    summ = {sum[size].first + sum[size - 1].first, sum[size - 1].second};
  } else if (typesymbol[size] == 4) { // x.4
    type = 4;
    summ = {0, 0};
  } else if (typesymbol[size] == 5) { // x.5
    if (typesymbol[size - 1] == 5) {
      type = typesymbol[size];
      summ = {0, std::max(sum[size].second, sum[size - 1].second)};
    } else {
      type = typesymbol[size - 1];
      summ = {sum[size - 1].first, std::max(sum[size].second, sum[size - 1].second)};
    }
  } else if (typesymbol[size - 1] == 5) { // 5.x
    type = 6;
    summ = {sum[size].first, std::max(sum[size].second, sum[size - 1].second)};
  } else {
    type = 6;
    summ = {sum[size].first + sum[size - 1].first,
            std::max(sum[size].second + sum[size - 1].first, sum[size - 1].second)};
  }
  check(summ, type);
  typesymbol.pop_back();
  typesymbol.pop_back();
  typesymbol.push_back(type);
  sum.pop_back();
  sum.pop_back();
  sum.push_back(summ);
}

std::string MaxPrefixSymbol (std::string regular, char symbol) {
  if (symbol == '1') {
    return "INF";
  }
  if (symbol != 'a' && symbol != 'b' && symbol != 'c') {
    return "ERROR";
  }
  std::vector<std::pair<int, int>> sum;
  std::vector<int> typesymbol;
  std::string expression;
  for (size_t i = 0; i < regular.length(); ++i) {
    if (regular[i] == 'a' || regular[i] == 'b' || regular[i] == 'c' || (regular[i]) == '1') {
      expression = regular[i];
      if (regular[i] == symbol) {
        sum.push_back({1, 1});
        typesymbol.push_back(3);
      } else if (regular[i] == '1'){
        sum.push_back({0, 0});
        typesymbol.push_back(1);
      } else {
        sum.push_back({0, 0});
        typesymbol.push_back(0);
      }
    } else if (regular[i] == '+' && sum.size() >= 2) {
      doplus(sum, typesymbol);
    } else if (regular[i] == '.' && sum.size() >= 2) {
      dopoint(sum, typesymbol);
    } else if (regular[i] == '*' && sum.size() >= 1) {
      dostar(sum, typesymbol);
    } else {
      return "ERROR";
    }
  }
  if (typesymbol.size() == 1) {
    if (typesymbol[0] == 4) {
      return "INF";
    } else {
      return std::to_string(std::max(sum[0].first, sum[0].second) );
    }
  } else {
    return "ERROR";
  }
}