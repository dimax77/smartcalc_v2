#ifndef BASE_PARSER_H_
#define BASE_PARSER_H_

#include <cstring>
#include <list>
#include <stack>
#include <stdexcept>
#include <string>

namespace s21 {

class BaseParser {
public:
  virtual ~BaseParser(){};

  virtual void set_input_string(const std::string &raw) = 0;

  virtual void translate() = 0;

  virtual std::string postfix_string() = 0;

protected:
  std::string in_{};
  std::string acceptable_tokens_after_digit_ = "-+*/)m^";
  std::string acceptable_tokens_after_op_ = "x0123456789cstaivloq(";
  std::string postfix_string_{};
  std::stack<char> operators_{};
  std::list<std::string> output_tokens_{};

  bool is_operator(char c) { return strchr("-+*/^m", c) != nullptr; }

  bool is_func(char c) { return strchr("cstaivloq", c) != nullptr; }

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

  void move_operator_to_output_tokens() {
    output_tokens_.push_back(std::string(1, operators_.top()));
    operators_.pop();
  }

  void processNumber(std::size_t &idx, std::size_t &temp_idx, bool &no_num,
                     std::size_t size) {
    double n = std::stod(in_.substr(idx), &temp_idx);
    output_tokens_.push_back(std::to_string(n));
    no_num = false;
    idx += (temp_idx - 1);
    if (idx + 1 < size) {
      if (acceptable_tokens_after_digit_.find(in_[idx + 1]) ==
          std::string::npos) {
        throw std::runtime_error("Malformed expression in number.");
      }
    }
  }

  void processFunction(char c, std::size_t idx, bool &no_num) {
    if (isdigit(in_[idx + 1]) || in_[idx + 1] == '(') {
      operators_.push(c);
      no_num = true;
    } else {
      throw std::runtime_error("Malformed expression in function.");
    }
  }

  void processOperator(char c, std::size_t idx, bool &no_num) {
    if (c == '-' && no_num) {
      operators_.push('u');
    } else {
      if (acceptable_tokens_after_op_.find(in_[idx + 1]) == std::string::npos) {
        throw std::runtime_error("Malformed expression in operator.");
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
      throw std::runtime_error("Malformed expression in open brace.");
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
};

} // namespace s21

#endif // BASE_PARSER_H_
