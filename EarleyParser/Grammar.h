#include <vector>
#include <string>


class Grammar {
 private:
  std::vector<std::vector<std::string>> rules;
  std::string startstate;
  struct Node {
    Node(std::string state_) : state(state_){}
    std::string state;
  };
 public:
  Grammar(std::vector<std::vector<std::string>> rules_, std::string startstate_) : rules(rules_), startstate(startstate_){};
  bool EarleyParser(std::string word);
};
