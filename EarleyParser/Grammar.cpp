#include "Grammar.h"
#include <algorithm>
#include <iostream>


bool Grammar::EarleyParser(std::string word) {
  D.clear();
  D.resize(word.size() + 1);
  D[0].push_back(Situation(rules[0], 0, 0));

  for (int j = 0; j <= word.size(); ++j) {
    if (j > 0) {
      Scan(j, word[j - 1]);
    }
    for (int i = -1; i != D[j].size();) {
      i = D[j].size();
      Predict(j);
      Complete(j);
    }
  }
  //D.shrink_to_fit();
  for (auto i : D[D.size() - 1]) {
    if(i == Situation(rules[0], 1, 0)) {
      return true;
    }
  }
  return false;
}


void Grammar::Scan(int j, char letter) {
  for (auto i : D[j - 1]) {
    if (i.rule.second[i.position] == letter) {
      D[j].push_back(Situation(i.rule, i.position + 1, i.start));
    }
  }
}

void Grammar::Predict(int j) {
  std::vector<Situation> tmpsituation;
  for (auto i : D[j]) {
    for (auto r : rules) {
      if (i.rule.second.size() > i.position && r.first == i.rule.second[i.position]) {
        tmpsituation.push_back(Situation(r, 0, j));
      }
    }
  }
  for (const auto& i : tmpsituation) {
    bool same_situation = false;
    for (const auto& k : D[j]) {
      if (k == i) {
        same_situation = true;
      }
    }

    if (not same_situation) {
      D[j].push_back(i);
    }
  }
}

void Grammar::Complete(int j) {
  std::vector<Situation> tmpsituation;
  for (auto i : D[j]) {
    if (i.position == i.rule.second.size()) {
      for (auto k : D[i.start]) {
        if (k.rule.second.size() > k.position && k.rule.second[k.position] == i.rule.first) {
          tmpsituation.push_back(Situation(k.rule, k.position + 1, k.start));
        }
      }
    }
  }

  for (const auto& i : tmpsituation) {
    bool same_situation = false;
    for (const auto& k : D[j]) {
      if (k == i) {
        same_situation = true;
      }
    }

    if (not same_situation) {
      D[j].push_back(i);
    }
  }
}