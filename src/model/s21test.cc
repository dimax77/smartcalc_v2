#include <iostream>

#include "gtest/gtest.h"
#include "model.h"

TEST(PostfixTest, BasicTest) {
  s21::model p;
  p.set_input_string("2+2");
  ASSERT_FALSE(p.to_postfix());
  p.clear();
  ASSERT_EQ(p.get_res_string(), "22+");
}

TEST(PostfixTest, ComplexTest) {
  s21::model p;
  p.set_input_string("(2+3)*4-5^2");
  ASSERT_FALSE(p.to_postfix());
  p.clear();
  ASSERT_EQ(p.get_res_string(), "23+4*52^-");
}

TEST(PostfixTest, ComplexTest2) {
  s21::model p;
  p.set_input_string("sin(2*x^2)-ln(---11)");
  ASSERT_FALSE(p.to_postfix());
  p.clear();
  ASSERT_EQ(p.get_res_string(), "2x2^*s11uuul-");
}

TEST(PostfixTest, Braces) {
  s21::model p;
  p.set_input_string("sin(2*x^2)-ln(---11)))");
  ASSERT_TRUE(p.to_postfix());
}

TEST(PostfixTest, Braces2) {
  s21::model p;
  p.set_input_string("sin(2*x^2)-ln(((((((---11)))");
  ASSERT_TRUE(p.to_postfix());
}

TEST(PostfixTest, ErrorTest) {
  s21::model p;
  p.set_input_string("1/0");
  ASSERT_FALSE(p.to_postfix());
  p.set_input_string("sin");
  ASSERT_FALSE(p.to_postfix());
}

TEST(PostfixTest, Eval) {
  s21::model p;
  p.set_input_string("2+2");
  ASSERT_FALSE(p.to_postfix());
  ASSERT_EQ(p.eval(0), 4.0);
}