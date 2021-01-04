#include <vector>
#include <string>

class Grammar {
 private:
  std::vector<std::pair<char, std::string>> rules;
  std::string startstate;
  struct Situation {
    std::pair<char, std::string> rule;
    int position;
    int start;
    Situation(std::pair<char, std::string> rule_, int position_, int start_) : rule(rule_), position(position_), start(start_){};
    bool operator ==(const Situation& another) const {
      return rule == another.rule && position == another.position && start == another.start;
    }
  };
  std::vector<std::vector<Situation>> D;

  void Scan(int j, char letter);
  void Predict(int j);
  void Complete(int j);
 public:
  Grammar(std::vector<std::pair<char, std::string>> rules_, std::string startstate_) : rules(rules_), startstate(startstate_){
    rules.insert(rules.begin(), 1,{'&', startstate_});
  };
  bool EarleyParser(std::string word);
};
