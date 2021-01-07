#include <vector>
#include <string>

void check(std::pair<int, int> &max, int &type);
void doplus (std::vector<std::pair<int, int>> &max, std::vector<int> &typesymbol);
void dostar (std::vector<std::pair<int, int>> &max, std::vector<int> &typesymbol);
void dopoint (std::vector<std::pair<int, int>> &max, std::vector<int> &typesymbol);

std::string MaxPrefixSymbol (std::string regular, char symbol);

