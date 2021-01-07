#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "../task18/MaxPrefixSymbol.h"


TEST(MaxPrefix, Example1) {
  EXPECT_EQ(MaxPrefixSymbol("ab+c.aba.*.bac.+.+*", 'a'), "2");
}

TEST(MaxPrefix, Example2) {
  EXPECT_EQ(MaxPrefixSymbol("acb..bab.c.*.ab.ba.+.+*a.", 'c'), "0");
}

TEST(MaxPrefix, Example3) {
  EXPECT_EQ(MaxPrefixSymbol("ba.*cc.c..*ab+c+.bb..", 'b'), "3");
}

TEST(MaxPrefix, Example4) {
  EXPECT_EQ(MaxPrefixSymbol("ba.*cc.c..*ab+c+.", 'a'), "1");
}

TEST(MaxPrefix, Example5) {
  EXPECT_EQ(MaxPrefixSymbol("abc++abc++.a.*b.bb..bb..", 'b'), "5");
}

TEST(MaxPrefix, Example6) {
  EXPECT_EQ(MaxPrefixSymbol("abc++abc++.a*.b.bb..bb..", 'b'), "7");
}

TEST(PastMistake, Example7) {
  EXPECT_EQ(MaxPrefixSymbol("a1+a.", 'a'), "2");
}

TEST(PastMistake2, Example8) {
  EXPECT_EQ(MaxPrefixSymbol("ab.*a.", 'a'), "1");
}

TEST(MaxPrefix, Example9) {
  EXPECT_EQ(MaxPrefixSymbol("ab.1+a.a.", 'a'), "2");
}

TEST(MaxPrefix, Example10) {
  EXPECT_EQ(MaxPrefixSymbol("aaa.b.a+.", 'a'), "3");
}

TEST(MaxPrefix, Example11) {
  EXPECT_EQ(MaxPrefixSymbol("aaa..b.a+1ab.+.", 'a'), "3");
}

TEST(MaxPrefix, Example12) {
  EXPECT_EQ(MaxPrefixSymbol("1aa.b.+aaa..b.a+.", 'a'), "3");
}

TEST(MaxPrefix, Example13) {
EXPECT_EQ(MaxPrefixSymbol("aa.a.b.aa.+1aa.b.+.", 'a'), "4");
}

TEST(MaxPrefix, ERROR) {
  EXPECT_EQ(MaxPrefixSymbol("a.", 'a'), "ERROR");
}

TEST(MaxPrefix, Star) {
  EXPECT_EQ(MaxPrefixSymbol("c*", 'c'), "INF");
}

TEST(MaxPrefix, Infinum) {
  EXPECT_EQ(MaxPrefixSymbol("ba.*cc.c..*ab+c+*.", 'a'), "INF");
}

TEST(MaxPrefix, Infinum2) {
  EXPECT_EQ(MaxPrefixSymbol("ba.*cc.c..*ab+c+.", 'c'), "INF");
}

TEST(Inf_plus, Type) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.a*+", 'a'), "INF");
}

TEST(Type0_plus, Type0) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.aa.b.+", 'a'), "4");
}

TEST(Type0_plus, Type1) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.aa.+", 'a'), "4");
}

TEST(Type0_plus, Type2) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.aa.+aa.a.a.a.a.a.b.+", 'a'), "7");
}

TEST(Type1_plus, Type1) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.a.1+", 'a'), "5");
}

TEST(Type1_plus, Type2) {
EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.a+aa.+", 'a'), "4");
}

TEST(Type2_plus, Type2) {
 EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.a+aa.b.aa.a.a.a.a.++", 'a'), "6");
}

TEST(Type0, star) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.*", 'a'), "4");
}

TEST(Type1, star) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.*", 'a'), "INF");
}

TEST(Type2, star) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.ab.+*", 'a'), "INF");
}

TEST(Type2, star2) {
  EXPECT_EQ(MaxPrefixSymbol("aa.b.1+*", 'a'), "2");
}

TEST(Inf_point, Type) {
  EXPECT_EQ(MaxPrefixSymbol("a*ab.*.", 'a'), "INF");
}

TEST(Type1, Inf_point) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a*.", 'a'), "INF");
}

TEST(Type2, Inf_point) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.b.a+a*.", 'a'), "INF");
}

TEST(Type0_point, Type0) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.aa.b..", 'a'), "4");
}

TEST(Type0_point, Type01) {
EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.aa.a.a.a.a.b..", 'a'), "4");
}

TEST(Type0_point, Type1) {
EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.aa..", 'a'), "4");
}

TEST(Type0_point, Type2) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.aa.b.a+.", 'a'), "4");
}

TEST(Type0_point, Type20) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.b.aa.b.aa.a.a.a.a.+.", 'a'), "4");
}

TEST(Type1_point, Type0) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.ab..", 'a'), "5");
}

TEST(Type1_point, Type1) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.aa.a..", 'a'), "7");
}

TEST(Type1_point, Type2) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.a.aa.a.aa.a.a.a.a.b.+.", 'a'), "10");
}

TEST(Type2_point, Type0) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.aa.a.a.a.a.b.+aa.a.a.b..", 'a'), "7");
}

TEST(Type2_point, Type1) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.aa.a.a.a.a.b.+aa.a.a..", 'a'), "7");
}

TEST(Type2_point, Type2) {
  EXPECT_EQ(MaxPrefixSymbol("aa.a.aa.a.a.a.a.b.+aa.a.b.1+.", 'a'), "6");
}