#include <gtest/gtest.h>

#include "calculator.h"
#include "iostream"

TEST(CalculatorTest, EmptyInputString) {
  s21::Calculator converter;
  converter.set_input_string("");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "");
}

TEST(CalculatorTest, SingleNumber) {
  s21::Calculator converter;
  converter.set_input_string("123.45");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "123.450000 ");
}

TEST(CalculatorTest, SingleNumberWithTrailingZeroes) {
  s21::Calculator converter;
  converter.set_input_string("12.500");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "12.500000 ");
}

TEST(CalculatorTest, IncorrectExpressionMultipleDecimals) {
  s21::Calculator converter;
  converter.set_input_string("12.5.0");
  ASSERT_THROW(converter.translate(), std::runtime_error);
}

TEST(CalculatorTest, SimpleExpression) {
  s21::Calculator converter;
  converter.set_input_string("2+3*4");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "2.000000 3.000000 4.000000 * + ");
}

TEST(CalculatorTest, ComplexExpression) {
  s21::Calculator converter;
  converter.set_input_string("(3+4)*(2-1)/5");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(),
            "3.000000 4.000000 + 2.000000 1.000000 - * 5.000000 / ");
}

TEST(CalculatorTest, ComplexExpression2) {
  s21::Calculator converter;
  converter.set_input_string("(3+4)*(2-1)/5/");
  ASSERT_THROW(converter.translate(), std::runtime_error);
}

TEST(CalculatorTest, NestedBracketsDepth1) {
  s21::Calculator converter;
  converter.set_input_string("((1+2)*3)/4");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(),
            "1.000000 2.000000 + 3.000000 * 4.000000 / ");
}

TEST(CalculatorTest, NestedBracketsDepth2) {
  s21::Calculator converter;
  converter.set_input_string("(((1+2)*3)-4)/5");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(),
            "1.000000 2.000000 + 3.000000 * 4.000000 - 5.000000 / ");
}

TEST(CalculatorTest, NestedBracketsDepth3) {
  s21::Calculator converter;
  converter.set_input_string("(((1+2)*3)-4)/(5+6)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(),
            "1.000000 2.000000 + 3.000000 * 4.000000 - 5.000000 6.000000 + / ");
}

TEST(CalculatorTest, IncorrectExpressionMissingClosingBracket) {
  s21::Calculator converter;
  converter.set_input_string("(1+2*3");
  ASSERT_THROW(converter.translate(), std::runtime_error);
}

TEST(CalculatorTest, IncorrectExpressionExtraClosingBracket) {
  s21::Calculator converter;
  converter.set_input_string("(1+2)*3)");
  ASSERT_THROW(converter.translate(), std::runtime_error);
}

TEST(CalculatorTest, ComplexExpressionWithCos) {
  s21::Calculator converter;
  converter.set_input_string("c(x)+s(x)*t(x)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x c x s x t * + ");
}

TEST(CalculatorTest, ComplexExpressionWithAcos) {
  s21::Calculator converter;
  converter.set_input_string("a(x)-i(x)/v(x)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x a x i x v / - ");
}

TEST(CalculatorTest, ComplexExpressionWithLn) {
  s21::Calculator converter;
  converter.set_input_string("l(x)*o(x)/q(x)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x l x o * x q / ");
}

TEST(CalculatorTest, ComplexExpressionWithPow) {
  s21::Calculator converter;
  converter.set_input_string("(x^2)+(2^x)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x 2.000000 ^ 2.000000 x ^ + ");
}

TEST(CalculatorTest, ComplexExpressionWithMod) {
  s21::Calculator converter;
  converter.set_input_string("(xm3)+(3mx)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x 3.000000 m 3.000000 x m + ");
}

TEST(CalculatorTest, SimpleEval) {
  s21::Calculator converter;
  converter.set_input_string("0.2*0.1");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "0.200000 0.100000 * ");
  EXPECT_TRUE((converter.eval(0.0) - 0.02) < 0.0000001);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
