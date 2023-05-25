// Function aliases:
// c: cos   a: acos   l: ln       m: mod
// s: sin   i: asin   o: log      q: sqrt
// t: tan   v: atan   u: unar '-' ^: pow

#ifndef _CALCULATOR_H_
#define _CALCULATOR_H_

#include <cctype>
#include <cmath>
#include <cstring>
#include <list>
#include <stack>
#include <string>

#include "base_parser.h"

namespace s21 {

class Calculator : public BaseParser {
 public:
  ~Calculator() override{};

  void set_input_string(const std::string& raw) override { in_ = raw; }

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
    return postfix_string_;
  }

  double eval(double x) {
    double n1{}, n2{}, res{};
    int count = postfix_string_.length();
    for (int i = 0; i < count; ++i) {
      if (isdigit(postfix_string_[i])) {
        std::size_t temp_idx{};
        n1 = std::stod(postfix_string_.substr(i), &temp_idx);
        stack_double.push(n1);
        i += temp_idx - 1;
      } else if (postfix_string_[i] == 'x') {
        stack_double.push(x);
      } else if (strchr("-+*/mp", postfix_string_[i]) != NULL) {
        n2 = stack_double.top();
        stack_double.pop();
        n1 = stack_double.top();
        stack_double.pop();
        stack_double.push(evalOperation(postfix_string_[i], n1, n2));
      } else if (strchr("aciloqstuv", postfix_string_[i]) != NULL) {
        n1 = stack_double.top();
        stack_double.pop();
        stack_double.push(evalFunction(postfix_string_[i], n1));
      }
    }
    res = stack_double.top();
    stack_double.pop();
    return res;
  }

 private:
  std::stack<double> stack_double;

  double evalOperation(char operation, double value1, double value2) {
    double res{};
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

  double evalFunction(char operation, double value) {
    double res{};
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

}  // namespace s21

#endif  // _CALCULATOR_H_
