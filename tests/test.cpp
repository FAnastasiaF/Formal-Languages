#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../EarleyParser/Grammar.h"


TEST(OneLetter, Example1) {
  std::vector<std::vector<std::string>> rules('Z',std::vector<std::string>());
  rules['S'].push_back("a");
  Grammar grammar(rules, "S");
  EXPECT_EQ(grammar.EarleyParser("a"), true);
}

TEST(WrongOneLetter, Example2) {
std::vector<std::vector<std::string>> rules('Z',std::vector<std::string>());
rules['S'].push_back("a");
Grammar grammar(rules, "S");
EXPECT_EQ(grammar.EarleyParser("b"), false);
}


TEST(Word, Example3) {
std::vector<std::vector<std::string>> rules('Z',std::vector<std::string>());
rules['S'].push_back("aAa");
rules['S'].push_back("bAb");
rules['A'].push_back("a");
Grammar grammar(rules, "S");
EXPECT_EQ(grammar.EarleyParser("bab"), true);
}

TEST(CircleWord, Example4) {
std::vector<std::vector<std::string>> rules('Z',std::vector<std::string>());
rules['S'].push_back("aAa");
rules['S'].push_back("bAb");
rules['A'].push_back("a");
rules['A'].push_back("SS");
Grammar grammar(rules, "S");
EXPECT_EQ(grammar.EarleyParser("baaababb"), true);
}

TEST(WrongCircleWord, Example5) {
std::vector<std::vector<std::string>> rules('Z',std::vector<std::string>());
rules['S'].push_back("aAa");
rules['S'].push_back("bAb");
rules['A'].push_back("a");
rules['A'].push_back("SS");
Grammar grammar(rules, "S");
EXPECT_EQ(grammar.EarleyParser("baaababbaa"), false);
}

TEST(EpsilonWord, Example6) {
std::vector<std::vector<std::string>> rules('Z',std::vector<std::string>());
rules['S'].push_back("aAa");
rules['S'].push_back("bAb");
rules['S'].push_back("&");
rules['A'].push_back("SS");
Grammar grammar(rules, "S");
EXPECT_EQ(grammar.EarleyParser("baaaaabbab"), true);
}

//S aAa
//S bAb
//A SS
//A a
//bab

