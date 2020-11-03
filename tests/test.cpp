#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../task18/MaxPrefixSymbol.h"


TEST(MaxPrefix, Example1) {
  EXPECT_EQ(MaxPrefixSymbol("ab+c.aba.*.bac.+.+*", 'a'), "2");
}

TEST(MaxPrefix, Example2) {
  EXPECT_EQ(MaxPrefixSymbol("acb..bab.c.*.ab.ba.+.+*a.", 'c'), "0");
}

TEST(MaxPrefix, ERROR) {
  EXPECT_EQ(MaxPrefixSymbol("a.", 'a'), "ERROR");
}

TEST(MaxPrefix, Star) {
  EXPECT_EQ(MaxPrefixSymbol("c*", 'c'), "INF");
}