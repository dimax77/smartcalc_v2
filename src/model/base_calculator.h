// Function aliases:
// c: cos   a: acos   l: ln       m: mod
// s: sin   i: asin   o: log      q: sqrt
// t: tan   v: atan   u: unar '-' ^: pow

#ifndef BASE_CALCULATOR_H_
#define BASE_CALCULATOR_H_

#include <cctype>
#include <cmath>
#include <list>
#include <stack>

#include "base_parser.h"

namespace s21 {

class Calculator : public BaseParser {
public:
  ~Calculator() override{};

  void set_input_string(const std::string &raw) override { in_ = raw; }

  std::string get_postfix_string() { return postfix_string_; }

  void translate() override {
    postfix_string_ = "";
    std::size_t size = in_.length(), idx{}, temp_idx{};
    bool no_num = true;
    operators_.push('S');
    while (idx < size) {
      char c = in_[idx];
      if (isdigit(c)) {
        processNumber(idx, temp_idx, no_num, size);
      } else if (is_func(c)) {
        processFunction(c, idx, no_num);
      } else if (is_operator(c)) {
        processOperator(c, idx, no_num);
      } else if (c == '(') {
        processOpenBrace(idx);
      } else if (c == ')') {
        processCloseBrace();
      } else if (c == 'x') {
        processVariable();
        no_num = false;
      } else {
        throw std::runtime_error("Unknown symbol");
      }
      idx += 1;
    }
    while (operators_.top() != 'S') {
      if (operators_.top() == '(')
        throw std::runtime_error("Unmatched braces.");
      move_operator_to_output_tokens();
    }
    operators_.pop();
    in_ = "";
  }

  void postfix_string() override {
    if (output_tokens_.empty())
      throw std::runtime_error("Malformed expression");
    while (!output_tokens_.empty()) {
      postfix_string_ += output_tokens_.front();
      postfix_string_ += " ";
      output_tokens_.pop_front();
    }
  }

  double eval(double x) {
    try {
      double value{}, result{};
      int count = postfix_string_.length();
      for (int i = 0; i < count; ++i) {
        if (isdigit(postfix_string_[i])) {
          std::size_t temp_idx{};
          value = std::stod(postfix_string_.substr(i), &temp_idx);
          stack_double_.push(value);
          i += temp_idx - 1;
        } else if (postfix_string_[i] == 'x') {
          stack_double_.push(x);
        } else if (strchr("-+*/m^", postfix_string_[i]) != nullptr) {
          stack_double_.push(evalOperation(postfix_string_[i]));
        } else if (strchr("aciloqstuv", postfix_string_[i]) != nullptr) {
          stack_double_.push(evalFunction(postfix_string_[i]));
        }
      }
      result = stack_double_.top();
      stack_double_.pop();
      return result;
    } catch (...) {
      throw std::runtime_error("Malformed expression.");
    }
  }

private:
  std::stack<double> stack_double_;

  double evalOperation(char operation) {
    double firstValue{}, secondValue{}, result{};
    secondValue = stack_double_.top();
    stack_double_.pop();
    if (stack_double_.empty())
      throw std::runtime_error("Missinig argument");
    firstValue = stack_double_.top();
    stack_double_.pop();
    switch (operation) {
    case '+':
      result = firstValue + secondValue;
      break;
    case '-':
      result = firstValue - secondValue;
      break;
    case '*':
      result = firstValue * secondValue;
      break;
    case '/':
      result = firstValue / secondValue;
      break;
    case 'm':
      result = (int)firstValue % (int)secondValue;
      break;
    case '^':
      result = pow(firstValue, secondValue);
      break;
    }
    return result;
  }

  double evalFunction(char operation) {
    if (stack_double_.empty())
      throw std::runtime_error("Malformed expression");
    double value{}, result{};
    value = stack_double_.top();
    stack_double_.pop();
    switch (operation) {
    case 'a':
      result = acos(value);
      break;
    case 'c':
      result = cos(value);
      break;
    case 's':
      result = sin(value);
      break;
    case 't':
      result = tan(value);
      break;
    case 'i':
      result = asin(value);
      break;
    case 'q':
      result = sqrt(value);
      break;
    case 'o':
      result = log10f(value);
      break;
    case 'l':
      result = log(value);
      break;
    case 'v':
      result = atan(value);
      break;
    case 'u':
      result = value * (-1);
      break;
    }
    return result;
  }
};

} // namespace s21

#endif // BASE_CALCULATOR_H_
