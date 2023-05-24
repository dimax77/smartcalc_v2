// Function aliases:
// c: cos   a: acos   l: ln       m: mod
// s: sin   i: asin   o: log      q: sqrt
// t: tan   v: atan   u: unar '-' ^: pow

#ifndef _PARSER_H_
#define _PARSER_H_

#include <cstring>
#include <list>
#include <stack>
#include <string>

namespace s21 {

class ConvertToPostfix {
  std::string in_{};
  std::list<std::string> output_tokens_{};
  std::string acceptable_tokens_after_digit_ = "-+*/)m^";
  std::string acceptable_tokens_after_op_ = "x0123456789cstaivloq(";
  std::string postfix_string_{};
  std::stack<char> operators_{};

  inline bool is_func(char c) { return strchr("cstaivloq", c); }
  inline bool is_operator(char c) { return strchr("-+*/^m", c); }

  void move_operator_to_output_tokens() {
    output_tokens_.push_back(std::string(1, operators_.top()));
    operators_.pop();
  }

  int precedence(char op) {
    if (op == '+' || op == '-') {
      return 1;
    } else if (op == '*' || op == '/' || op == 'm') {
      return 2;
    } else if (op == '^') {
      return 3;
    } else if (is_func(op)) {
      return 4;
    } else {
      return 0;
    }
  }

  void processNumber(std::size_t& idx, std::size_t& temp_idx, bool& no_num,
                     std::size_t size) {
    double n = std::stod(in_.substr(idx), &temp_idx);
    output_tokens_.push_back(std::to_string(n));
    no_num = false;
    idx += (temp_idx - 1);
    if (idx + 1 < size) {
      if (acceptable_tokens_after_digit_.find(in_[idx + 1]) ==
          std::string::npos) {
        throw std::runtime_error("Malformed expression.");
      }
    }
  }

  void processFunction(char c, std::size_t idx, bool& no_num) {
    if (isdigit(in_[idx + 1]) || in_[idx + 1] == '(') {
      operators_.push(c);
      no_num = true;
    } else {
      throw std::runtime_error("Malformed expression.");
    }
  }

  void processOperator(char c, std::size_t idx, bool& no_num) {
    if (c == '-' && no_num) {
      operators_.push('u');
    } else {
      if (acceptable_tokens_after_op_.find(in_[idx + 1]) == std::string::npos) {
        throw std::runtime_error("Malformed expression.");
      } else {
        while (precedence(c) <= precedence(operators_.top())) {
          move_operator_to_output_tokens();
        }
        operators_.push(c);
        no_num = true;
      }
    }
  }

  void processOpenBrace(std::size_t idx) {
    if (idx > 0 && (isdigit(in_[idx - 1]) || in_[idx - 1] == '.')) {
      throw std::runtime_error("Malformed expression.");
    }
    operators_.push('(');
  }

  void processCloseBrace() {
    while (operators_.top() != '(') {
      move_operator_to_output_tokens();
      if (operators_.top() == 'S') {
        throw std::runtime_error("Unmatched braces.");
      }
    }
    operators_.pop();
  }

  void processVariable() { output_tokens_.push_back("x"); }

 public:
  void set_input_string(std::string raw) { in_ = raw; }

  void translate() {
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
  }

  std::string postfix_string() {
    while (!output_tokens_.empty()) {
      postfix_string_ += output_tokens_.front();
      postfix_string_ += " ";
      output_tokens_.pop_front();
    }
    return postfix_string_;
  }
};

}  // namespace s21

#endif  // _PARSER_H_
