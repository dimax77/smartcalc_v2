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

  virtual void Translate() = 0;

  virtual void PostfixString() = 0;

 protected:
  std::string input_string_{};
  std::string acceptable_tokens_after_digit_ = "-+*/)m^";
  std::string acceptable_tokens_after_op_ = "x0123456789cstaivloq(";
  std::string postfix_string_{};
  std::stack<char> operators_{};
  std::list<std::string> output_tokens_{};

  bool IsOperator(char c) { return strchr("-+*/^m", c) != nullptr; }

  bool IsFunc(char c) { return strchr("cstaivloqu", c) != nullptr; }

  int Precedence(char op) {
    if (op == '+' || op == '-') {
      return 1;
    } else if (op == '*' || op == '/' || op == 'm') {
      return 2;
    } else if (op == '^') {
      return 3;
    } else if (IsFunc(op)) {
      return 4;
    } else {
      return 0;
    }
  }

  void MoveOperatorToOutputTokens() {
    if (operators_.empty()) throw std::runtime_error("Malformed expression.");
    output_tokens_.push_back(std::string(1, operators_.top()));
    operators_.pop();
  }

  void ProcessNumber(std::size_t &idx, std::size_t &temp_idx, bool &no_num,
                     std::size_t size) {
    double n = std::stod(input_string_.substr(idx), &temp_idx);
    output_tokens_.push_back(std::to_string(n));
    no_num = false;
    idx += (temp_idx - 1);
    if (idx + 1 < size) {
      if (acceptable_tokens_after_digit_.find(input_string_[idx + 1]) ==
          std::string::npos) {
        throw std::runtime_error("Malformed expression.");
      }
    }
  }

  void ProcessFunction(char c, std::size_t idx, bool &no_num) {
    if (isdigit(input_string_[idx + 1]) || input_string_[idx + 1] == '(') {
      operators_.push(c);
      no_num = true;
    } else {
      throw std::runtime_error("Malformed expression.");
    }
  }

  void ProcessOperator(char c, std::size_t idx, bool &no_num) {
    if (c == '-' && no_num) {
      operators_.push('u');
    } else if (c == '+' && no_num) {
    } else {
      if (acceptable_tokens_after_op_.find(input_string_[idx + 1]) == std::string::npos) {
        throw std::runtime_error("Malformed expression.");
      } else {
        while (Precedence(c) <= Precedence(operators_.top())) {
          MoveOperatorToOutputTokens();
        }
        operators_.push(c);
        no_num = true;
      }
    }
  }

  void ProcessOpenBrace(std::size_t idx) {
    if (idx > 0 && (isdigit(input_string_[idx - 1]) || input_string_[idx - 1] == '.')) {
      throw std::runtime_error("Malformed expression.");
    }
    operators_.push('(');
  }

  void ProcessCloseBrace() {
    while (operators_.top() != '(') {
      MoveOperatorToOutputTokens();
      if (operators_.top() == 'S') {
        throw std::runtime_error("Unmatched braces.");
      }
    }
    operators_.pop();
  }

  void ProcessVariable() { output_tokens_.push_back("x"); }
};

}  // namespace s21

#endif  // BASE_PARSER_H_
