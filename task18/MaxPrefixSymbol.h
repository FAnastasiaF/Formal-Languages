#include <vector>
#include <string>

void check(std::pair<int, int> &sum, int &type);
void doplus (std::vector<std::pair<int, int>> &sum, std::vector<int> &typesymbol);
void dostar (std::vector<std::pair<int, int>> &sum, std::vector<int> &typesymbol);
void dopoint (std::vector<std::pair<int, int>> &sum, std::vector<int> &typesymbol);

std::string MaxPrefixSymbol (std::string regular, char symbol);

