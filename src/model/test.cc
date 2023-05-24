#include <gtest/gtest.h>

#include "parser.h"

TEST(ConvertToPostfixTest, EmptyInputString) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "");
}

TEST(ConvertToPostfixTest, SingleNumber) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("123.45");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "123.450000 ");
}

TEST(ConvertToPostfixTest, SingleNumberWithTrailingZeroes) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("12.500");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "12.500000 ");
}

TEST(ConvertToPostfixTest, IncorrectExpressionMultipleDecimals) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("12.5.0");
  ASSERT_THROW(converter.translate(), std::runtime_error);
}

TEST(ConvertToPostfixTest, SimpleExpression) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("2+3*4");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "2.000000 3.000000 4.000000 * + ");
}

TEST(ConvertToPostfixTest, ComplexExpression) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("(3+4)*(2-1)/5");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "3.000000 4.000000 + 2.000000 1.000000 - * 5.000000 / ");
}

TEST(ConvertToPostfixTest, ComplexExpression2) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("(3+4)*(2-1)/5/");
  ASSERT_THROW(converter.translate(), std::runtime_error);
}

TEST(ConvertToPostfixTest, NestedBracketsDepth1) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("((1+2)*3)/4");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "1.000000 2.000000 + 3.000000 * 4.000000 / ");
}

TEST(ConvertToPostfixTest, NestedBracketsDepth2) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("(((1+2)*3)-4)/5");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "1.000000 2.000000 + 3.000000 * 4.000000 - 5.000000 / ");
}

TEST(ConvertToPostfixTest, NestedBracketsDepth3) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("(((1+2)*3)-4)/(5+6)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "1.000000 2.000000 + 3.000000 * 4.000000 - 5.000000 6.000000 + / ");
}

TEST(ConvertToPostfixTest, IncorrectExpressionMissingClosingBracket) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("(1+2*3");
  ASSERT_THROW(converter.translate(), std::runtime_error);
}

TEST(ConvertToPostfixTest, IncorrectExpressionExtraClosingBracket) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("(1+2)*3)");
  ASSERT_THROW(converter.translate(), std::runtime_error);
}

TEST(ConvertToPostfixTest, ComplexExpressionWithCos) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("c(x)+s(x)*t(x)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x c x s x t * + ");
}

TEST(ConvertToPostfixTest, ComplexExpressionWithAcos) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("a(x)-i(x)/v(x)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x a x i x v / - ");
}

TEST(ConvertToPostfixTest, ComplexExpressionWithLn) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("l(x)*o(x)/q(x)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x l x o * x q / ");
}

TEST(ConvertToPostfixTest, ComplexExpressionWithPow) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("(x^2)+(2^x)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x 2.000000 ^ 2.000000 x ^ + ");
}

TEST(ConvertToPostfixTest, ComplexExpressionWithMod) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("(xm3)+(3mx)");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "x 3.000000 m 3.000000 x m + ");
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
