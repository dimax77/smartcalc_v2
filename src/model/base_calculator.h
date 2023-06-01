// Function aliases:
// c: cos   a: acos   l: ln       m: mod
// s: sin   i: asin   o: log      q: sqrt
// t: tan   v: atan   u: unar '-' ^: pow

#ifndef BASE_CALCULATOR_H_
#define BASE_CALCULATOR_H_

#include <cctype>
#include <cmath>
#include <cstring>
#include <iostream>
#include <list>
#include <stack>
#include <string>

#include "base_parser.h"

namespace s21 {

class Calculator : public BaseParser {
public:
  ~Calculator() override{};

  void set_input_string(const std::string &raw) override { in_ = raw; }

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

  std::string postfix_string() override {
    while (!output_tokens_.empty()) {
      postfix_string_ += output_tokens_.front();
      postfix_string_ += " ";
      output_tokens_.pop_front();
    }
    std::cout << postfix_string_ << std::endl;
    return postfix_string_;
  }

  double eval(double x) {
    double number{}, res{};
    int count = postfix_string_.length();
    for (int i = 0; i < count; ++i) {
      if (isdigit(postfix_string_[i])) {
        std::size_t temp_idx{};
        number = std::stod(postfix_string_.substr(i), &temp_idx);
        stack_double_.push(number);
        i += temp_idx - 1;
      } else if (postfix_string_[i] == 'x') {
        stack_double_.push(x);
      } else if (strchr("-+*/m^", postfix_string_[i]) != nullptr) {
        stack_double_.push(evalOperation(postfix_string_[i]));
      } else if (strchr("aciloqstuv", postfix_string_[i]) != nullptr) {
        stack_double_.push(evalFunction(postfix_string_[i]));
      }
    }
    res = stack_double_.top();
    stack_double_.pop();
    return res;
  }

private:
  std::stack<double> stack_double_;

  double evalOperation(char operation) {
    double value1{}, value2{}, res{};
    value2 = stack_double_.top();
    stack_double_.pop();
    value1 = stack_double_.top();
    stack_double_.pop();
    switch (operation) {
    case '+':
      res = value1 + value2;
      break;
    case '-':
      res = value1 - value2;
      break;
    case '*':
      res = value1 * value2;
      break;
    case '/':
      res = value1 / value2;
      break;
    case 'm':
      res = (int)value1 % (int)value2;
      break;
    case '^':
      res = pow(value1, value2);
      break;
    }
    return res;
  }

  double evalFunction(char operation) {
    double value{}, res{};
    value = stack_double_.top();
    stack_double_.pop();
    switch (operation) {
    case 'a':
      res = acos(value);
      break;
    case 'c':
      res = cos(value);
      break;
    case 's':
      res = sin(value);
      break;
    case 't':
      res = tan(value);
      break;
    case 'i':
      res = asin(value);
      break;
    case 'q':
      res = sqrt(value);
      break;
    case 'o':
      res = log10f(value);
      break;
    case 'l':
      res = log(value);
      break;
    case 'v':
      res = atan(value);
      break;
    case 'u':
      res = value * (-1);
      break;
    }
    return res;
  }
};

} // namespace s21

#endif // BASE_CALCULATOR_H_
