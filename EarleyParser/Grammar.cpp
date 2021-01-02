#include "Grammar.h"
#include <algorithm>
#include <list>

bool Grammar::EarleyParser(std::string word) {

  std::list<Node> states;
  states.push_back(startstate);
  std::vector<Node> NodesToFree;

  while(!states.empty()){
    Node currentnode = states.front();
    states.pop_front();
    if(currentnode.state.size() > word.size() + 10) {
      continue;
    }
    if(word == currentnode.state){
      return true;
    }

    char nonterminal = '0';
    int indexnonterminal = 0;
    for(int i = 0, size = currentnode.state.size(); i < size;++i) {
      if(currentnode.state[i] >= 'A' && currentnode.state[i] <= 'Z') {
        nonterminal = currentnode.state[i];
        indexnonterminal = i;
        break;
      }
    }

    if(nonterminal != '0')
      for(int i = 0, size = rules[nonterminal].size(); i < size;++i) {
        if(rules[nonterminal][i][0] == '&') {
          NodesToFree.push_back(std::string(currentnode.state).erase(indexnonterminal, 1));
        }
        else {
          NodesToFree.push_back((std::string(currentnode.state).replace(indexnonterminal,
                                                                        1,
                                                                        rules[nonterminal][i])));
        }
        states.push_back(NodesToFree[NodesToFree.size()-1]);
      }
  }
  return false;
}