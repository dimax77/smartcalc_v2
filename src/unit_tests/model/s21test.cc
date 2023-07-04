#include <gtest/gtest.h>

#include "../../model/base_calculator.h"

namespace s21 {

class CalculatorWrapper {
 public:
  CalculatorWrapper() { calculator_ = new Calculator(); }

  ~CalculatorWrapper() { delete calculator_; }

  void set_input_string(const std::string& raw) {
    calculator_->set_input_string(raw);
  }

  void translate() { calculator_->translate(); }

  std::string get_postfix_string() {
    calculator_->translate();
    calculator_->postfix_string();
    return calculator_->get_postfix_string();
  }

  double evaluate(double x) { return calculator_->eval(x); }

 private:
  Calculator* calculator_;
};

class CalculatorWrapperTest : public ::testing::Test {
 protected:
  void SetUp() override { testCalc.set_input_string(""); }

  CalculatorWrapper testCalc;
};

TEST_F(CalculatorWrapperTest, EmptyInputString) {
  EXPECT_EQ(testCalc.get_postfix_string(), "");
}

TEST_F(CalculatorWrapperTest, SingleNumber) {
  testCalc.set_input_string("123.45");
  EXPECT_EQ(testCalc.get_postfix_string(), "123.450000 ");
}

TEST_F(CalculatorWrapperTest, SingleNumberWithTrailingZeroes) {
  testCalc.set_input_string("12.500");
  EXPECT_EQ(testCalc.get_postfix_string(), "12.500000 ");
}

TEST_F(CalculatorWrapperTest, IncorrectExpressionMultipleDecimals) {
  testCalc.set_input_string("12.5.0");
  ASSERT_THROW(testCalc.translate(), std::runtime_error);
}

TEST_F(CalculatorWrapperTest, SimpleExpression) {
  testCalc.set_input_string("2+3*4");
  EXPECT_EQ(testCalc.get_postfix_string(), "2.000000 3.000000 4.000000 * + ");
}

TEST_F(CalculatorWrapperTest, ComplexExpression) {
  testCalc.set_input_string("(3+4)*(2-1)/5");
  EXPECT_EQ(testCalc.get_postfix_string(),
            "3.000000 4.000000 + 2.000000 1.000000 - * 5.000000 / ");
}

TEST_F(CalculatorWrapperTest, ComplexExpression2) {
  testCalc.set_input_string("(3+4)*(2-1)/5/");
  ASSERT_THROW(testCalc.translate(), std::runtime_error);
}

TEST_F(CalculatorWrapperTest, NestedBracketsDepth1) {
  testCalc.set_input_string("((1+2)*3)/4");
  EXPECT_EQ(testCalc.get_postfix_string(),
            "1.000000 2.000000 + 3.000000 * 4.000000 / ");
}

TEST_F(CalculatorWrapperTest, NestedBracketsDepth2) {
  testCalc.set_input_string("(((1+2)*3)-4)/5");
  EXPECT_EQ(testCalc.get_postfix_string(),
            "1.000000 2.000000 + 3.000000 * 4.000000 - 5.000000 / ");
}

TEST_F(CalculatorWrapperTest, NestedBracketsDepth3) {
  testCalc.set_input_string("(((1+2)*3)-4)/(5+6)");
  EXPECT_EQ(testCalc.get_postfix_string(),
            "1.000000 2.000000 + 3.000000 * 4.000000 - 5.000000 6.000000 + / ");
}

TEST_F(CalculatorWrapperTest, IncorrectExpressionMissingClosingBracket) {
  testCalc.set_input_string("(1+2*3");
  ASSERT_THROW(testCalc.translate(), std::runtime_error);
}

TEST_F(CalculatorWrapperTest, IncorrectExpressionExtraClosingBracket) {
  testCalc.set_input_string("(1+2)*3)");
  ASSERT_THROW(testCalc.translate(), std::runtime_error);
}

TEST_F(CalculatorWrapperTest, ComplexExpressionWithCos) {
  testCalc.set_input_string("c(x)+s(x)*t(x)");
  EXPECT_EQ(testCalc.get_postfix_string(), "x c x s x t * + ");
}

TEST_F(CalculatorWrapperTest, ComplexExpressionWithAcos) {
  testCalc.set_input_string("a(x)-i(x)/v(x)");
  EXPECT_EQ(testCalc.get_postfix_string(), "x a x i x v / - ");
}

TEST_F(CalculatorWrapperTest, ComplexExpressionWithLn) {
  testCalc.set_input_string("l(x)*o(x)/q(x)");
  EXPECT_EQ(testCalc.get_postfix_string(), "x l x o * x q / ");
}

TEST_F(CalculatorWrapperTest, ComplexExpressionWithPow) {
  testCalc.set_input_string("(x^2)+(2^x)");
  EXPECT_EQ(testCalc.get_postfix_string(), "x 2.000000 ^ 2.000000 x ^ + ");
}

TEST_F(CalculatorWrapperTest, ComplexExpressionWithMod) {
  testCalc.set_input_string("(xm3)+(3mx)");
  EXPECT_EQ(testCalc.get_postfix_string(), "x 3.000000 m 3.000000 x m + ");
}

TEST_F(CalculatorWrapperTest, SimpleEval) {
  testCalc.set_input_string("0.2*0.1");
  EXPECT_EQ(testCalc.get_postfix_string(), "0.200000 0.100000 * ");
  EXPECT_TRUE((testCalc.evaluate(0.0) - 0.02) < 0.0000001);
}

}  // namespace s21

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
