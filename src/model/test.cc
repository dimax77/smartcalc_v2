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
  EXPECT_EQ(converter.postfix_string(), "123.45");
}

TEST(ConvertToPostfixTest, SimpleExpression) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("2+3*4");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "234*+");
}

TEST(ConvertToPostfixTest, ComplexExpression) {
  s21::ConvertToPostfix converter;
  converter.set_input_string("(3 + 4) * (2 - 1) / 5");
  converter.translate();
  EXPECT_EQ(converter.postfix_string(), "3 4 + 2 1 - * 5 /");
}

// Добавьте больше тестов, покрывающих различные сценарии и граничные случаи

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
