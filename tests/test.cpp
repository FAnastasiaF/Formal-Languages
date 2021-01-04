#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../EarleyParser/Grammar.h"


TEST(OneLetter, Example1) {
  std::vector<std::pair<char, std::string>> rules;
  rules.push_back({'S', "a"});
  Grammar grammar(rules, "S");
  EXPECT_EQ(grammar.EarleyParser("a"), true);
}

TEST(WrongOneLetter, Example2) {
  std::vector<std::pair<char, std::string>> rules;
  rules.push_back({'S', "a"});
  Grammar grammar(rules, "S");
  EXPECT_EQ(grammar.EarleyParser("b"), false);
}

TEST(Word, Example3) {
  std::vector<std::pair<char, std::string>> rules;
  rules.push_back({'S', "aAa"});
  rules.push_back({'S', "bAb"});
  rules.push_back({'A', "a"});
  Grammar grammar(rules, "S");
  EXPECT_EQ(grammar.EarleyParser("bab"), true);
}

TEST(CircleWord, Example4) {
  std::vector<std::pair<char, std::string>> rules;
  rules.push_back({'S', "aAa"});
  rules.push_back({'S', "bAb"});
  rules.push_back({'A', "a"});
  rules.push_back({'A', "SS"});
  Grammar grammar(rules, "S");
  EXPECT_EQ(grammar.EarleyParser("baaababb"), true);
}

TEST(WrongCircleWord, Example4) {
std::vector<std::pair<char, std::string>> rules;
rules.push_back({'S', "aAa"});
rules.push_back({'S', "bAb"});
rules.push_back({'A', "a"});
rules.push_back({'A', "SS"});
Grammar grammar(rules, "S");
EXPECT_EQ(grammar.EarleyParser("baaababbaa"), false);
}

TEST(EpsilonWord, Example6) {
  std::vector<std::pair<char, std::string>> rules;
  rules.push_back({'S', "aAa"});
  rules.push_back({'S', "bAb"});
  rules.push_back({'S', ""});
  rules.push_back({'A', "SS"});
  Grammar grammar(rules, "S");
  EXPECT_EQ(grammar.EarleyParser("abbaaa"), true);
}

TEST(CBS, Example7) {
  std::vector<std::pair<char, std::string>> rules;
  rules.push_back({'S', "(S)S"});
  rules.push_back({'S', ""});
  Grammar grammar(rules, "S");
  EXPECT_EQ(grammar.EarleyParser("()()((((()())))())"), true);
}

TEST(AnotherTerminal, Example8) {
  std::vector<std::pair<char, std::string>> rules;
  rules.push_back({'A', "aA"});
  rules.push_back({'A', "bA"});
  rules.push_back({'A', ""});
  Grammar grammar(rules, "A");
  EXPECT_EQ(grammar.EarleyParser("aaabb"), true);
}

TEST(AnotherTerminalEpsilon, Example9) {
  std::vector<std::pair<char, std::string>> rules;
  rules.push_back({'A', "aA"});
  rules.push_back({'A', "bA"});
  rules.push_back({'A', ""});
  Grammar grammar(rules, "A");
  EXPECT_EQ(grammar.EarleyParser(""), true);
}

TEST(NoUseTerminal, Example10) {
  std::vector<std::pair<char, std::string>> rules;
  rules.push_back({'A', "aA"});
  rules.push_back({'S', "Ab"});
  rules.push_back({'A', ""});
  Grammar grammar(rules, "A");
  EXPECT_EQ(grammar.EarleyParser("aaabb"), false);
}


